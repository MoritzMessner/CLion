//
// Created by moritz on 13.04.2021.
//

#ifndef CLION_AUFGABE4_H
#define CLION_AUFGABE4_H

#include <iostream>
#include <cassert>

class Aufgabe4 {
private:
    int size;
    const std::string *names;

    int validateSize(std::string *pString, int length);

    std::string *copyArray(std::string *pString, int length);

public:
    Aufgabe4(std::string names[], int length);

    Aufgabe4();

    int getSize() const;

    const std::string *getNames() const;

    const std::string &name(int v);


};


#endif //CLION_AUFGABE4_H
