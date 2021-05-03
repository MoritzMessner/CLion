//
// Created by moritz on 13.04.2021.
//

#include "Friends.h"
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <cassert>


// Constructors

Friends::Friends(std::string names[], int length) : size(validateSize(names, length)),
                                                    names(copyArray(names, length)) {

}

Friends::Friends() : Friends(nullptr, 0) {

}

Friends::Friends(const Friends &_otherFriends) : Friends(_otherFriends.getNames(), _otherFriends.getSize()) {

}

Friends::~Friends() {
    std::cout << "in deconstructor: " << names[0] << std::endl;
}

// validate input parameters
int Friends::validateSize(std::string *pString, int length) {
    if ((pString == nullptr && length == 0) || length >= 0)
        return length;
    throw std::invalid_argument("falscher size ");
}

std::string *Friends::copyArray(std::string *pString, int length, bool flag) {
    if (pString == nullptr)
        return pString;
    auto *returner = new std::string[length];
    for (int i = 0; i < length; i++) {
        if (i == length - 1 && flag)
            returner[i] = "";
        else
            returner[i] = pString[i];
    }
    return returner;
}

const std::string &Friends::name(int v) {
    if (v >= this->getSize() || v < 0)
        throw std::invalid_argument("im index ist was falsch ");
    return this->names[v];
}

void Friends::set_name_on_position(int _position, const std::string &_value) {
    if (_position >= this->getSize() || _position < 0)
        throw std::invalid_argument("im index ist was falsch ");
    names[_position] = _value;
}
// setter and getter

int Friends::getSize() const {
    return this->size;
}

void Friends::setSize(int _new_size) {
    this->size = _new_size;
}

void Friends::setNames(std::string _names[]) {
    this->names = _names;
}


std::string *Friends::getNames() const {
    return names;
}

void Friends::add(const std::string &name) {
    this->setSize(this->getSize() + 1);
    this->setNames(this->copyArray(names, this->getSize(), true));
    set_name_on_position(this->getSize() - 1, name);
}

void Friends::deconstruct() {
    std::string test[2] = {"Johannes", "Daisy"};
    Friends a(test, 2);
    a.getSize();
    std::string test1[2] = {"Hans", "Daisy"};
    auto *b = new Friends(test1, 2);
    b->getSize();
    delete b;
}


bool operator==(const Friends &other) const { return true; }
