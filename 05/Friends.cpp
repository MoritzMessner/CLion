//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
#include "Friends.h"


ArrayList::ArrayList(std::string *names, int size) : names(validate_names(names, size)), size(validate_size(size)) {
    std::cout << "ctr called" << std::endl;
}

ArrayList::ArrayList() : ArrayList(nullptr, 0) {}

std::string *ArrayList::get_names() const {
    return names;
}

int ArrayList::get_size() const {
    return size;
}

std::string &ArrayList::name(int v) {
    if (v >= size || v < 0) {
        throw std::invalid_argument("This position does not exist!");
    }
    return names[v];
}

int ArrayList::validate_size(int _size) {
    if (_size < 0) {
        throw std::invalid_argument("Size cannot be less than 0!");
    }
    return _size;
}

std::string *ArrayList::validate_names(std::string *_names, int _size) {
    if (_size > 0) {
        std::string *copy = new std::string[_size];
        for (int i = 0; i <= _size; i++) {
            copy[i] = _names[i];
        }
        return copy;
    }
    return nullptr;
}

ArrayList::ArrayList(const ArrayList &_otherFriends) : ArrayList(_otherFriends.get_names(), _otherFriends.get_size()) {

}


void ArrayList::set_names(const int &_test) {
    std::cout << _test << std::endl;
    //ArrayList::names = _names;
    // ArrayList::size = _size;
    //this->size = _size;
}

/*
void ArrayList::change_friend(const std::string &_name, const int &_position) {
    names[_position] = _name;
}
 */




