//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
#include "Friends.h"


Friends::Friends(std::string *names, int size) : names(validate_names(names, size)), size(validate_size(size)) {
    std::cout << "ctr called" << std::endl;
}

Friends::Friends() : Friends(nullptr, 0) {}

std::string *Friends::get_names() const {
    return names;
}

int Friends::get_size() const {
    return size;
}

std::string &Friends::name(int v) {
    if (v >= size || v < 0) {
        throw std::invalid_argument("This position does not exist!");
    }
    return names[v];
}

int Friends::validate_size(int _size) {
    if (_size < 0) {
        throw std::invalid_argument("Size cannot be less than 0!");
    }
    return _size;
}

std::string *Friends::validate_names(std::string *_names, int _size) {
    if (_size > 0) {
        std::string *copy = new std::string[_size];
        for (int i = 0; i <= _size; i++) {
            copy[i] = _names[i];
        }
        return copy;
    }
    return nullptr;
}

Friends::Friends(const Friends &_otherFriends) : Friends(_otherFriends.get_names(), _otherFriends.get_size()) {

}


void Friends::set_names(const int &_test) {
    std::cout << _test << std::endl;
    //Friends::names = _names;
    // Friends::size = _size;
    //this->size = _size;
}

/*
void Friends::change_friend(const std::string &_name, const int &_position) {
    names[_position] = _name;
}
 */




