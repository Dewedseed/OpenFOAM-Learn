# OpenFOAM Mesh

OpenFOAM 基于网格控制文件创建网格

## Template

`createMesh.H` 标准文件代码如下，基于 `system/blockMeshDict` 文件创建网格

```c++
Foam::Info
    << "Create mesh for time = "
    << runTime.name() << Foam::nl << Foam::endl;

Foam::fvMesh mesh
(
    Foam::IOobject
    (
        Foam::fvMesh::defaultRegion,
        runTime.name(),
        runTime,
        Foam::IOobject::MUST_READ
    )
);
```
