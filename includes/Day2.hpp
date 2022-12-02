//
// Created by oupson on 01/12/22.
//

#ifndef ADVENTOFCODE2022_DAY2_HPP
#define ADVENTOFCODE2022_DAY2_HPP


#include <Day.hpp>

#include <iostream>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

class Day2 : public Day {
public:
    Day2() : Day(2) {
    }

private:
    void run_day(std::ifstream &stream) const override;
};

int apply_strategy(char opponent, char action);
int loose_point(char opponent);
int win_point(char opponent);

#endif //ADVENTOFCODE2022_DAY2_HPP
