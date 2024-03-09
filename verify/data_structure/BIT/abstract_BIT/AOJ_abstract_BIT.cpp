#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A"

#include "lib/data_structure/BIT/abstract_BIT.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    auto fx = [](int x, int y)->int{return x+y;};
    auto inv = [](int x)->int{return -x;};
    int ex = 0;
    akTARDIGRADE13::BIT<int> bt(n, fx, inv, ex);
    bt.add(0, a[0]);
    for(int i = 1; i < n; ++i) {
        bt.add(i, a[i] - a[i - 1]);
    }
    int q;
    std::cin >> q;
    while(q--) {
        int k;
        std::cin >> k;
        int idx = bt.binary_search(k);
        if(idx < n && bt.sum(idx+1) == k) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}