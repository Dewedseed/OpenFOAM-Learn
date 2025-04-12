# HelloWorld

基于 OpenFOAM 环境编译并输出信息

## `wmake`

OpenFOAM `wmake` 是基于 `make` 的编译脚本，专用于在 OpenFOAM 中编译组件

## Coding Style

OpenFOAM 详细编码风格参考 <https://openfoam.org/dev/coding-style-guide/> 此处注意两点

- 文件名采用 `驼峰` 格式，首字母小写
- 文件名后缀为 `*.C` `*.H`

## Compile

在当前路径下编译

```bash
wclean
wmake
```

编译生成可执行文件 `-o $FOAM_USER_APPBIN/of_helloWorld_wmake`，编译路径已包含在环境变量中，因此可以直接执行

```bash
of_helloWorld_wmake
```

打印 `HelloWorld` 信息

```bash
iostream:   Hello World!
Foam::Info: Hello World!
```




