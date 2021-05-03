//
// Created by Moritz on 16.03.2021.
//

#include "Aufgabe1.h"
#include <iostream>
#include <math.h>
#include <cassert>

namespace AufgabeOne {

    // this function mergers to numbers into one number
    // @returns the merged value
    double to_double(int _integer, int _fractional) {
        if (_fractional < 0)
            throw std::invalid_argument("invalid arg");
        int counter = 0;
        int tempFractional = _fractional;
        while (tempFractional > 0) {
            tempFractional = tempFractional / 10;
            counter++;
        }
        double result;
        if (_integer >= 0)
            result = _integer + _fractional / pow(10, counter);
        else
            result = _integer - _fractional / pow(10, counter);
        return result;
    }

    void to_double_test() {
        assert(to_double(5, 11) == 5.11);
        assert(to_double(3, 452) == 3.452);
        assert(to_double(100, 11) == 100.11);
        assert(to_double(1, 1111111111) == 1.1111111111);
        assert(to_double(-1, 1111111111) == -1.1111111111);
    }
}

int main() {
    std::cout << "starting ..." << std::endl;
    AufgabeOne::to_double_test();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
}