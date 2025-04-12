#include "testAPI.H"

#include "IOstreams.H"
// #include "label.H"

using namespace Foam;

void TestAPI::TestLabel()
{
    Foam::label i = 10;
    Foam::label j{ 2 };

    Info << i << j << endl;
    Info << pow(i, j) << endl;
    Info << factorial(i) << endl;
}
