# Compile

将源码编译成动态库 Dynamic Link Library (DLL) 并链接成可执行程序

## DLL

动态库目录下包含两个 Class 文件夹，在一个 Make 文件夹设定下编译

```bash
Compile/
|-- Class1
|   |-- class1.C
|   `-- class1.H
|-- Class2
|   |-- class2.C
|   `-- class2.H
`-- Make
    |-- files
    `-- options
```

files 文件中包含源文件和结果文件，此处链接为动态库 `LIB`

```makefile
Class1/class1.C
Class2/class2.C

LIB = $(FOAM_USER_LIBBIN)/libUDClass
```

options 文件中包含编译选项，此处未包含额外头文件，因此空置

```makefile
LIB_INC =
LIB_LIBS =
```

需要注意的是，OpenFOAM 内部头文件会默认包含，包括

- `-I/opt/openfoam7/src/OpenFOAM/lnInclude`
- `-I/opt/openfoam7/src/OSspecific/POSIX/lnInclude`

```makefile
g++ -std=c++11 -m64 -Dlinux64 -DWM_ARCH_OPTION=64 -DWM_DP -DWM_LABEL_SIZE=32 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -Wno-attributes -O3  -DNoRepository -ftemplate-depth-100  -IlnInclude -I. -I/opt/openfoam7/src/OpenFOAM/lnInclude -I/opt/openfoam7/src/OSspecific/POSIX/lnInclude   -fPIC -c Class1/class1.C -o Make/linux64GccDPInt32Opt/Class1/class1.o
```

执行 `wmake Compile` 编译动态库，除了在 `$(FOAM_USER_LIBBIN)` 中生成动态库 `libUDClass.so` 外，在当前目录下还会生成文件夹 `lnInclude`，软链接至各头文件

```bash
Compile/
`-- lnInclude
    |-- class1.C -> ../Class1/class1.C
    |-- class1.H -> ../Class1/class1.H
    |-- class2.C -> ../Class2/class2.C
    `-- class2.H -> ../Class2/class2.H
```

## APP

顶层为可执行程序，结构如下，在同级中添加 `Make` 文件夹设定编译方法

```bash
.
|-- Compile
|-- Make
|   |-- files
|   `-- options
`-- of_compile.C
```

`files` 文件中包含源文件和结果文件，此处编译为可执行程序 `EXE`

```makefile
of_compile.C

EXE = $(FOAM_USER_APPBIN)/of_compile
```

options 文件中包含编译选项，此处需包含动态库的头文件路径，并指定需要链接的动态库，语法与 make 一致

```makefile
EXE_INC = \
    -ICompile/lnInclude

EXE_LIBS = \
    -L$(FOAM_USER_LIBBIN) \
    -lUDClass
```

编译/清理需要进行两次，首先编译/清理动态库，再链接/清理可执行文件，在 `$(FOAM_USER_APPBIN)` 路径下生成可执行文件 `of_compile`

{% note danger %}
**注意：** `wclean` 不会删除 FOAM_USER_LIBBIN 和 FOAM_USER_APPBIN 目录下生成的动态库和可执行程序文件
{% endnote %}

## Guide

OpenFOAM 详细编译方法参考

**OpenFOAM v12 User Guide - 3.2 Compiling applications and libraries** | <https://doc.cfd.direct/openfoam/user-guide-v12/compiling-applications>

OpenFOAM 使用了大量的环境变量来管理路径、编译选项和运行配置，可通过以下命令检索

```bash
env | grep -i "foam\_\|wm\_"
```

环境变量信息参考 `User Guide 3.2.7`
