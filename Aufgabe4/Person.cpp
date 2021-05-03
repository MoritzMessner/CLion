//
// Created by moritz on 30.03.2021.
//

#include "Person.h"
#include <iostream>


std::string Person::validateFirstName(std::string _first_name) const {
    if (_first_name.empty())
        throw std::invalid_argument("falscher firstname");
    return _first_name;
};



Person::Person(std::string _first_name, std::string _last_name, Date _born) : last_name(
        validateLastName(_last_name)), first_name(validateFirstName(_first_name)), born(_born) {

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

