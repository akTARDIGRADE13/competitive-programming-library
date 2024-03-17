#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "lib/data_structure/SegmentTree/Segtree.hpp"
#include "lib/math/ModInt/mint.hpp"

#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

using mint = akTARDIGRADE13::mint<998244353>;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<mint, mint>> vec(n);
    for(int i = 0; i < n; ++i)
        std::cin >> vec[i].first >> vec[i].second;
    auto fx = [](const std::pair<mint, mint> &lhs,
                 const std::pair<mint, mint> &rhs) -> std::pair<mint, mint> {
        return std::pair<mint, mint>(lhs.first * rhs.first,
                                     rhs.first * lhs.second + rhs.second);
    };
    std::pair<mint, mint> ex = std::pair<mint, mint>(1, 0);
    akTARDIGRADE13::Segtree<std::pair<mint, mint>> seg(n, fx, ex);
    seg.set_vec(vec);
    while(q--) {
        int t;
        std::cin >> t;
        if(t) {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto ret = seg.prod(l, r);
            std::cout << ret.first * x + ret.second << std::endl;
        } else {
            int p, c, d;
            std::cin >> p >> c >> d;
            seg.set(p, std::pair<mint, mint>(c, d));
        }
    }
    return 0;
}