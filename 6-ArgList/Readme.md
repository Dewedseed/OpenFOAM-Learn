# OpenFOAM Argument Lists

OpenFOAM 读取及处理命令行

## Command Line

参考 COM 版本文档 <https://doc.openfoam.com/2312/fundamentals/command-line/>

OpenFOAM 命令行基本结构为

```bash
<application> [OPTIONS] <arguments>
```

## Programming

执行 `foamNewApp of_argList` 创建新项目，删除注释外的非必要代码，保留代码如下

```c++
#include "argList.H"
using namespace Foam;
int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    return 0;
}
```

直接编译 `wmake` 运行 `of_argList` 会输出求解器基本信息，执行 `of_argList -help` 可查看目前支持的指令

`src/OpenFOAM/lnInclude/setRootCase.H` 头文件是用于命令行处理的标准模块，创建了 `args` 处理器

```c++
Foam::argList args(argc, argv);
if (!args.checkRootCase())
{
    Foam::FatalError.exit();
}
```

## `argList.H`

<https://cpp.openfoam.org/v12/classFoam_1_1argList.html#details>

参考 `foamRun.C`

### Add option

添加自定义选项并打印

```c++
argList::addOption("solver", "name", "Solver Name");
args.printUsage();
```

输出结果 `-[opt] <para> [Usage]` 分别对应option三部分

```bash
-solver <name>    Solver Name
```

### Get Option

获取选项定义的值

```c++
word solverName;
args.optionReadIfPresent("solver", solverName);
Info << "Solver Name: " << solverName << endl;
```
