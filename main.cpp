//#include "Strategy.h"
//#include "Observer.h"
//#include "Decorator.h"
//#include "Singleton.h"
//#include "State.h"
#include <string>
#include <iostream>
#include <sstream>

double fnk(int n, int k) {
    if(k == 0) {
        return n;
    }
    return fnk(n*n, k-1) * fnk(n*n, k-1);
}

int main() {
    std::cout << fnk(2,1);
}