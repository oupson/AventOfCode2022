//
// Created by oupson on 08/12/22.
//

#ifndef ADVENTOFCODE2022_DAY8_HPP
#define ADVENTOFCODE2022_DAY8_HPP

#include <Day.hpp>

class Day8 : public Day {
public:
    Day8() : Day(8) {
    }

private:
    void run_day(std::ifstream &stream) const override;

    int part1(int n, int *grid) const;
    int part2(int n, const int *grid) const;

    int getInt(int n, const int *grid, int x, int y, int v) const;
};

#endif //ADVENTOFCODE2022_DAY8_HPP
