#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "lib/data_structure/BIT/range_BIT.hpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    akTARDIGRADE13::range_BIT<int> bt(n);
    while(q--) {
        int t;
        std::cin >> t;
        if(!t) {
            int l, r, x;
            std::cin >> l >> r >> x;
            bt.add(l, r, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << bt.query(l, r) << std::endl;
        }
    }
    return 0;
}