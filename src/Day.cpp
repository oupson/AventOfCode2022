//
// Created by oupson on 01/12/22.
//

#include "Day.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

#include <fmt/core.h>

Day::Day(int day_number) : day_number(day_number) {}

void Day::run() const {
    std::filesystem::path tmp_path("/tmp/advent-of-code");

    if (!(std::filesystem::exists(tmp_path) && std::filesystem::is_directory(tmp_path))) {
        std::filesystem::create_directory(tmp_path);
    }

    auto input_path = tmp_path / fmt::format("input-{}.txt", this->day_number);

    if (!exists(input_path)) {
        std::cerr << fmt::format("Please put input in {}", input_path.c_str()) << std::endl;
    }

    std::cout << fmt::format("===== running day {} =====", this->day_number) << std::endl;

    std::ifstream input(input_path);

    this->run_day(input);

    input.close();
}