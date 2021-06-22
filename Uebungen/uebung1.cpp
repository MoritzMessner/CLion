//
// Created by moritz on 22.06.2021.
//

#include "uebung1.h"
#include <iostream>

void increase(int *w) {
    (*w)++;
}

void increase(int &w) {
    w++;
}

int main() {
    int w = 23;
    increase(&w);
    increase(w);
    std::cout << w << std::endl;
    return 0;
}