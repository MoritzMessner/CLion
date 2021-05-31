//
// Created by moritz on 18.05.2021.
//



#include <iostream>
#include<fstream>
#include <cassert>
#include <map>
#include <memory>
#include <chrono>
#include "Aufgabe9.h"

namespace aufgabeNine {


    std::string extract_airline(const std::string &row) {
        auto delimiter = row.find(('"'));
        auto substring = row.substr(delimiter + 1, row.size());
        delimiter = substring.find('"');
        substring = substring.substr(0, delimiter);
        return substring;
    }

    std::ifstream readfile(const std::string &filename) {
        std::ifstream input_file(filename);
        assert(input_file.is_open());
        return input_file;
    }


    void closeFile(std::ifstream &file) {
        file.close();
    }


    std::unique_ptr<std::map<std::string, int>> create_frequencies(const std::string &filename) {
        auto map = std::make_unique<std::map<std::string, int>>();
        auto file = readfile(filename);
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            //std::cout << "line => " << line << std::endl;
            //std::cout << "key => " << extract_airline(line) << std::endl;
            //map[extract_airline(line)] += 1;
            auto entety = map->find(extract_airline(line));
            if (entety != map->end()) {
                entety->second++;
            } else {
                map->insert(std::make_pair(extract_airline(line), 1));
            }
        }
        closeFile(file);
        return map;
    }


    void test_task_two() {
        std::string row_test_one = R"(2013,1,1,558,600,-2,924,917,7,"UA",194,"N29129","JFK","LAX",345,2475,6,0,2013-01-01 06:00:00)";
        assert(extract_airline(row_test_one) == "UA");

        std::string row_test_two = R"(2013,1,1,558,600,-2,849,851,-2,"B6",49,"N793JB","JFK","PBI",149,1028,6,0,2013-01-01 06:00:00)";
        assert(extract_airline(row_test_two) == "B6");

        std::string row_test_three = R"(2013,1,1,608,600,8,807,735,32,"MQ",3768,"N9EAMQ","EWR","ORD",139,719,6,0,2013-01-01 06:00:00)";
        assert(extract_airline(row_test_three) == "MQ");
    }

    void test_task_three() {
        std::string filename = "../Aufgabe9/flights.csv";
        auto airlines = aufgabeNine::create_frequencies(filename);
        //assert(airlines["AA"] = 32729);
        assert(airlines->find("AA")->second = 32729);
        int size = airlines->size();
        assert(size == 16);
    }

}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "starting ..." << std::endl;
    aufgabeNine::test_task_two();
    aufgabeNine::test_task_three();
    std::cout << "tests passed ..." << std::endl;
    std::cout << "closing ..." << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
    return 1;
}

