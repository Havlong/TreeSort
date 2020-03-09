#include <random>
#include <iostream>
#include <algorithm>
#include "TreeSorter.h"
#include "measurement.h"

int main() {
    std::vector<long long> x(1000000);
    std::mt19937 rnd(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    for(auto &i: x) {
        i = rnd();
    }
    std::cout << measureAction([&](){
        TreeSorter<long long> xSorter(x);
        auto result = xSorter.sorted();
        std::cout << (std::is_sorted(result.begin(), result.end()) ? "ok" : "error") << '\n';
    }) << "ms\n";
    return 0;
}
