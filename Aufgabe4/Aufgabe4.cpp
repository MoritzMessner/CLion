//
// Created by moritz on 13.04.2021.
//

#include "Aufgabe4.h"
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <cassert>


// Constructors

Aufgabe4::Aufgabe4(std::string names[], int length) : size(validateSize(names, length)),
                                                    names(copyArray(names, length)) {

}

Aufgabe4::Aufgabe4() : Aufgabe4(nullptr, 0) {

}

// validate input parameters
int Aufgabe4::validateSize(std::string *pString, int length) {
    if ((pString == nullptr && length == 0) || length >= 0)
        return length;
    throw std::invalid_argument("falscher size ");
}

std::string *Aufgabe4::copyArray(std::string *pString, int length) {
    if (pString == nullptr)
        return pString;
    auto *returner = new std::string[length];
    for (int i = 0; i < length; i++) {
        returner[i] = pString[i];
    }
    return returner;
}


// setter and getter

int Aufgabe4::getSize() const {
    return this->size;
}


const std::string *Aufgabe4::getNames() const {
    return names;
}


// Methods
const std::string &Aufgabe4::name(int v) {
    if (v >= this->getSize() || v < 0)
        throw std::invalid_argument("im index ist was falsch ");
    return this->names[v];
}


void test_firends() {

    // Test a)
    std::string names[2] = {"Donald", "Daisy"};
    Aufgabe4 friends(names, 2);

    // Test b)
    Aufgabe4 friendsTest;

    // Test c)
    std::cout << friends.name(0) << std::endl;
    assert(friendsTest.getSize() == 0);
    assert(friendsTest.getNames() == nullptr);


    // Test d)
    try {
        std::string namesFalse[2] = {"Hans", "Wurst"};
        Aufgabe4 friendsFalse(namesFalse, -2);

        Aufgabe4 wrongFriend = Aufgabe4(nullptr, -10);
        wrongFriend.getSize();

    } catch (...) {
        std::cout << "nichts gehe" << std::endl;
    }


    // Test e)
    std::string namesOne[2] = {"Hans", "Wurst"};
    Aufgabe4 friendsOne(namesOne, 2);
    assert(friendsOne.name(0) == "Hans");
    namesOne[0] = "Mickey";
    assert(friendsOne.name(0) == "Hans");




}


void test_person() {
    Date aBorn(1913, 2, 28);
    Person a("Max", "a", aBorn);


    Date bBorn(2020, 1, 2);;
    Person b("Falscher", "b", bBorn);


    Date cBorn(1996, 2, 1);
    Person c("Richtiger", "c", cBorn);


    assert(b.compare(a) == false);
    assert(c.compare(b) == false);
    assert(c.compare(a) == false);

}


int main() {
    std::cout << "starting" << std::endl;
    test_firends();
    test_person();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 0;
}