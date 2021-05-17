//
// Created by moritz on 20.04.2021.
//

#include "Aufgabe5.h"
#include "Date.h"
#include "Person.h"
#include "Friends.h"
#include <iostream>
#include <cassert>

namespace AufgabeFive {

    void test_person_date() {
        Date test_date(1992, 8, 16);
        Person a = Person("Gustav", "Hüha", test_date);
        assert(a.get_born().get_year() == 1992);
        assert(a.get_born().get_month() == 8);
        assert(a.get_born().get_day() == 16);
        test_date.set_year(2005);
        assert(a.get_born().get_year() == 1992);
        assert(a.get_born().get_month() == 8);
        assert(a.get_born().get_day() == 16);

        Date test_date_two = test_date;
        test_date.set_year(2020);
        assert(test_date_two.get_year() == 2005);
        assert(test_date_two.get_month() == 8);
        assert(test_date_two.get_day() == 16);

        Person b = a;
        assert(&a != &b);
        assert(b.get_born().get_year() == 1992);
        assert(b.get_born().get_month() == 8);
        assert(b.get_born().get_day() == 16);
    }


    void test_friends() {
        std::string names[] = {"Friedrich", "Olav", "Heinz"};
        ArrayList a(names, 3);
        assert(a.name(1) == "Olav");


/*
         // Hier wäre Kopierkunstruktor sinnvoll
         ArrayList b = a;
         a.set_name_on_position(1, "Willi");
         assert(a.name(1) == "Willi"); -> wahr
         assert(b.name(1) == "Willi"); -> wahr
         b.getNames();
 */
        ArrayList b = a;
        a.set_name_on_position(1, "Willi");
        assert(a.name(1) == "Willi"); // -> wahr
        assert(b.name(1) == "Olav"); // -> wahr


    }


    class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) : x(x), y(y) {}

        int getX() const {
            return x;
        }

        void setX(int _x) {
            Point::x = _x;
        }

        int getY() const {
            return y;
        }

        void setY(int _y) {
            Point::y = _y;
        }
    };


    class Segment {
        Point &p1, p2;
    public:
        Segment(Point &p1, Point &p2) : p1(p1), p2(p2) {}

        Point &getP1() const {
            return p1;
        }

        void setP1(Point &_p1) {
            Segment::p1 = _p1;
        }

        const Point &getP2() const {
            return p2;
        }

        void setP2(const Point &_p2) {
            Segment::p2 = _p2;
        }
    };


    void test_segment() {
        Point a(1, 2);
        Point b(3, 4);
        Segment seg(a, b);
        Segment seg2 = seg;

        assert(seg.getP1().getX() == 1);
        a.setX(10);
        assert(seg.getP1().getX() ==
               10); // sieht so aus, als müssten wir auch bei references einen Kopierkonstruktor bauen

        seg2.getP1().setX(2);
        assert(seg2.getP1().getX() == 2);
        std::cout << seg.getP1().getX() << "  " << seg2.getP1().getX() << std::endl;
    }
}

int main() {
    std::cout << "starting" << std::endl;
    AufgabeFive::test_person_date();
    std::cout << "test_person_date finished" << std::endl;
    AufgabeFive::test_friends();
    std::cout << "test_friends finished" << std::endl;

    AufgabeFive::test_segment();
    std::cout << "test_segment finished" << std::endl;

    std::cout << "tests passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 0;
}