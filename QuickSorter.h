/**
 * 10.03.2020
 * QuickSorter
 *
 * @author havlong
 * @version 1.0
 */

#ifndef TREESORT_QUICKSORTER_H
#define TREESORT_QUICKSORTER_H

#include <random>
#include <vector>
#include <stack>
#include <chrono>

template<typename T>
class QuickSorter {
private:
    std::vector<T> toSort;
    std::mt19937 rnd;

    std::pair<int, int> split(const int ql, const int qr) {
        T element = toSort[ql + rnd() % (qr - ql + 1)];
        int i = ql, j = qr;
        while (i <= j) {
            while (toSort[i] < element) i++;
            while (toSort[j] > element) j--;
            if (i <= j)
                std::swap(toSort[i++], toSort[j--]);
        }
        return {i, j};
    }

public:
    explicit QuickSorter(const std::vector<T> &origin) : toSort(origin) {
        rnd = std::mt19937(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    }

    std::vector<T> sorted() {
        std::stack<std::pair<int, int>> s;
        s.push({0, toSort.size() - 1});
        while (!s.empty()) {
            std::pair<int, int> cur = s.top();
            s.pop();
            if (cur.first == cur.second)
                continue;
            std::pair<int, int> mid = split(cur.first, cur.second);
            if (mid.first < cur.second)
                s.push({mid.first, cur.second});
            if (cur.first < mid.second)
                s.push({cur.first, mid.second});
        }
        return toSort;
    }
};

#endif //TREESORT_QUICKSORTER_H
