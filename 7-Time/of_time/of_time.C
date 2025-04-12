/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2025 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    of_time

Description

\*---------------------------------------------------------------------------*/

#include "argList.H"

// #include "pimpleNoLoopControl.H"
#include "Time.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    // #include "createTime.H"
    Foam::Time runTime(Foam::Time::controlDictName, args);

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info << "------------------------------------------" << endl;
    Info << "Time Information" << endl;

    Info << "  " << "name = " << runTime.name() << endl;
    Info << "  " << "beginTime = " << runTime.beginTime() << endl;
    Info << "  " << "endTime = " << runTime.endTime() << endl;
    Info << "  " << "startTime = " << runTime.startTime() << endl;
    Info << "  " << "ExecutionCPUTime = " << runTime.elapsedCpuTime() << endl;
    Info << "  " << "ExecutionClockTime = " << runTime.elapsedClockTime() << endl;

    Info << "------------------------------------------" << endl;
    Info << "Path Information" << endl;

    Info << "  " << "controlDict = " << runTime.controlDict() << endl;
    Info << "  " << "timePath = "    << runTime.timePath() << endl;
    Info << "  " << "rootPath = "    << runTime.rootPath() << endl;
    Info << "  " << "filePath = "    << runTime.filePath() << endl;
    Info << "  " << "path = "        << runTime.path() << endl;
    Info << "  " << "caseName = "    << runTime.caseName() << endl;

    Info << "------------------------------------------" << endl;
    Info << "Get directory" << endl;

    Info << "  " << "Time = "     << runTime.name() << endl;
    Info << "  " << "System = "   << runTime.system() << endl;
    Info << "  " << "Constant = " << runTime.constant() << endl;

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
