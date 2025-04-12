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

Class
    Foam::newClass

Description

SourceFiles
    newClassI.H
    newClass.C
    newClassIO.C

\*---------------------------------------------------------------------------*/

#ifndef newClass_H
#define newClass_H

#include ".H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class Istream;
class Ostream;

// Forward declaration of friend functions and operators
class newClass;
Istream& operator>>(Istream&, newClass&);
Ostream& operator<<(Ostream&, const newClass&);


/*---------------------------------------------------------------------------*\
                          Class newClass Declaration
\*---------------------------------------------------------------------------*/

class newClass
:
    public baseClassName
{
    // Private Data

        //- Description of data_
        dataType data_;


    // Private Member Functions


public:

    // Static Data Members

        //- Static data staticData
        static const dataType staticData;


    // Constructors

        //- Construct null
        newClass();

        //- Construct from components
        newClass(const dataType& data);

        //- Construct from Istream
        newClass(Istream&);

        //- Copy constructor
        newClass(const newClass&);

        //- Disallow default bitwise copy construction
        newClass(const newClass&) = delete;


    // Selectors

        //- Select null constructed
        static autoPtr<newClass> New();


    //- Destructor
    ~newClass();


    // Member Functions

        // Access

        // Check

        // Edit

        // Write


    // Member Operators

        void operator=(const newClass&);

        //- Disallow default bitwise assignment
        void operator=(const newClass&) = delete;


    // Friend Functions

    // Friend Operators

    // IOstream Operators

        friend Istream& operator>>(Istream&, newClass&);
        friend Ostream& operator<<(Ostream&, const newClass&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "newClassI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
