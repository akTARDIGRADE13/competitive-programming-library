#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "lib/convolution/Convolution.hpp"
#include "lib/math/ModInt/mint.hpp"

using mint = akTARDIGRADE13::mint<998244353>;

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < m; ++i) std::cin >> b[i];
    akTARDIGRADE13::NTT<998244353> convolution;
    auto c = convolution.multiply(a, b);
    for(int i = 0; i < n + m - 1; ++i) {
        std::cout << c[i] << " \n"[i == n + m - 2];
    }

    return 0;
}