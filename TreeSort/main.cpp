#include<bits/stdc++.h>

using namespace std;

void print(std::vector<int> example) {
    for (auto it: example) {
        cout << it << " ";
    }
    cout << endl;
}

void heapify(int n, std::vector<int> &example, int pos) {
    int largest = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    if (left < n && example[left] > example[largest]) largest = left;
    if (right < n && example[right] > example[largest]) largest = right;
    if (largest != pos) {
        std::swap(example[largest], example[pos]);
    }
    print(example);
}

void heap_sort(std::vector<int> &example) {
    int len = example.size();
    //建堆
    for (int i = example.size() / 2 - 1; i >= 0; i--) {
        heapify(example.size(), example, i);
    }

    for (int i = len - 1; i > 0; i--) {
        std::swap(example[0], example[i]);
        heapify(i, example, 0);
    }
}


int main() {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heap_sort(a);
    return 0;
}