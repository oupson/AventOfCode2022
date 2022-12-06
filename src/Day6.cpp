//
// Created by oupson on 06/12/22.
//

#include <Day6.hpp>

#include <fstream>
#include <fmt/core.h>
#include "MessageBuffer.hpp"

void Day6::run_day(std::ifstream &stream) const {
    char last_chars[4]{0, 0, 0, 0};
    stream >> last_chars[0];
    stream >> last_chars[1];
    stream >> last_chars[2];
    stream >> last_chars[3];

    MessageBuffer msg;

    int index = 4;
    int index_start = 0;
    int index_msg = 0;

    while (!stream.eof() && (index_start == 0 || index_msg == 0)) {
        bool a = false;
        for (int i = 0; i < 4 - 1; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (last_chars[i] == last_chars[j]) {
                    a = true;
                }
            }
        }

        if (index_msg == 0 && msg.detect()) {
            index_msg = index;
        }

        if (index_start == 0 && !a) {
            index_start = index;
        }

        last_chars[0] = last_chars[1];
        last_chars[1] = last_chars[2];
        last_chars[2] = last_chars[3];
        stream >> last_chars[3];

        msg.add_char(last_chars[3]);

        index += 1;
    }

    std::cout << "Part 1 : " << index_start << std::endl;
    std::cout << "Part 2 : " << index_msg << std::endl;

}