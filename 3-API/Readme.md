# OpenFOAM API

OpenFOAM 基础库，头文件定义于 `/opt/openfoam7/src/OpenFOAM/lnInclude` 路径下，包括基本数据结构、单位、输入输出等

```bash
# find header file
find $FOAM_SRC --name xxx.H
```

## Data Type

| 数据类型   | 描述                |
| :--------- | ------------------- |
| `label`    | 整型 <integer>      |
| `scalar`   | 标量/浮点数 <float> |
| `vector`   | 矢量                |
| `tensor`   | 张量/多维数组       |
| `word`     | 字符串              |
| `Field`    | 场                  |
| `tmp<>`    | 临时数组            |
| `IOobject` | 接入数据结构        |

`label`、`scalar` 定义较为简单

```c++
typedef INT_SIZE(int, _t) label;

typedef float floatScalar;
typedef double doubleScalar;
```

`Vector` 模板类在 `Vector.H` 中声明，具体类型 `<cmpt>` 在 `bools` `complex` `floats` `ints` `lists` 中继承实现，例如

```c++
typedef Vector<scalar> vector;
typedef Field<vector> vectorField;
```

`vector` 模板方法在 `VectorI.H` 中定义，包括点积 innerProduct(&) 和叉积 crossProduct(^)

与 `vector` 类似，`tensor` 模板类在 `Tensor.H` 中声明，模板方法在 `TensorI.H` 中定义，详细函数和操作符可查看相应 API

`Field` 场类包括 `DimensionedField` `fvPatchField` `IOField` 等

## Dimension

量纲设置 `dimension*`

## IOstream

## Reference

**OpenFOAM API** | <https://www.openfoam.com/documentation/guides/latest/api/index.html>
**OpenFOAM API** | <https://cpp.openfoam.org/v12/>
