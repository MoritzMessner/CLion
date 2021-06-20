//
// Created by moritz on 11.05.2021.
//

#include "Aufgabe8.h"
#include "../Aufgabe8/Date.h"
#include "../Aufgabe8/ArrayList.cpp"
#include "cassert"
#include <iostream>


typedef ArrayList<std::string> Friends;


namespace aufgabeAcht {


    bool find(int *array, int length, int key) {
        for (int i = 0; i < length; i++) {
            if (array[i] == key)
                return true;
        }
        return false;
    }


    template<typename T, typename T2>
    bool find(T *array, int length, const T2 &key) {
        for (int i = 0; i < length; i++) {
            if (array[i] == key)
                return true;
        }
        return false;
    }


    void test_find() {
        //a
        int array[] = {1, 2, 3, 4, 5, 6};
        assert(aufgabeAcht::find(array, 6, 4) == true);
        assert(aufgabeAcht::find(array, 6, 10) == false);

        //b
        std::string str_array[2] = {"Hallo", "Welt"};
        assert(aufgabeAcht::find(str_array, 2, "Welt") == true);
        assert(aufgabeAcht::find(str_array, 2, "Haus") == false);

        //c
        Date date1(2021, 1, 1);
        Date date2(2020, 12, 31);
        Date date3(2019, 12, 24);
        Date date4(1989, 11, 9);
        Date dates[] = {date1, date2, date3};
        for (auto date : dates) {
            assert(find(dates, 3, date));
        }
        assert(!find(dates, 3, date4));
    }


    void test_array_list() {

        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(friends[1] == "Daisy");

        std::string names1[2] = {"Op1", "Op2"};
        Friends friends1(names1, 2);
        auto friends2 = friends1;
        assert((friends1 == friends2) == true);
        assert((friends1 != friends2) == false);

        friends1.add("Hannes");
        assert((friends1 != friends2) == true);


    }
}

int main() {
    std::cout << "starting" << std::endl;
    aufgabeAcht::test_find();
    aufgabeAcht::test_array_list();
    std::cout << "tests passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 1;
}