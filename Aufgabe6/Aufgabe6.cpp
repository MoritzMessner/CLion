//
// Created by moritz on 27.04.2021.
//

#include "Aufgabe6.h"
#include "Friends.h"
#include <iostream>
#include <cassert>
#include <typeinfo>


void test_friends() {

    // Aufgabe 1
    std::string names[2] = {"Donald", "Daisy"};
    Friends friends(names, 2);
    friends.add("Gustav");

    assert(friends.name(2) == "Gustav");
    friends.deconstruct();
}


void test_operators(){
    std::string names[2] = {"Op1", "Op2"};
    Friends friends(names, 2);
    auto friends2 = friends;
    assert((friends==friends2) == true);
    assert((friends!=friends2) == false);

    friends.add("Hannes");
    assert((friends!=friends2) == true);
}


int main() {
    std::cout << "starting" << std::endl;
    test_friends();
    test_operators();
    std::cout << "tests passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 1;
}