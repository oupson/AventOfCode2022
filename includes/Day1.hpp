//
// Created by oupson on 01/12/22.
//

#ifndef ADVENTOFCODE2022_DAY1_HPP
#define ADVENTOFCODE2022_DAY1_HPP


#include <Day.hpp>

#include <iostream>

class Day1 : public Day {
public:
    Day1() : Day(1) {
    }

private:
    void run_day(std::ifstream &stream) const override;
};


#endif //ADVENTOFCODE2022_DAY1_HPP
