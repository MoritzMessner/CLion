//
// Created by moritz on 13.04.2021.
//

#include "Friends.h"
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <cassert>


// Constructors

ArrayList::ArrayList(std::string names[], int length) : size(validateSize(names, length)),
                                                    names(copyArray(names, length)) {

}

ArrayList::ArrayList() : ArrayList(nullptr, 0) {

}

ArrayList::ArrayList(const ArrayList &_otherFriends) : ArrayList(_otherFriends.getNames()  , _otherFriends.getSize()) {

}

// validate input parameters
int ArrayList::validateSize(std::string *pString, int length) {
    if ((pString == nullptr && length == 0) || length >= 0)
        return length;
    throw std::invalid_argument("falscher size ");
}

std::string *ArrayList::copyArray(std::string *pString, int length) {
    if (pString == nullptr)
        return pString;
    std::string *returner = new std::string[length];
    for (int i = 0; i < length; i++) {
        returner[i] = pString[i];
    }
    return returner;
}

const std::string &ArrayList::name(int v) {
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


std::string *ArrayList::getNames() const {
    return names;
}

