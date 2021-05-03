//
// Created by moritz on 30.03.2021.
//
#include <iostream>
#include "Date.h"


int Date::validateDate(int _day) const {

    int checkDate;
    if (this->month == 2) {
        if ((this->year % 400 == 0) || (this->year % 4 == 0 && this->year % 100 != 0))
            checkDate = 29;
        else
            checkDate = 28;
    } else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 ||this->month == 10 || this->month == 12)
        checkDate = 31;
    else
        checkDate = 30;
    if (this->month > 12 || this->year < 0 || _day > checkDate)
        return false;
    return _day;
}

// so nicht! day()
Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(validateDate(_day)) {

}

int Date::get_year() const {
    return this->year;
}

int Date::get_month() const {
    return this->month;
}

int Date::get_day() const {
    return this->day;
}


