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
    of_IO

Description

\*---------------------------------------------------------------------------*/

#include "argList.H"
#include "solver.H"
#include "OFstream.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"

    // Create the default single region mesh
    // #include "createMesh.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    const word dictName("customProperties");

    // IO object
    // IOobject dictIO(
    //     dictName,
    //     runTime.name(),
    //     runTime,
    //     IOobject::MUST_READ
    // );
    IOobject dictIO(
        dictName,  // file name
        runTime.constant(), // path name
        runTime,  // registry object
        IOobject::MUST_READ // read option
    );

    // dictionary object
    dictionary customDict = IOdictionary(dictIO);

    // get content
    word         testWord  { customDict.lookup("testWord") };
    label        testLabel { customDict.lookupOrDefault("testLabel",  1)};
    doubleScalar testScalar{ customDict.lookupOrDefault("testScalar", 1.0) };
    labelList    testList  (customDict.lookup("testList", true)) ;
    HashTable<vector, word> testHashT ( customDict.lookup("testHashTable") );

    bool testBool{ customDict.lookupOrDefault("testBool", true) };

    // output information
    Info << nl << "File: "
         << nl << "testWord   " <<  testWord
         << nl << "testLabel  " <<  testLabel
         << nl << "testScalar " <<  testScalar
         << nl << "testList   " <<  testList
         << nl << "testHashT  " <<  testHashT
         << nl << "testBool   " <<  testBool
         << nl << endl;

    Info<< "End\n" << endl;

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    // create new folder
    Foam::fileName outputDir = runTime.path()/"postProcessing";
    Foam::mkDir(outputDir);

    // output file
    OFstream outputFile(outputDir/"outputFile.txt");

    outputFile << "--------------------------------" << endl;

    outputFile << "Custom File" << endl;
    outputFile << 1 << endl;
    outputFile << 0.15 << endl;
    outputFile << true << endl;

    HashTable<vector, word> testHashTable;
    testHashTable.insert("key 1", vector(1.0, 0, 2.0));
    testHashTable.insert("key 2", vector(0, 0.5, 2.0));
    testHashTable.insert("key 3", vector(3.0, 0, 0.0));
    outputFile << testHashTable << endl;

    outputFile << "--------------------------------" << endl;

    return 0;
}


// ************************************************************************* //
