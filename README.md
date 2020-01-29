[![Build Status](https://travis-ci.org/xueruini/thuthesis.svg?branch=master)](https://travis-ci.org/xueruini/thuthesis)
[![Join the chat at https://gitter.im/thuthesis/Lobby](https://badges.gitter.im/thuthesis/Lobby.svg)](https://gitter.im/thuthesis/Lobby)
[![Github downloads](https://img.shields.io/github/downloads/xueruini/thuthesis/total.svg)](https://github.com/xueruini/thuthesis/releases)
[![GitHub release](https://img.shields.io/github/release/xueruini/thuthesis/all.svg)](https://github.com/xueruini/thuthesis/releases/latest)
[![GitHub commits](https://img.shields.io/github/commits-since/xueruini/thuthesis/latest.svg)](https://github.com/xueruini/thuthesis/commits/master)

## Note
首先需要安装Tex

Windows 用户在文件夹空白处按`Shift+鼠标右键`，点击“在此处打开命令行窗口”）：

    xetex thuthesis.ins

即可得到 `thuthesis.cls` 等模板文件。

之后在根目录运行：

```
latexmk -xelatex --shell-escape main.tex
```

即可编译得到PDF文件。



## Tools

PDF转Excel：

[**FREE ONLINE OCR SERVICE**](https://www.onlineocr.net/)

Latex表格生成

**[*LaTeX* Tables Generator](https://www.tablesgenerator.com/)**

截图公式转Latex

**[Sinp](https://mathpix.com/)**



## What's ThuThesis?
ThuThesis is an abbreviation of <b>T</b>sing<b>h</b>ua <b>U</b>niversity <b>Thesis</b> LaTeX Template.

This package establishes a simple and easy-to-use LaTeX template for Tsinghua dissertations, including general undergraduate research papers, masters theses, doctoral theses, doctoral dissertations, and post-doc reports. Additional support for other formats (what else is there?) will be added continuously. An English translation of this README follows the Chinese below.

## ThuThesis是什么？
ThuThesis为 <b>T</b>sing<b>h</b>ua <b>U</b>niversity <b>Thesis</b> LaTeX Template之缩写。

此宏包旨在建立一个简单易用的清华大学学位论文LaTeX模板，包括本科综合论文训练、硕士论文、博士论文、博士哲学论文以及博士后出站报告。现在支持本科、硕士、博士论文、博士后出站报告格式，对其它格式（还有么？）的支持会陆续加入。

## 文档
请[下载](https://github.com/xueruini/thuthesis/releases)模板，里面包括具体使用说明以及示例文档：

* 模板使用说明 (thuthesis.pdf)
* 示例文档 (main.pdf)

## 下载
* 发行版：[CTAN](http://www.ctan.org/pkg/thuthesis)
* 开发版：[GitHub](https://github.com/xueruini/thuthesis)

## 升级：
## 自动更新
通过 TeX 发行版工具自动从 [CTAN](http://www.ctan.org/pkg/thuthesis) 更新。

## 手动更新
从 [GitHub](https://github.com/xueruini/thuthesis) 下载放入论文目录，执行命令（Windows 用户在文件夹空白处按`Shift+鼠标右键`，点击“在此处打开命令行窗口”）：

    xetex thuthesis.ins

即可得到 `thuthesis.cls` 等模板文件。

## 提问
按推荐顺序排序：

* 先到 [FAQ](https://github.com/xueruini/thuthesis/wiki/FAQ) 看看常见问题
* [Github Issues](http://github.com/xueruini/thuthesis/issues)
* [TeX@newsmth](http://www.newsmth.net/nForum/#!board/TeX)
* [ThuThesis@Google Groups](http://groups.google.com/group/thuthesis)

## Makefile的用法

```shell
make [{all|thesis|shuji|doc|clean|cleanall|distclean}]
```

### 目标
* `make all`       等于 `make thesis && make shuji && make doc`；
* `make cls`       生成模板文件；
* `make thesis`    生成论文 main.pdf；
* `make shuji`     生成书脊 shuji.pdf；
* `make doc`       生成使用说明书 thuthesis.pdf；
* `make clean`     删除示例文件的中间文件（不含 main.pdf）；
* `make cleanall`  删除示例文件的中间文件和 main.pdf；
* `make distclean` 删除示例文件和模板的所有中间文件和 PDF。
