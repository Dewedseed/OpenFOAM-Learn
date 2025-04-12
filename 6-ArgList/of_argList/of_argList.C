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
    of_argList

Description

\*---------------------------------------------------------------------------*/

#include "argList.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

    // add options
    argList::addOption("solver", "name", "Solver Name");
    argList::addOption("intOpt", "int",  "Test Integer Option");
    argList::addOption("noParaOpt", "",  "No Paramter Option");

    #include "setRootCase.H"

    args.printUsage();

    Info << "------------------------------------------" << endl;

    word solverName;
    args.optionReadIfPresent("solver", solverName);
    Info << "Solver Name: " << solverName << endl;

    label intOpt;
    args.optionReadIfPresent("intOpt", intOpt);
    Info << "IntOpt :" << intOpt << endl;

    Info << "------------------------------------------" << endl;

    Info << "Command Line: " << args.commandLine() << endl;
    Info << "Executable Name: " << args.executable() << endl;
    Info << "Argument Size: " << args.size() << endl;

    Info << "------------------------------------------" << endl;
    argList::addNote("This is extra notes for the usage information.");
    args.printNotes();

    Info << "------------------------------------------" << endl;
    Info << "Remove options -doc(default) -solver" << endl;
    argList::removeOption("doc");
    argList::removeOption("solver");
    args.printUsage();

    return 0;
}


// ************************************************************************* //
