#include <Day1.hpp>
#include <Day2.hpp>
#include <Day3.hpp>
#include <Day4.hpp>
#include <Day5.hpp>
#include <Day6.hpp>
#include <Day7.hpp>

template<class T>
void run() {
    T t;
    t.run();
}

int main() {
    run<Day1>();
    run<Day2>();
    run<Day3>();
    run<Day4>();
    run<Day5>();
    run<Day6>();
    run<Day7>();
    return 0;
}


