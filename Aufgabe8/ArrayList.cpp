//
// Created by moritz on 13.04.2021.
//

#include "ArrayList.h"
#include "../Aufgabe8/Person.h"
#include "../Aufgabe8/Date.h"
#include <iostream>
#include <cassert>


// Constructors
template<typename T>
ArrayList<T>::ArrayList(T names[], int length) : size(validateSize(names, length)),
                                              names(copyArray(names, length)) {

}

template<typename T>
ArrayList<T>::ArrayList() : ArrayList(nullptr, 0) {

}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList &_otherFriends) : ArrayList(_otherFriends.getNames(), _otherFriends.getSize()) {

}

template<typename T>
ArrayList<T>::~ArrayList() {
    std::cout << "in deconstructor: " << names[0] << std::endl;
    delete[] names;
}

// validate input parameters
template<typename T>
int ArrayList<T>::validateSize(T *pString, int length) {
    if ((pString == nullptr && length == 0) || length >= 0)
        return length;
    throw std::invalid_argument("falscher size ");
}

template<typename T>
T *ArrayList<T>::copyArray(T *pString, int length, bool flag) {
    if (pString == nullptr)
        return pString;
    auto *returner = new T[length];
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

template<typename T>
const T &ArrayList<T>::name(int v) const {
    if (v >= this->getSize() || v < 0)
        throw std::invalid_argument("im index ist was falsch ");
    return this->names[v];
}

template<typename T>
void ArrayList<T>::set_name_on_position(int _position, const T &_value) {
    if (_position >= this->getSize() || _position < 0)
        throw std::invalid_argument("im index ist was falsch ");
    names[_position] = _value;
}
// setter and getter

template<typename T>
int ArrayList<T>::getSize() const {
    return this->size;
}

template<typename T>
void ArrayList<T>::setSize(int _new_size) {
    this->size = _new_size;
}

template<typename T>
void ArrayList<T>::setNames(T _names[]) {
    this->names = _names;
}


template<typename T>
T *ArrayList<T>::getNames() const {
    return names;
}

template<typename T>
void ArrayList<T>::add(const T &name) {
    this->setSize(this->getSize() + 1);
    this->setNames(this->copyArray(names, this->getSize(), true));
    set_name_on_position(this->getSize() - 1, name);
}

template<typename T>
void ArrayList<T>::deconstruct() {
    // Aufgabe 2
    T test[2] = {"Johannes", "Daisy"};
    ArrayList a(test, 2);
    a.getSize();

    T test1[2] = {"Hans", "Daisy"};
    auto *b = new ArrayList(test1, 2);
    b->getSize();
    delete b;
}

// Aufgabe 3
template<typename T>
bool ArrayList<T>::operator==(const ArrayList &other) const {
    if (this->getSize() != other.getSize())
        return false;
    for (int i = 0; i < this->getSize(); i++) {
        if (this->name(i) != other.name(i))
            return false;
    }
    return true;
}

template<typename T>
bool ArrayList<T>::operator!=(const ArrayList &other) const {
    if (this->getSize() != other.getSize())
        return true;
    for (int i = 0; i < this->getSize(); i++) {
        if (this->name(i) != other.name(i))
            return true;
    }
    return false;
}

// Aufgabe 2
template<typename T>
std::ostream &operator<<(std::ostream &out,  ArrayList<T> &_friend) {
    out << "size:" << _friend.getSize() << " frien_friends: ";
    for (int i = 0; i < _friend.getSize(); i++) {
        out << _friend.getNames()[i] << " ";
    }
    return out;
}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList &other) {
    this->setSize(other.getSize());
    this->setNames(this->copyArray(other.getNames(), other.getSize()));
    return *this;
}

template<typename T>
const T &ArrayList<T>::operator[](int _position) const {
    return name(_position);
}
