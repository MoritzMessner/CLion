//
// Created by moritz on 30.03.2021.
//

#include "Person.h"
#include <iostream>

bool Person::validatePerson() const {
    if (this->first_name.empty() || this->last_name.empty())
        return false;
    return true;
};


void Person::init(std::string _first_name, std::string _last_name, Date _born) {
    this->first_name = _first_name;
    this->last_name = _last_name;
    this->born = _born;
    if (!validatePerson())
        throw std::invalid_argument("first or lastname is empty");
};


const std::string &Person::get_last_name() const {
    return this->last_name;
};

const std::string &Person::get_first_name() const {
    return this->first_name;
};

const Date &Person::get_born() const {
    return this->born;
};

bool Person::compare(const Person &_other) const {
    // if (this->get_last_name().size() == _other.get_last_name().size())
    return (this->get_last_name() <= _other.get_last_name());
    //if (this->get_last_name().size() < _other.get_last_name().size())
    //     return true;
    //return false;
};

