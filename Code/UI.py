import plotly.graph_objects as go
from __future__ import print_function
from ipywidgets import interact, interactive, fixed, interact_manual
import ipywidgets as widgets
from ipywidgets import Button, Layout

import numpy as np
import pandas as pd
import xlrd
from sklearn import preprocessing
import matplotlib.pyplot as plt
# 单独窗口显示动态图
%matplotlib auto


# 把邻接矩阵excel里面的数据存储到邻接矩阵里面
def excel_to_matrix(path):
    table = xlrd.open_workbook(path).sheets()[0]#获取第一个sheet表
    row = table.nrows  # 行数
    col = table.ncols  # 列数
    datamatrix = np.zeros((row, col))#生成一个nrows行ncols列，且元素均为0的初始矩阵
    for x in range(col):
        cols = np.matrix(table.col_values(x))  # 把list转换为矩阵进行矩阵操作
        datamatrix[:, x] = cols # 按列把数据存进矩阵中
    #数据归一化   
    min_max_scaler = preprocessing.MinMaxScaler()
    datamatrix  = min_max_scaler.fit_transform(datamatrix)
    return datamatrix

datafile = 'input.xlsx'
A = excel_to_matrix(datafile) # 邻接矩阵 A Adjacency_matrix


# 使用最简单的平均值算法通过A计算Q
def A_to_Q_matrix(A):
    row = A.shape[0]  # 行数
    col = A.shape[1]  # 列数
    Q = np.zeros((row, col))#生成一个nrows行ncols列，且元素均为0的初始矩阵

    #每一横行的元素分别除以本行所有元素的和
    for y in range(row):
        for x in range(col):
            Q[y,:] = A[y,:]/sum(A[y,:])
    return Q
Q = A_to_Q_matrix(A)

# 固定次数迭代函数
def Iteration_Fixed_Time (P,Count):
    P_trans = np.transpose(P)
    P_Length = len(P)
    # 使用Q和初始值进行迭代P(n+1)=P(n)*(Q)
    P_All = np.zeros((Count+1, P_Length))
    P_All[0,:] = np.transpose(P_trans)
    for i in range(Count):
        P_trans = Q.dot(P_trans)
        P_All[i+1,:] = np.transpose(P_trans)
    return P_All


def f(a,b,c,d):
    fig = go.Figure(data=go.Bar(y=[a, b, c, d]))
    fig.show()
    global Input
    Input = [0,0,0,0]
    Input[0]=a
    Input[1]=b
    Input[2]=c
    Input[3]=d
    for i in range(0,4):
        print(Input[i])
    # 在这插入XBee代码
    XbeeTx(Input)
    
def XbeeTx(Input):
    for i in range(0,4):
        print(Input[i])    

# Error: 关不上输出窗口，而且输出乱七八糟的，待调试。
def XbeeTxRun(RUNorNOT):
    name_list = ['1','2','3','4']
    color=['r','g','b','#FFE4C4']
    num_list = [0,0,0,0]
    # 读入初始值P
    P= [0,0,0,0]
    for i in range(0,4):
        P[i] = float(Input[i])
        print(Input[i])
    
    P_Length = len(P)
    Times = 3
    P_All=Iteration_Fixed_Time(P,Times)
    # 画图 每个节点的变量随着迭代次数的曲线图
    Y = np.transpose(P_All)
    #     for i in range(P_Length):
    #         plt.plot(x,Y[i],'+-')
    #     plt.show()         
   
    #     fig = plt.figure()
    #     ax = fig.add_subplot(1, 1, 1)
    #     ax.axis([x_min, x_max, y_min, y_max])    # 固定 X 轴和 Y 轴坐标范围
    plt.ion()                                # 连续动态图

    for i in range(Times):                    # 以 20步长更新，绘制动态图
        num_list = [Y[0,i],Y[1,i],Y[2,i],Y[3,i]]
        plt.bar(range(len(num_list)), num_list,color=color,tick_label=name_list)
        plt.pause(1)                       # 每次绘制后暂停 0.1 秒

    
I = [0,0,0,0]

for i in range(0,4):
    I[i] = widgets.FloatSlider(min=0, max=1e3, step=1)

ui = widgets.VBox([I[0], I[1], I[2], I[3] ])
# ui = widgets.HBox([I[0], I[1], I[2], I[3] ])

out = widgets.interactive_output(f, {'a': I[0], 'b': I[1], 'c': I[2], 'd': I[3] } )

b1 = Button(description='Run')
b1.style.button_color = 'lightgreen'
b1.on_click (XbeeTxRun)


display(ui, out, b1)