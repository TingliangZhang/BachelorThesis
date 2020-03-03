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

运行：

```
latexmk -c
```

即可清除编译附加文件。大写C清除PDF等输出文件。



## VSCode相关

https://code.visualstudio.com/docs/getstarted/tips-and-tricks#_editing-hacks

表格对齐自动换行

using the ALT+Z keyboard shortcut to *Toggle Word Wrap*

Ctrl+F2   Select all occurrences of current word

Ctrl+Shift+L Select all occurrences of current selection

Alt+Click Insert cursor

To set cursors above or below the current position use: Keyboard Shortcut: Ctrl+Alt+Up or Ctrl+Alt+Down

### Column (box) selection

You can select blocks of text by holding Shift+Alt (Shift+Option on macOS) while you drag your mouse. A separate cursor will be added to the end of each selected line.



My VSCode Settings

```json
{

  "window.zoomLevel": 0,

  "git.autofetch": true,

  "latex-workshop.latex.autoBuild.run": "never",

  "editor.fontSize": 18,

  "editor.wordWrap": "on",

  "arduino.path": "C:\\Program Files (x86)\\Arduino"

}
```

## Latex相关

#### [Why should I put a ~ before \ref or \cite?](https://tex.stackexchange.com/questions/9633/why-should-i-put-a-before-ref-or-cite)

The `~` is a non-breaking space, (not really a symbol) so when you write in your text `Table~\ref{mytable}` it ensures that the `Table` part is kept together with the number. This is generally considered to be good for readability.

Latex源码里面注意不要出现下划线，短横线可以。可以用\\_做为下划线，\textbackslash{}作为反斜杠。\\\\是换行。

[LaTeX 黑魔法（一）：tcolorbox 宏包简明教程](https://liam.page/2016/07/22/using-the-tcolorbox-package-to-create-a-new-theorem-environment/)



## PDF插入3D模型

[PDF file containing 3D object is not included correctly with \includegraphics](https://tex.stackexchange.com/questions/52018/pdf-file-containing-3d-object-is-not-included-correctly-with-includegraphics)

https://www.ctan.org/pkg/media9

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
