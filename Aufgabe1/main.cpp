//
// Created by Moritz on 12.03.2021.
//


#include <iostream>
#include <cassert>


namespace hfu {

    int power(int _base, int _exponent) {
        if (_exponent < 0)
            throw std::invalid_argument("exponent <0");
        int result = 1;
        for (int i = 1; i <= _exponent; ++i) {
            result *= _base;
        }
        return result;
    }

    void powerTest() {
        assert(power(2, 3) == 8);
        assert(power(2, 4) == 16);
        try {
            assert(power(2, -3) == 8);
            assert(false);
        } catch (...) {
            std::cout << "nichts gehe" << std::endl;
        }

        assert(power(0, 3) == 0);
        assert(power(3, 0) == 1);
        assert(power(-3, 0) == 1);
        assert(power(0, 0) == 1);
    }

    int gdc(int _v, int _w) {
        if (_v == 0 && _w == 0)
            throw std::invalid_argument("Both args are zero");
        while (_w != 0) {
            int tmp = _w;
            _w = _v % _w;
            _v = tmp;
        }
        return _v;
    }

    void gdc_Test() {

        assert(gdc(8, 12) == 4);
        assert(gdc(12, 8) == 4);
        assert(gdc(0, 5) == 5);
        assert(gdc(5, 0) == 5);
        try {
            assert(gdc(0, 0) == 0);
            assert(false);
        } catch (...) {

        }
    }

    // this function mergers to numbers into one number
    // @returns the merged value
    double to_double(int _integer, std::string _fractional) {
        if(std::stod(_fractional) < 0)
            throw std::invalid_argument("invalid arg");
        std::string newValue = std::to_string(_integer) + "." + _fractional;
        return std::stod(newValue);
    }

    void to_double_test() {
        assert(to_double(5, "11") == 5.11);
        assert(to_double(100, "11") == 100.11);
        assert(to_double(1, "1111111111") == 1.1111111111);
        assert(to_double(-1, "1111111111") == -1.1111111111);
        assert(to_double(0, "00000000001") == 0.00000000001);
        assert(to_double(0, "10000000000") == 0.10000000000);
    }
}

int main() {

    std::cout << "starting ..." << std::endl;
    //powerTest();
    //gdc_Test();
    hfu::to_double_test();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 0;
}