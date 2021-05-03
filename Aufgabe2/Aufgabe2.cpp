#include <iostream>
#include <cmath>
#include <cassert>

namespace AufgabeTwo {

    bool is_digit(char c) {
        return ((int) c >= '0' && (int) c <= 57);
    }

    void test_is_digit() {
        assert(is_digit('a') == false);
        assert(is_digit('z') == false);
        assert(is_digit('1') == true);
        assert(is_digit('9') == true);
    }


    bool is_sign(char c, int &sign) {
        if (c == '+' || c == '-') {
            sign = c == '+' ? 1 : -1;
            return true;
        } else
            return false;
    }


    void test_is_sign() {
        int sign = 23;
        assert(is_sign('-', sign));
        assert(sign == -1);
        sign = 23;
        assert(is_sign('+', sign));
        assert(sign == 1);
    }

    int parse_int(const std::string &text) {
        int sign = 0;
        int result = 0;
        // event hier
        if (text.at(0) == '-' || text.at(0) == '+')
            is_sign(text.at(0), sign);

        int flag = 0;
        if (sign == 1 || sign == -1)
            flag += 1;

        for (std::size_t i = flag; i < text.size(); i++) {
            if (!is_digit(text.at(i)))
                throw std::invalid_argument(std::string(1, text.at(i)) + " is no number");
            int factor = pow(10, (int) text.size() - (int) i - 1);
            result += factor * (int) (text.at(i) - 48);
        }
        sign = sign == 0 ? 1 : sign;
        result = result * sign;
        return result;
    }

    int parse_int(std::string *text) {
        int sign = 0;
        int result = 0;
        if ((*text)[0] == '-' || (*text)[0] == '+')
            is_sign((*text)[0], sign);
        int flag = 0;
        if (sign == 1 || sign == -1)
            flag += 1;
        int len = (*text).length();

        for (int i = flag; i < len; i++) {
            if (!is_digit((*text)[i]))
                throw std::invalid_argument(std::string(1, (*text)[i]) + " is no number");
            int factor = pow(10, len - i - 1);
            result += factor * (int) ((*text)[i] - 48);
        }
        sign = sign == 0 ? 1 : sign;
        return result * sign;
    }

    void test_parse_int() {
        std::string number = "-123";
        assert(parse_int(number) == -123);
        number = "+26459789";
        assert(parse_int(number) == +26459789);
        number = "321";
        assert(parse_int(number) == 321);

        number = "-123";
        assert(parse_int(&number) == -123);
        number = "+26459789";
        assert(parse_int(&number) == +26459789);
        number = "321";
        assert(parse_int(&number) == 321);
    }
}

int main() {
    std::cout << "starting  ..." << std::endl;
    AufgabeTwo::test_is_digit();
    AufgabeTwo::test_is_sign();
    AufgabeTwo::test_parse_int();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 0;
}