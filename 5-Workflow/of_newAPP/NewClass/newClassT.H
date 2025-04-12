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
    Foam::newClassT

Description

SourceFiles
    newClassTI.H
    newClassT.C
    newClassTIO.C

\*---------------------------------------------------------------------------*/

#ifndef newClassT_H
#define newClassT_H

#include ".H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class someClass;


// Forward declaration of friend functions and operators

template<class cmpt>
class newClassT;

template<class cmpt>
Istream& operator>>(Istream&, newClassT<cmpt>&);

template<class cmpt>
Ostream& operator<<(Ostream&, const newClassT<cmpt>&);


/*---------------------------------------------------------------------------*\
                          Class newClassT Declaration
\*---------------------------------------------------------------------------*/

template<class cmpt>
class newClassT
:
    public baseClassName
{
    // Private Data

        dataType data_;


    // Private Member Functions


public:

    // Static Data Members

        //- Static data someStaticData
        static const dataType staticData;


    // Constructors

        //- Construct null
        newClassT();

        //- Construct from components
        newClassT(const dataType& data);

        //- Construct from Istream
        newClassT(Istream&);

        //- Copy constructor
        newClassT(const newClassT<cmpt>&);

        //- Disallow default bitwise copy construction
        newClassT(const newClassT<cmpt>&) = delete;


    // Selectors

        //- Select null constructed
        static autoPtr<newClassT<cmpt>> New();


    //- Destructor
    ~newClassT();


    // Member Functions

    // Member Operators

        void operator=(const newClassT<cmpt>&);

        //- Disallow default bitwise assignment
        void operator=(const newClassT<cmpt>&) = delete;


    // Friend Functions

    // Friend Operators

    // IOstream Operators

        friend Istream& operator>> <cmpt>
        (Istream&, newClassT<cmpt>&);

        friend Ostream& operator<< <cmpt>
        (Ostream&, const newClassT<cmpt>&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "newClassTI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "newClassT.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
