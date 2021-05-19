//
// Created by moritz on 18.05.2021.
//



#include <iostream>
#include<fstream>
#include <cassert>
#include "Aufgabe9.h"

namespace aufgabeNine {


    std::string extract_airline(const std::string &text) {
        std::cout << text << std::endl;
        return text;
    }

    std::ifstream readfile(std::string &filename) {
        std::ifstream in(filename);
        assert(in.is_open());
        return in;
    }


    void closeFile(std::ifstream &file) {
        file.close();
    }

}

int main() {

    std::cout << "starting ..." << std::endl;
    aufgabeNine::readfile("AA");
    aufgabeNine::extract_airline("AA");
    aufgabeNine::closeFile("AA");
    std::cout << "tests passed ..." << std::endl;
    std::cout << "closing ..." << std::endl;

    return 1;
}

