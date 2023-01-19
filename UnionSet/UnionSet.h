//
// Created by 86183 on 2023/1/19.
//

#ifndef UNIONSET_UNIONSET_H
#define UNIONSET_UNIONSET_H


class UnionSet {
public:
    UnionSet();

    int find(int child);

    void insert(int child, int parent);

private:
    int array[100];

};


#endif //UNIONSET_UNIONSET_H
