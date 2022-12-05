//
// Created by oupson on 05/12/22.
//

#include <Day5.hpp>

#include <fstream>
#include <fmt/core.h>
#include <vector>
#include <regex>

void Day5::run_day(std::ifstream &stream) const {
    std::vector<std::vector<char>> cargo;
    std::vector<std::vector<char>> cargo2;

    std::string line;

    while (std::getline(stream, line) && line[1] != '1') {
        int index = 0;
        while ((index * 4) < line.length()) {
            char c = line[(index * 4) + 1];
            if (cargo.size() == index) {
                cargo.emplace_back();
                cargo2.emplace_back();
            }

            if (c != ' ') {
                cargo[index].insert(cargo[index].begin(), c);
                cargo2[index].insert(cargo2[index].begin(), c);
            }
            index += 1;
        }
    }

    std::getline(stream, line);

    std::regex reg(R"(^move (\d+) from (\d) to (\d)$)");
    std::cmatch m;

    while (std::getline(stream, line) && !line.empty() && regex_search(line.c_str(), m, reg)) {
        int nbr_to_move = std::atoi(m[1].str().c_str());
        int from = std::atoi(m[2].str().c_str()) - 1;
        int to = std::atoi(m[3].str().c_str()) - 1;

        for (int j = 0; j < nbr_to_move; j++) {
            char c = cargo[from].back();
            cargo[to].push_back(c);
            cargo[from].pop_back();
        }

        for (int j = nbr_to_move; j < nbr_to_move; j++) {
            char c = cargo[from].back();
            cargo[to].push_back(c);
            cargo[from].pop_back();


        }

        auto ci = cargo2[from].size() - nbr_to_move;
        for (int j = 0; j < nbr_to_move; j++) {
            char c = cargo2[from][ci + j];
            cargo2[to].push_back(c);
        }

        cargo2[from].resize(ci);
    }

    std::cout << "Part 1 : ";
    for (auto &column: cargo) {
        std::cout << column.back();
    }

    std::cout << std::endl;

    std::cout << "Part 2 : ";
    for (auto &column: cargo2) {
        std::cout << column.back();
    }
    std::cout << std::endl;
}

void Day5::print_cargo(const std::vector<std::vector<char>> &cargo) const {
    size_t max_height = 0;
    for (auto &c: cargo) {
        if (cargo.size() > max_height) {
            max_height = cargo.size();
        }
    }

    for (int y = max_height - 1; y >= 0; y--) {
        for (int i = 0; i < cargo.size(); i++) {

            if (cargo[i].size() > y) {
                std::cout << "[" << cargo[i][y] << "] ";
            } else {
                std::cout << "    ";
            }
        }

        std::cout << std::endl;
    }
}
