//
// Created by moritz on 27.04.2021.
//

#include "Aufgabe6.h"
#include "Friends.h"
#include <iostream>
#include <cassert>
#include <typeinfo>

void test_friends() {
    std::string names[2] = {"Donald", "Daisy"};
    Friends friends(names, 2);
    friends.add("Gustav");
    assert(friends.name(2) == "Gustav");
    friends.deconstruct();
}


int main() {
    std::cout << "starting" << std::endl;
    test_friends();
    std::cout << "tests passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 1;
}