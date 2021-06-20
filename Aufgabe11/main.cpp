//
// Created by moritz on 01.06.2021.
//
#include <iostream>
#include <cassert>
#include <chrono>
#include <memory>


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

    class Employee : public Person {
    public:
        Employee(int id, std::string firstName, std::string lastName) : Person(id, firstName, lastName) {}

        virtual ~Employee() {
        }

        virtual int salary() const {
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

        int salary() const override {
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

        int salary() const override {
            return pay + commission;
        }
    };

    // Aufgabe 1
    // Aufgabe 2
    // subklassen mit override gearbeitet
    // und in Employee mit virtual gearbeitet, Zahlen unten dann angepasst
    // Aufgabe 3
    // smart pointer
    void test() {
        //std::unique_ptr<Employee> employee(new Employee(4, "Duck", "Tick"));
        std::shared_ptr<Employee> employee(new Employee(4, "Duck", "Tick"));
        assert(employee->salary() == 0);
        //auto worker = new Worker(4, "Duck", "Tick", 9, 40);
        std::shared_ptr<Worker> worker(new Worker(4, "Duck", "Tick", 9, 40));
        employee = worker;
        assert(employee->salary() == 360);
        //auto seller = new Seller(5, "Duck", "Trick", 1000, 2000);
        std::shared_ptr<Seller> seller(new Seller(5, "Duck", "Trick", 1000, 2000));

        employee = seller;
        assert(employee->salary() == 3000);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "starting ..." << std::endl;
    AufgabeTen::test();
    std::cout << "tests passed ..." << std::endl;
    std::cout << "closing ..." << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
    return 1;
}
