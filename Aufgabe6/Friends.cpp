//
// Created by moritz on 13.04.2021.
//

#include "Friends.h"
#include "Person.h"
#include "Date.h"
#include "../Aufgabe7/Friends.h"
#include <iostream>
#include <cassert>


// Constructors

ArrayList::ArrayList(std::string names[], int length) : size(validateSize(names, length)),
                                                    names(copyArray(names, length)) {

}

ArrayList::ArrayList() : ArrayList(nullptr, 0) {

}

ArrayList::ArrayList(const ArrayList &_otherFriends) : ArrayList(_otherFriends.getNames(), _otherFriends.getSize()) {

}

ArrayList::~ArrayList() {
    std::cout << "in deconstructor: " << names[0] << std::endl;
    delete[] names;
}

// validate input parameters
int ArrayList::validateSize(std::string *pString, int length) {
    if ((pString == nullptr && length == 0) || length >= 0)
        return length;
    throw std::invalid_argument("falscher size ");
}

std::string *ArrayList::copyArray(std::string *pString, int length, bool flag) {
    if (pString == nullptr)
        return pString;
    auto *returner = new std::string[length];
    for (int i = 0; i < length; i++) {
        if (i == length - 1 && flag)
            returner[i] = "";
        else
            returner[i] = pString[i];
    }
    if (flag == true) {
        std::cout << "del names" << std::endl;
        delete[] names;
    }
    return returner;
}

const std::string &ArrayList::name(int v) const {
    if (v >= this->getSize() || v < 0)
        throw std::invalid_argument("im index ist was falsch ");
    return this->names[v];
}

void ArrayList::set_name_on_position(int _position, const std::string &_value) {
    if (_position >= this->getSize() || _position < 0)
        throw std::invalid_argument("im index ist was falsch ");
    names[_position] = _value;
}
// setter and getter

int ArrayList::getSize() const {
    return this->size;
}

void ArrayList::setSize(int _new_size) {
    this->size = _new_size;
}

void ArrayList::setNames(std::string _names[]) {
    this->names = _names;
}


std::string *ArrayList::getNames() const {
    return names;
}

void ArrayList::add(const std::string &name) {
    this->setSize(this->getSize() + 1);
    this->setNames(this->copyArray(names, this->getSize(), true));
    set_name_on_position(this->getSize() - 1, name);
}

void ArrayList::deconstruct() {
    // Aufgabe 2
    std::string test[2] = {"Johannes", "Daisy"};
    ArrayList a(test, 2);
    a.getSize();

    std::string test1[2] = {"Hans", "Daisy"};
    auto *b = new ArrayList(test1, 2);
    b->getSize();
    delete b;
}

// Aufgabe 3
bool ArrayList::operator==(const ArrayList &other) const {
    if (this->getSize() != other.getSize())
        return false;
    for (int i = 0; i < this->getSize(); i++) {
        if (this->name(i) != other.name(i))
            return false;
    }
    return true;
}

bool ArrayList::operator!=(const ArrayList &other) const {
    return !(*this == other);
}


