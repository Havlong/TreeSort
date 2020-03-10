/**
 * 09.03.2020
 * TreeSorter
 * 
 * @author havlong 
 * @version 2.0
 */

#ifndef TREESORT_TREESORTER_H
#define TREESORT_TREESORTER_H

#include <vector>

template<typename T>
class TreeSorter {
private:
    std::vector<int> tree;
    const std::vector<T> &origin;
    int treeSize;
    int originSize;

    void build() {
        for (int i = originSize - 1; i > 0; --i)
            tree[i] = origin[tree[i * 2]] < origin[tree[i * 2 + 1]] ? tree[i * 2] : tree[i * 2 + 1];
    }

    void remove(int i) {
        for (tree[i += originSize] = -1; i > 1; i /= 2) {
            if (tree[i] == -1)
                tree[i / 2] = tree[i ^ 1];
            else if (tree[i ^ 1] == -1)
                tree[i / 2] = tree[i];
            else
                tree[i / 2] = origin[tree[i]] < origin[tree[i ^ 1]] ? tree[i] : tree[i ^ 1];
        }
    }

public:
    explicit TreeSorter(const std::vector<T> &origin) : origin(origin) {
        originSize = origin.size();
        treeSize = originSize * 2;
        tree.resize(treeSize);
        for (int i = originSize; i < treeSize; ++i) {
            tree[i] = i - originSize;
        }
        build();
    }

    std::vector<T> sorted() {
        std::vector<T> sorted;
        sorted.reserve(origin.size());
        for (int i = 0; i < origin.size(); ++i) {
            sorted.push_back(origin[tree[1]]);
            remove(tree[1]);
        }
        return sorted;
    }
};


#endif //TREESORT_TREESORTER_H
