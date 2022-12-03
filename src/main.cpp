#include <Day1.hpp>
#include <Day2.hpp>
#include "Day3.hpp"

template<class T>
void run() {
    T t;
    t.run();
}

int main() {
    run<Day1>();
    run<Day2>();
    run<Day3>();
    return 0;
}


