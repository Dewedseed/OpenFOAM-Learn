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

\*---------------------------------------------------------------------------*/

#include "NewFunc.H"
#include "Time.H"
#include "fvMesh.H"
#include "addToRunTimeSelectionTable.H"
#include "volFields.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(NewFunc, 0);
    addToRunTimeSelectionTable(functionObject, NewFunc, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::NewFunc::NewFunc
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fvMeshFunctionObject(name, runTime, dict),
    wordData_(dict.lookupOrDefault<word>("wordData", "defaultWord")),
    scalarData_(dict.lookup<scalar>("scalarData")),
    labelData_(dict.lookup<label>("labelData"))
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::NewFunc::~NewFunc()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::functionObjects::NewFunc::read(const dictionary& dict)
{
    dict.readIfPresent("wordData", wordData_);
    dict.lookup("scalarData") >> scalarData_;
    dict.lookup("labelData") >> labelData_;

    return true;
}


Foam::wordList Foam::functionObjects::NewFunc::fields() const
{
    return wordList::null();
}


bool Foam::functionObjects::NewFunc::execute()
{
    return true;
}


bool Foam::functionObjects::NewFunc::end()
{
    return true;
}


bool Foam::functionObjects::NewFunc::write()
{
    return true;
}


// ************************************************************************* //
