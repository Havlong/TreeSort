#include "TreeSorter.h"
#include "MergeSorter.h"
#include "QuickSorter.h"
#include "measurement.h"
#include <iostream>
#include <algorithm>

int main() {
    std::vector<long long> x(1000000);
    std::mt19937 rnd(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    for (auto &i: x) {
        i = rnd();
    }
    std::cout << measureAction([&]() {
        TreeSorter<long long> xSorter(x);
        auto result = xSorter.sorted();
        std::cout << (std::is_sorted(result.begin(), result.end()) ? "ok" : "error") << '\n';
    }) << "ms\n";
    std::cout << measureAction([&]() {
        MergeSorter<long long> xSorter(x);
        auto result = xSorter.sorted();
        std::cout << (std::is_sorted(result.begin(), result.end()) ? "ok" : "error") << '\n';
    }) << "ms\n";
    std::cout << measureAction([&]() {
        QuickSorter<long long> xSorter(x);
        auto result = xSorter.sorted();
        std::cout << (std::is_sorted(result.begin(), result.end()) ? "ok" : "error") << '\n';
    }) << "ms\n";
    return 0;
}
