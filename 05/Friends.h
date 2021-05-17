//
// Created by Aljosha on 03.04.2021.
//

#ifndef OOP_FRIENDS_H
#define OOP_FRIENDS_H

#include <string>


class ArrayList {
private:
    std::string *names;
    int size;

    static int validate_size(const int _size);

public:
    ArrayList(std::string *names, int size);

    ArrayList();

    ArrayList(const ArrayList &_otherFriends);


    std::string *get_names() const;

    int get_size() const;

    std::string &name(int v);

    void set_names(const int &_test);

    //void change_friend(const std::string &_name, const int &_position);


    std::string *validate_names(std::string *_names, int _size);

    //void set_name_on_position(int _position, const std::string &_value);
};


#endif //OOP_FRIENDS_H
