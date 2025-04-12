#include "testAPI.H"

#include "IOstreams.H"
// #include "label.H"
#include "vector.H"

using namespace Foam;

void TestAPI::TestVector()
{
    vector v1{0.5, 0.7, 0.3};
    vector v2{0.3, 0.4, 0.6};

    Info << v1 << endl;
    Info << v2 << endl;

    Info << v1 + v2 << endl;
    Info << 2.0 * v1 << endl;

    // method: get component
    Info << v1.x() << v1.y() << v1.z() << endl;

    // inner-product
    Info << (v1 & v2) << endl;

    // cross-product
    Info << (v1 ^ v2) << endl;
}
