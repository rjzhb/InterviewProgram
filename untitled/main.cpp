#include <iostream>
#include <vector>

using namespace std;

int find(int target, vector<int> test) {
    int l = -1, r = test.size();

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (test[mid] > target) {
            r = mid;
        } else if (test[mid] == target) {
            return mid;
        } else {
            l = mid;
        }
    }

    return -1;
}


int find_2(int target, vector<int> test) {
    int l = -1, r = test.size();

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (test[mid] >= target) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (r == test.size())return -1;

    return test[r] == target ? r : -1;
}


int main() {
    vector<int> test({2, 5, 7, 13, 22, 89, 102});
    vector<int> test_2({2, 5, 7, 13, 22, 89, 102, 500});

    std::cout << find(89, test) << std::endl;
    std::cout << find(3, test) << std::endl;

    std::cout << "--------------" << std::endl;
    std::cout << find(500, test_2) << std::endl;
    return 0;
}
