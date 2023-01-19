#include <iostream>
#include "UnionSet.h"

int main() {
    UnionSet *set = new UnionSet();

    set->insert(1, 2);
    set->insert(2, 3);
    set->insert(4, 5);

    std::cout << set->find(1) << std::endl;
    std::cout << set->find(4) << std::endl;
    return 0;
}
