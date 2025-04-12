# New Solver

基于 OpenFOAM 基础包与工具创建新的求解器

## Workflow

相关命令可在 <https://openfoamwiki.net/> 上搜索，或通过 `-h` 选项查看

### `foamNewApp`

执行 `foamNewApp of_newAPP` 可创建一个新的可执行程序目录

```bash
of_newAPP/
|-- Make
|   |-- files
|   `-- options
|-- createFields.H
`-- of_newAPP.C
```

`options` 文件中自动添加 `fvCFD` 和 `meshTools` 包含路径及基础库

### `foamNewFunctionObject`

`foamNewFunctionObject NewFunc` 添加新函数对象，包括头文件、源文件及编译文件

```bash
NewFunc/
|-- Make
|   |-- files
|   `-- options
|-- NewFunc.C
`-- NewFunc.H
```

### `foamNew`

`foamNew` 创建新的源文件，不会创建编译文件，以下命令在 `NewClass` 文件夹下执行

- `foamNew -s H newClass`  创建头文件 `newClass.H`
- `foamNew -s C newClass`  创建源文件 `newClass.C` 定义类具体方法
- `foamNew -s I newClass`  创建头文件 `newClassI.H` 定义类内部方法，如构造函数、运算符重载等
- `foamNew -s IO newClass` 创建源文件 `newClassIO.C` 定义类输出输出方法
- `foamNew -t H newClassT cmpt` 创建模板类头文件 `newClassT.H`
- `foamNew -t I newClassT cmpt` 创建模板类源文件 `newClassTI.C`

`foamNewSource` `foamNewTemplate` 可完成相似功能

### `foamNewBC`

