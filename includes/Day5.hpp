//
// Created by oupson on 05/12/22.
//

#ifndef ADVENTOFCODE2022_DAY5_HPP
#define ADVENTOFCODE2022_DAY5_HPP


#include <Day.hpp>
#include <vector>

class Day5 : public Day {
public:
    Day5() : Day(5) {
    }

private:
    void run_day(std::ifstream &stream) const override;

    void print_cargo(const std::vector<std::vector<char>> &cargo) const;
};

#endif //ADVENTOFCODE2022_DAY5_HPP
