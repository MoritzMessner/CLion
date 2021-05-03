//
// Created by moritz on 30.03.2021.
//
#include <iostream>
#include <cassert>
#include "Aufgabe3.h"
#include "Date.h"
#include "Person.h"

namespace AufgabeThree {


    void test_date() {
        Date xmas;
        xmas.init(2021, 12, 24);

        assert(xmas.get_day() == 24);
        assert(xmas.get_month() == 12);
        assert(xmas.get_year() == 2021);

        Date test_date;
        test_date.init(2050, 8, 14);

        assert(test_date.get_day() == 14);
        assert(test_date.get_month() == 8);
        assert(test_date.get_year() == 2050);

        Date falseDate;
        //falseDate.init(1912, 2, 30);
        falseDate.init(1912, 2, 28);
    }

    void swap(Person &a, Person &b) {
        Person tmp = a;
        a = b;
        b = tmp;
    }

    void sort(Person *persons, int length) {
        for (int i = 0; i < length; i++) {
            int swaps = 0;
            for (int j = 0; j < length - i - 1; j++) {
                if (persons[j + 1].compare(persons[j])) {
                    swap(persons[j], persons[j + 1]);
                    swaps = 1;
                }
            }
            if (!swaps)
                break;
        }
    }

    void test_person() {
        Person a;
        Date aBorn;
        aBorn.init(1913, 2, 28);
        a.init("Max", "a", aBorn);

        Person b;
        Date bBorn;
        bBorn.init(2020, 1, 2);
        b.init("Falscher", "b", bBorn);


        Person c;
        Date cBorn;
        cBorn.init(1996, 2, 1);
        c.init("Richtiger", "c", cBorn);

        assert(b.compare(a) == false);
        assert(c.compare(b) == false);
        assert(c.compare(a) == false);

        Person array[] = {c, b, a};
        //AufgabeThree::sort(array, 3);
        for (const auto &i : array) {
            std::cout << i.get_last_name() << std::endl;
        }

        AufgabeThree::sort(array, 3);

        for (const auto &i : array) {
            std::cout << i.get_last_name() << std::endl;
        }

    }
}

int main() {
    std::cout << "starting" << std::endl;
    AufgabeThree::test_date();
    AufgabeThree::test_person();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
}