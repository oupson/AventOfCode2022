//
// Created by oupson on 01/12/22.
//

#ifndef ADVENTOFCODE2022_DAY_HPP
#define ADVENTOFCODE2022_DAY_HPP

#include <iostream>

class Day {
public :
    explicit Day(int day_number);

    void run() const;

private:
    int day_number;

    virtual void run_day(std::ifstream& stream) const = 0;
};


#endif //ADVENTOFCODE2022_DAY_HPP
