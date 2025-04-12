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
    Foam::functionObjects::newFunc

Description
    This function object...

    Example of function object specification:
    \verbatim
    newFunc1
    {
        type           newFunc;
        libs ("libnewFuncFunctionObject.so");
        ...
        wordData       someWord;
        scalarData     1.0;
        labelData      1;
    }
    \endverbatim

Usage
    \table
        Property     | Description               | Required | Default value
        type         | type name: newFunc | yes      |
        wordData     | some word option...       | no       | defaultWord
        scalarData   | some scalar value...      | yes      |
        labelData    | some label value...       | yes      |
    \endtable

SourceFiles
    newFunc.C

\*---------------------------------------------------------------------------*/

#ifndef newFunc_H
#define newFunc_H

#include "fvMeshFunctionObject.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                       Class newFunc Declaration
\*---------------------------------------------------------------------------*/

class newFunc
:
    public fvMeshFunctionObject
{
    // Private Data

        //- word
        word wordData_;

        //- scalar
        scalar scalarData_;

        //- label
        label labelData_;


    // Private Member Functions


public:

    //- Runtime type information
    TypeName("newFunc");


    // Constructors

        //- Construct from Time and dictionary
        newFunc
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict
        );

        //- Disallow default bitwise copy construction
        newFunc(const newFunc&) = delete;


    //- Destructor
    virtual ~newFunc();


    // Member Functions

        //- Read the newFunc data
        virtual bool read(const dictionary&);

        //- Return the list of fields required
        virtual wordList fields() const;

        //- Execute, currently does nothing
        virtual bool execute();

        //- Execute at the final time-loop, currently does nothing
        virtual bool end();

        //- Write the newFunc
        virtual bool write();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const newFunc&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
