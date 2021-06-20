//
// Created by moritz on 01.06.2021.
//
#include <iostream>
#include <cassert>
#include <chrono>


namespace AufgabeTen {
    class Person {
    private:
        int id;
        std::string first_name;
        std::string last_name;
    public:
        Person(int id, std::string firstName, std::string lastName) : id(id), first_name(firstName),
                                                                      last_name(lastName) {}

        int getId() const {
            return id;
        }

        const std::string &getFirstName() const {
            return first_name;
        }

        const std::string &getLastName() const {
            return last_name;
        }


    };

    class Guest : public Person {
    private:
        int days;
        int room_rate;
    public:
        Guest(int id, const std::string &firstName, const std::string &lastName, int days, int roomRate) : Person(id,
                                                                                                                  firstName,
                                                                                                                  lastName),
                                                                                                           days(days),
                                                                                                           room_rate(
                                                                                                                   roomRate) {}

        int getDays() const {
            return days;
        }

        int getRoomRate() const {
            return room_rate;
        }

        int check() const {
            return days * room_rate;
        }
    };


    void test_guest() {
        // Jeder Guest IST Person

        // d
        Guest Hans(1, "Hans", "Wurst", 10, 1);
        assert(Hans.getId() == 1);
        assert(Hans.getFirstName() == "Hans");
        assert(Hans.getLastName() == "Wurst");
        assert(Hans.getDays() == 10);
        assert(Hans.getRoomRate() == 1);
        assert(Hans.check() == 10);


        // e
        // ja,
        Person a(2, "Peter", "Pan");
        a = Hans; // Zuweisung geht!
        // Jeder Gast ist eine Person, ich finde, dass es sinnvoll ist Guest von Person abzuleiten
    }

    class Employee : public Person {
    public:
        Employee(int id, std::string firstName, std::string lastName) : Person(id, firstName, lastName) {}

        int salary() const {
            return 0;
        }
    };

    class Worker : public Employee {
    private:
        int hourly_rate;
        int hours_worked;
    public:
        Worker(int id, std::string firstName, std::string lastName, int hourlyRate, int hoursWorked) : Employee(id,
                                                                                                                firstName,
                                                                                                                lastName),
                                                                                                       hourly_rate(
                                                                                                               hourlyRate),
                                                                                                       hours_worked(
                                                                                                               hoursWorked) {}

        int salary() const {
            return hourly_rate * hours_worked;
        }
    };


    class Seller : public Employee {
    private:
        int pay;
        int commission;

    public:
        Seller(int id, std::string firstName, std::string lastName, int pay, int commission) : Employee(id, firstName,
                                                                                                         lastName),
                                                                                                pay(pay), commission(
                        commission) {}

        int salary() const {
            return pay + commission;
        }
    };


    void test_person() {
        Employee employee(1, "Johannes", "Dreher");
        assert(employee.getId() == 1);
        assert(employee.getFirstName() == "Johannes");
        assert(employee.getLastName() == "Dreher");

        Worker worker(2, "Ralf", "Richtig", 12, 20);
        assert(worker.getId() == 2);
        assert(worker.getFirstName() == "Ralf");
        assert(worker.getLastName() == "Richtig");
        assert(worker.salary() == 240);

        Seller seller(3, "Peter", "Lustig", 200, 100);
        assert(seller.getId() == 3);
        assert(seller.getFirstName() == "Peter");
        assert(seller.getLastName() == "Lustig");
        assert(seller.salary() == 300);

        employee = worker;
        assert(employee.salary() == 0);

    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "starting ..." << std::endl;
    AufgabeTen::test_guest();
    AufgabeTen::test_person();
    std::cout << "tests passed ..." << std::endl;
    std::cout << "closing ..." << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
    return 1;
}
