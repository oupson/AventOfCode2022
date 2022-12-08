//
// Created by oupson on 08/12/22.
//

#include <Day8.hpp>
#include <fstream>
#include <cstring>
#include <fmt/core.h>

void Day8::run_day(std::ifstream &stream) const {
    std::string line;

    std::getline(stream, line);

    int n = line.size();

    int grid[n][n];

    int yindex = 0;
    do {
        for (int i = 0; i < line.size(); i++) {
            grid[yindex][i] = line[i] - 48;
        }

        yindex += 1;
    } while (std::getline(stream, line) && !line.empty());

    auto grid_to_edit = (int *) std::malloc(n * n * sizeof(int));
    std::memcpy(grid_to_edit, grid, n * n * sizeof(int));
    int part1 = this->part1(n, grid_to_edit);

    std::cout << "Part 1 : " << part1 << std::endl;

    // 352512 to low
    int part2 = this->part2(n, (int *) grid);
    std::cout << "Part 2 : " << part2 << std::endl;
}

int Day8::part1(int n, int *grid) const {
    for (int x = 1; x < n - 1; x++) {
        for (int y = 1; y < n - 1; y++) {
            int v = grid[y * n + x];

            {
                int y1 = 0;
                while (y1 < y) {
                    if (v <= grid[y1 * n + x]) {
                        break;
                    }
                    y1 += 1;
                }

                if (y1 == y) {
                    continue;
                }

                y1 = y + 1;
                while (y1 < n) {
                    if (v <= grid[y1 * n + x]) {
                        break;
                    }
                    y1 += 1;
                }

                if (y1 == n) {
                    continue;
                }
            }
            // X

            {
                int x1 = 0;
                while (x1 < x) {
                    if (v <= grid[y * n + x1]) {
                        break;
                    }
                    x1 += 1;
                }

                if (x1 == x) {
                    continue;
                }

                x1 = x + 1;
                while (x1 < n) {
                    if (v <= grid[y * n + x1]) {
                        break;
                    }
                    x1 += 1;
                }

                if (x1 == n) {
                    continue;
                }
            }

            grid[y * n + x] = -1;
        }
    }

    int sum = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (grid[y * n + x] >= 0) {
                sum += 1;
            }
        }
    }
    return sum;
}

int Day8::part2(int n, const int *grid) const {
    int m = 0;

    for (int y = 1; y < n - 1; y++) {
        for (int x = 1; x < n - 1; x++) {
            int v = grid[y * n + x];

            int total = getInt(n, grid, x, y, v);

            if (m < total) {
                m = total;
            }
        }
    }

    return m;
}

int Day8::getInt(int n, const int *grid, int x, int y, int v) const {
    int up = 1, down = 1, left = 1, right = 1;

    while (up < (y) && v > grid[(y - up) * n + x]) {
        up += 1;
    }

    while (down < (n - y - 1) && v > grid[(y + down) * n + x]) {
        down += 1;
    }

    while (left < (x) && v > grid[y * n + (x - left)]) {
        left += 1;
    }

    while (right < (n - x - 1) && v > grid[y * n + (x + right)]) {
        right += 1;
    }

    int total = up * down * left * right;
    return total;
}
