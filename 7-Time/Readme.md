# OpenFOAM RunTime

OpenFOAM 获取命令行后，首先会创建一个 `Time` 类对象，用于获取当前 `case` 信息，包括执行时间、文件路径、运行状态等

## Code Analysis

标准头文件 `createTime.H` 创建 `Time` 类对象

```c++
Foam::Time runTime(Foam::Time::controlDictName, args);
```

调用构造函数对成员属性初始化

```c++
Foam::Time::Time
(
    const word& controlDictName,
    const argList& args,
    const bool enableFunctionObjects
);
```

基于初始化器列表定义内部属性，例如时间属性

```c++
startTimeIndex_(0),
startTime_(0),
endTime_(0),
beginTime_(startTime_),
userTime_(userTimes::userTime::New(controlDict_)),
```

文件 IO 属性

```c++
TimePaths
(
    args.parRunControl().parRun(),
    args.rootPath(),
    args.globalCaseName(),
    args.caseName()
),

controlDict_
(
    IOobject
    (
        controlDictName,
        system(),
        *this,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
),
```

`foamRun` 中并不直接包含 `Time.H` 文件，包含在 `pimpleSingleRegionControl.H` 中

## Programming

参考 <https://cpp.openfoam.org/v12/classFoam_1_1Time.html>

对象初始化时需要读取输入文件，复制一份算例到当前文件夹

```bash
cp -r $FOAM_TUTORIALS/shockFluid/shockTube .
of_time -case shockTube
```

### Get Directory

除时间信息外，`Time` 类的一个作用是获取文件路径

```c++
Info <<
```


