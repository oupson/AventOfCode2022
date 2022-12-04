//
// Created by oupson on 03/12/22.
//

#include <Day4.hpp>

#include <fstream>
#include <fmt/core.h>
#include <regex>

void Day4::run_day(std::ifstream &stream) const {
    std::string line;
    int sum = 0;
    int sum_part_2 = 0;

    std::regex reg(R"(^(\d+)-(\d+),(\d+)-(\d+)$)");
    std::cmatch m;

    while (std::getline(stream, line)) {
        if (regex_search(line.c_str(), m, reg)) {
            int min_first = std::atoi(m[1].str().c_str());
            int max_first = std::atoi(m[2].str().c_str());

            int min_second = std::atoi(m[3].str().c_str());
            int max_second = std::atoi(m[4].str().c_str());

            if (min_first <= min_second && max_first >= max_second ||
                min_second <= min_first && max_second >= max_first) {
                sum += 1;
            }

            if (min_first >= min_second && min_first <= max_second ||
                max_first >= min_second && max_first <= max_second ||
                min_second >= min_first && min_second <= max_first ||
                min_second >= min_first && max_second <= max_first) {
                sum_part_2 += 1;
            }
        }
    }
    std::cout << fmt::format("Answer part 1 : {}", sum) << std::endl;
    std::cout << fmt::format("Answer part 2 : {}", sum_part_2) << std::endl;
}