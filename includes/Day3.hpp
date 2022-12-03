//
// Created by oupson on 03/12/22.
//

#ifndef ADVENTOFCODE2022_DAY3_HPP
#define ADVENTOFCODE2022_DAY3_HPP


#include <Day.hpp>

class Day3 : public Day {
public:
    Day3() : Day(3) {
    }

private:
    void run_day(std::ifstream &stream) const override;
};

#endif //ADVENTOFCODE2022_DAY3_HPP
