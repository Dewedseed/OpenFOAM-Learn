#include "helloWorld.H"

#include "IOstreams.H"

#include <iostream>

void InfoTest::HelloWorld() {

    std::cout  << "iostream:   " << "Hello World!" << std::endl;
    Foam::Info << "Foam::Info: " << "Hello World!" << Foam::endl;

}
