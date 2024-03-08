#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "lib/data_structure/BIT/range_BIT.hpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    akTARDIGRADE13::range_BIT<long long> bt(n);
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        bt.add(i, i + 1, x);
    }
    while(q--) {
        int t;
        std::cin >> t;
        if(!t) {
            int p, x;
            std::cin >> p >> x;
            bt.add(p, p + 1, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << bt.query(l, r) << std::endl;
        }
    }
    return 0;
}