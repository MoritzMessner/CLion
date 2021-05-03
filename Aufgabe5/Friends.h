//
// Created by moritz on 13.04.2021.
//

#ifndef CLION_Friends_H
#define CLION_Friends_H

#include <iostream>
#include <cassert>

class Friends {
private:
    int size;
    std::string *names{};

    int validateSize(std::string *pString, int length);

    std::string *copyArray(std::string *pString, int length);

public:
    Friends(std::string names[], int length);

    Friends();
    Friends(const Friends& _otherFriends);

    int getSize() const;

    std::string *getNames() const;

    const std::string &name(int v);

    void set_name_on_position(int _position, const std::string& _value);
};


#endif //CLION_Friends_H
