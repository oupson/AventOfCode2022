//
// Created by oupson on 03/12/22.
//

#include <Day3.hpp>

#include <fstream>
#include <fmt/core.h>

int to_priority(char c) {
    if (c < 'a') {
        return c - 65 + 27;
    } else {
        return c - 96;
    }
}

char find_similar_char(std::string &s1, std::string &s2, std::string &s3) {
    for (char c: s1) {
        for (char c2: s2) {
            if (c == c2) {
                for (char c3: s3) {
                    if (c == c3) {
                        return c;
                    }
                }
            }
        }
    }
    return -1;
}

void Day3::run_day(std::ifstream &stream) const {
    std::string line;
    int sum = 0;
    int sum_part_2 = 0;

    int line_index = 0;
    std::string lines[3] = {"", "", ""};

    while (std::getline(stream, line)) {
        if (line.empty()) {
            break;
        }

        lines[line_index] = line;

        if (line_index == 2) {
            sum_part_2 += to_priority(
                    find_similar_char(lines[0], lines[1], lines[2])
            );
        }

        line_index = (line_index + 1) % 3;

        auto first_part = line.substr(0, line.length() / 2);
        auto second_part = line.substr(line.length() / 2, line.length() / 2);

        bool found = false;
        for (auto c: first_part) {
            for (auto c2: second_part) {
                if (c == c2) {
                    found = true;
                    sum += to_priority(c);
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }
    std::cout << fmt::format("Answer part 1 : {}", sum) << std::endl;
    std::cout << fmt::format("Answer part 2 : {}", sum_part_2) << std::endl;
}