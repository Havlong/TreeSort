/**
 * 10.03.2020
 * TreeSorter
 *
 * @author havlong
 * @version 1.0
 */

#ifndef TREESORT_MERGESORTER_H
#define TREESORT_MERGESORTER_H

#include <vector>

template<typename T>
class MergeSorter {
private:
    std::vector<T> toMerge;
    std::vector<T> toReturn;

    void merge(const int ql, const int qr) {
        int mid = (ql + qr) / 2;
        for (int l = ql, r = mid + 1, i = ql; l < mid && r < qr && i <= qr; ++i) {
            if (toMerge[l] < toMerge[r]) {
                toReturn[i] = toMerge[l];
                l++;
            } else {
                toReturn[i] = toMerge[r];
                r++;
            }
        }
    }

public:
    explicit MergeSorter(const std::vector<T> &origin) : toMerge(origin) {
        toReturn.resize(origin.size());
    }

    std::vector<T> sorted() {
        for (int step = 2; step < (int) toMerge.size(); step *= 2) {
            for (int i = 0; i < (int) toMerge.size(); ++i)
                toMerge[i] = toReturn[i];
            for (int ql = 0; ql < toMerge.size(); ql += step) {
                merge(ql, std::min(ql + step - 1, (int) toMerge.size() - 1));
            }
        }
        merge(0, toMerge.size() - 1);
        return toReturn;
    }
};

#endif //TREESORT_MERGESORTER_H
