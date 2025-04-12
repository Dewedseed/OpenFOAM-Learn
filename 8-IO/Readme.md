# OpenFOAM IO (file)

OpenFOAM 文件输入输出/文件流

## `IOobject`

OpenFOAM 基于 STL 封装了文件读写流 `IFstream` 和 `OFstream`，但对于 OpenFOAM 格式的算例输入文件使用 `IOobject`

<https://cpp.openfoam.org/v12/classFoam_1_1IOobject.html>
<https://www.topcfd.cn/18701/>

### Construct

执行 `foamNewApp of_IO` 创建测试项目

`IOobject` 类包含多个构造函数，如

```c++
IOobject
(
    const word& name,
    const fileName& instance,
    const objectRegistry& registry,
    readOption r=NO_READ,
    writeOption w=NO_WRITE,
    bool registerObject=true
);
```

其中 `name` 为文件名，`instance` 为文件夹

```c++
IOobject dictIO(
        dictName,  // file name
        runTime.constant(), // path name
        runTime,  // registry object
        IOobject::MUST_READ // read option
    );
```

### Input

读取文件并返回字典 `IOdictionary`

```c++
dictionary customDict = IOdictionary(dictIO);
```

从字典中获取定义值，注意 `{}` 和 `()`，现版本建议还是使用 `()`

```c++
word         testWord  { customDict.lookup("testWord") };
doubleScalar testScalar{ customDict.lookupOrDefault("testScalar", 1.0) };
HashTable<vector, word> testHashT ( customDict.lookup("testHashTable") );
```

### Output

## `OFstream.H`

采用文件流 `OFstream` 实现数据写出，创建文件夹

```c++
Foam::fileName outputDir = runTime.path()/"postProcessing";
Foam::mkDir(outputDir);
```

创建输出对象

```c++
OFstream outputFile(outputDir/"outputFile.txt");

outputFile << "Custom File" << endl;
outputFile << testHashTable << endl;
```
