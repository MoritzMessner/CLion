//
// Created by moritz on 30.03.2021.
//

#ifndef CLION_PERSON_H

#include "Date.h"
#include <iostream>

#define CLION_PERSON_H


class Person {
private:
    std::string last_name;
    std::string first_name;
    Date born;

    std::string validateFirstName(std::string _first_name) const;

    std::string validateLastName(std::string _last_name) const;


public:
    Person(std::string _first_name, std::string _last_name, Date _born);

    const std::string &get_last_name() const;

    const std::string &get_first_name() const;

    const Date &get_born() const;

    bool compare(const Person &_other) const;
};


#endif //CLION_PERSON_H
