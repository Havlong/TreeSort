/**
 * 09.03.2020
 * TreeSorter
 * 
 * @author havlong 
 * @version 1.0
 */

#ifndef TREESORT_TREESORTER_H
#define TREESORT_TREESORTER_H

#include <vector>

template<typename T>
class TreeSorter {
private:
    std::vector<int> tree;
    const std::vector<T> &origin;

    void build(const int ql, const int qr, const int &pos = 1) {
        if (ql == qr) {
            tree[pos] = ql;
            return;
        }
        int mid = (ql + qr) / 2;
        build(ql, mid, pos * 2);
        build(mid + 1, qr, pos * 2 + 1);
        tree[pos] = origin[tree[pos * 2]] < origin[tree[pos * 2 + 1]] ? tree[pos * 2] : tree[pos * 2 + 1];
    }

    void remove(const int &i, const int ql, const int qr, const int &pos = 1) {
        if (ql == qr) {
            tree[pos] = -1;
            return;
        }
        int mid = (ql + qr) / 2;
        if (tree[pos * 2] == i) {
            remove(i, ql, mid, pos * 2);
        } else {
            remove(i, mid + 1, qr, pos * 2 + 1);
        }
        if (tree[pos * 2] == -1) {
            tree[pos] = tree[pos * 2 + 1];
        } else if (tree[pos * 2 + 1] == -1) {
            tree[pos] = tree[pos * 2];
        } else {
            tree[pos] = origin[tree[pos * 2]] < origin[tree[pos * 2 + 1]] ? tree[pos * 2] : tree[pos * 2 + 1];
        }
    }

public:
    explicit TreeSorter(const std::vector<T> &origin) : origin(origin) {
        int treeSize = 1; // Power of 2 required to contain all of the elements
        int originSize = origin.size() - 1;
        while (originSize) {
            originSize /= 2;
            treeSize *= 2;
        }
        tree.resize(treeSize * 2);
        build(0, origin.size() - 1);
    }

    std::vector<T> sorted() {
        std::vector<T> sorted;
        sorted.reserve(origin.size());
        for (int i = 0; i < origin.size(); ++i) {
            sorted.push_back(origin[tree[1]]);
            remove(tree[1], 0, origin.size() - 1);
        }
        return sorted;
    }
};


#endif //TREESORT_TREESORTER_H
