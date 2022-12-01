//
// Created by oupson on 01/12/22.
//

#include <Day1.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include <fmt/core.h>

void Day1::run_day(std::ifstream &stream) const {
    std::string line;

    int sum = 0;
    int max = 0;
    int max2 = 0;
    int max3 = 0;

    while (std::getline(stream, line)) {
        if (line.empty()) {
            if (sum > max) {
                max3 = max2;
                max2 = max;
                max = sum;
            } else if (sum > max2) {
                max3 = max2;
                max2 = sum;
            } else if (sum > max3) {
                max3 = max;
            }

            sum = 0;
        } else {
            std::istringstream iss(line);
            int a = 0;

            iss >> a;

            sum += a;
        }
    }

    std::cout << fmt::format("Answer part 1 : {}", max) << std::endl;
    std::cout << fmt::format("Answer part 2 : {}", max + max2 + max3) << std::endl;
}
