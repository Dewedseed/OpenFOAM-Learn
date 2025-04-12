#include "testAPI.H"

#include "IOstreams.H"

using namespace Foam;

void TestAPI::TestScalar()
{
    Foam::floatScalar  fs{ 3.0 }, fs2{ 4.0 };
    Foam::doubleScalar ds{ 5.0 };

    Info << "floatScalar:  " << fs << endl;
    Info << "doubleScalar: " << ds << endl;

    Info << mag(fs) << endl;
    Info << hypot(fs, fs2) << endl;
    Info << atan2(fs, fs2) << endl;

    Info << floatScalarGreat << endl;
    Info << floatScalarSmall << endl;

    Info << doubleScalarGreat << endl;
    Info << doubleScalarSmall << endl;
}
