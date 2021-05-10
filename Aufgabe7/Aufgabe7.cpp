//
// Created by moritz on 04.05.2021.
//

#include "Aufgabe7.h"
#include "./Friends.h"
#include "Vector.cpp"
#include <iostream>
#include <cassert>
#include <sstream>

void test_Vector() {
    auto v = Vector3D(1, 1, 1);
    std::cout << v.getX() << std::endl;


    /* b.)
     *
     Aus der VL
     Definieren Sie einen eigenen Destruktor und einen eigenen Kopierkonstruktor für Klassen, die dynamische Attribute enthalten
     Es gilt die berühmte Dreierregel:
     Wenn man
        •einen Kopierkonstruktor oder
        •einen Zuweisungsoperator oder
        •einen Destruktor
    benötigt, dann benötigt man vermutlich alle drei!


     In der Klasse Vektor haben wir keine Dynamischen Attribute deswegen, mit den Ihnalten aus der VL, sage ich, dass man keine von den Genannten braucht
    */
    auto m = v;
    assert(m.getX() == v.getX() && m.getY() == v.getY() && m.getZ() == v.getZ());

    // c.
    // +
    auto x = m + v;
    assert(x.getX() == (v.getX() + m.getX()) && x.getY() == (v.getY() + m.getY()) && x.getZ() == (v.getZ() + m.getZ()));
    auto y = 2 + m;
    assert(y.getX() == (m.getX() + 2) && y.getY() == (m.getY() + 2) && y.getZ() == (m.getZ() + 2));
    auto z = m + 2;
    assert(z.getX() == (m.getX() + 2) && z.getY() == (m.getY() + 2) && z.getZ() == (m.getZ() + 2));

    // -
    auto x1 = v - m;
    assert(x1.getX() == (v.getX() - m.getX()) && x1.getY() == (v.getY() - m.getY()) &&
           x1.getZ() == (v.getZ() - m.getZ()));
    auto y1 = 2 - m;
    assert(y1.getX() == (2 - m.getX()) && y1.getY() == (2 - m.getY()) && y1.getZ() == (2 - m.getZ()));
    //auto z1 = m - 2;
    //assert(z1.getX() == (m.getX() - 2) && z1.getY() == (m.getY() - 2) && z1.getZ() == (m.getZ() - 2));

    // <<
    std::cout << v << std::endl;
    //assert((std::cout<< v) == "x: 1 y: 1 z: 1");



    // d.
    Vector3D n(2, 4, 6);
    auto test = n * 2;
    assert(test.getX() == 4 && test.getY() == 8 && test.getZ() == 12);
    auto test2 = 2 * n;
    assert(test2.getX() == 4 && test2.getY() == 8 && test2.getZ() == 12);
    auto nn = n * n;
    assert(nn == 56);
}

void test_2() {
    std::string pString[2] = {"Hans", "Gustav"};
    Friends a(pString, 2);
    std::cout << a << std::endl;
}

int main() {
    std::cout << "starting" << std::endl;
    test_Vector();
    test_2();
    std::cout << "tests passed" << std::endl;
    std::cout << "terminating ..." << std::endl;
    return 1;
}