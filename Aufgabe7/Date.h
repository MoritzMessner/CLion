//
// Created by moritz on 30.03.2021.
//

#ifndef CLION_DATE_H
#define CLION_DATE_H


class Date {
private:

    int year;
    int month;
    int day;

    int validateDate() const;

public:
    Date(int _year, int _month, int _day);


    int get_year() const;

    int get_month() const;

    int get_day() const;

    int validateDate(int _day) const;

    void set_year(int _year);
};


#endif //CLION_DATE_H
