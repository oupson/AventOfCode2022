//
// Created by oupson on 01/12/22.
//

#include <Day2.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include <fmt/core.h>

void Day2::run_day(std::ifstream &stream) const {
    std::string line;

    int sum = 0;

    int sum_part_2;

    while (std::getline(stream, line)) {
        if (line.empty()) {
        } else {
            std::istringstream iss(line);
            char c1, c2;
            iss >> c1;

            iss >> c2;

            int point_shape = c2 - 87;

            int outcome = 3;

            if ((c1 - 64) != point_shape) {
                if (c1 == 'A') {  // ROCK
                    if (c2 == 'Z') {
                        outcome = 0;
                    } else {
                        outcome = 6;
                    }
                } else if (c1 == 'B') { // PAPER
                    if (c2 == 'X') {
                        outcome = 0;
                    } else {
                        outcome = 6;
                    }
                } else { // SCISSORS
                    if (c2 == 'Y') {
                        outcome = 0;
                    } else {
                        outcome = 6;
                    }
                }
            }
            sum += point_shape + outcome;

            sum_part_2 += apply_strategy(c1, c2);
        }
    }

    std::cout << fmt::format("Answer part 1 : {}", sum) << std::endl;
    std::cout << fmt::format("Answer part 2 : {}", sum_part_2) << std::endl;
}

int apply_strategy(char opponent, char action) {
    switch (action) {
        case 'X': // LOOSE
            return loose_point(opponent);
        case 'Y': // DRAW
            return 3 + opponent - 64;
        case 'Z': // WIN
            return 6 + win_point(opponent);
        default:
            std::cerr << "Unknown action " << action << std::endl;
    }
}

int loose_point(char opponent) {
    switch (opponent) {
        case 'A': // ROCK
            return SCISSORS;
        case 'B': // PAPER
            return ROCK;
        default: // SCISSORS
            return PAPER;
    }
}

int win_point(char opponent) {
    switch (opponent) {
        case 'A': // ROCK
            return PAPER;
        case 'B': // PAPER
            return SCISSORS;
        default: // SCISSORS
            return ROCK;
    }
}