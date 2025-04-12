# OpenFOAM Programming

{% note info %}
**当前环境 OpenFOAM-7**
{% endnote %}

## Environment

OpenFOAM 编译环境通过 `docker` 实现

```bash
# download openfoam11 images
docker pull openfoam/openfoam11-paraview510
# create and run openfoam11 container
docker run -itd --name openfoam-11 -v local/run:/home/run openfoam/openfoam11-paraview510
# execute container
docker exec -it openfoam-11 /bin/bash
```

## Reference

**析模界** | <https://www.topcfd.cn/simulation/solve/openfoam/openfoam-program/>

***OpenFOAM UserGuide* | <https://doc.cfd.direct/openfoam/user-guide-v12/index>
***OpenFOAM Document* | <https://cfd.direct/openfoam/documentation/>
***OpenFOAM Wiki* | <https://openfoamwiki.net/index.php/Main_Page>
***OpenFOAM training Programming* | <https://cfd.direct/openfoam-training/programming-cfd/>
**UnnamedMoose** | <https://github.com/UnnamedMoose/BasicOpenFOAMProgrammingTutorials>
**OpenFOAM Course - Chalmers University of Technology** | <https://www.tfd.chalmers.se/~hani/kurser/OS_CFD/>
**OpenFOAM programming course (Tom Smith, UCL)** | <https://www.youtube.com/watch?v=KB9HhggUi_E&ab_channel=UCLOpenFOAMWorkshop>
**东岳流体** | <http://dyfluid.com/#>
**Aerosand's blog** | <https://aerosand.cn/>
