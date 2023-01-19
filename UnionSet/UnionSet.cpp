//
// Created by 86183 on 2023/1/19.
//

#include "UnionSet.h"

int UnionSet::find(int child) {
    if (array[child] == child) {
        return child;
    }
    int parent = array[child];
    array[child] = find(parent);
    return array[child];
}

void UnionSet::insert(int child, int parent) {
    int l = find(child);
    int r = find(parent);
    if (l == r) {
        return;
    }
    array[l] = r;
}

UnionSet::UnionSet() {
    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }
}
