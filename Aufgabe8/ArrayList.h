//
// Created by moritz on 13.04.2021.
//

#ifndef CLION_Friends_H
#define CLION_Friends_H

#include <iostream>
#include <cassert>

template<typename T>
class ArrayList {
private:
    int size;
    T *names{};

    int validateSize(T *pString, int length);

    T *copyArray(T *pString, int length, bool flag = false);

public:
    ArrayList(T names[], int length);

    ArrayList();

    ArrayList(const ArrayList &_otherFriends);

    ~ArrayList();


    int getSize() const;

    T *getNames() const;

    const T &name(int v) const;

    void set_name_on_position(int _position, const T &_value);

    void add(const T &name);

    void setSize(int _new_size);

    void setNames(T *_names);

    void deconstruct();

    bool operator==(const ArrayList &other) const;

    bool operator!=(const ArrayList &other) const;


    ArrayList &operator=(const ArrayList &other);

    const T &operator[](int _position) const;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, ArrayList<T> &_friend);


#endif //CLION_Friends_H
