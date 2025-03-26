#include <iostream>
#include "Abstract.h"
using namespace std;

int main()
{
    Bird *bird = new Sparrow();
    birdDoesSomething(bird);

    Bird *b = new Eagle();
    birdDoesSomething(b);
    b->drink();

    // Bird *b2 = new Bird();// error // no object of abstract class can be made still if there is non virtual fxn
    return 0;
}