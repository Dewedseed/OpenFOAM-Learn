# FVM CFD

OpenFOAM 中基于 `finiteVolume` 模块完成 CFD 有限体积法求解，`OpenFOAM-10` 之前的版本可以直接调用 `src/finiteVolume/lnInclude/fvCFD.H -> ../cfdTools/general/include/fvCFD.H` 头文件获取所有基础类，`OpenFOAM-11` 之后版本没有该头文件，需要分别调用 `solver.H` 等头文件

## fvCFD

## Compile

参见 [2-Compile/Readme.md](../2-Compile/Readme.md), `finiteVolume/lnInclude` 不在编译的默认包含路径中，因此需要手动添加

```makefile
# Make/options
EXE_INC = -I(LIB_SRC)/finiteVolume/lnInclude
EXE_LIBS = -lfiniteVolume
```
