#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "lib/math/ModInt/d_mint.hpp"

#include <iostream>
#include <vector>

using mint = akTARDIGRADE13::d_mint<-1>;

long long kai[10000000];

int main() {
    int t, m;
    std::cin >> t >> m;
    mint s;
    mint::set_mod(m);
    kai[0] = 1;
    for(int i = 1; i < 10000000; ++i) {
        kai[i] = kai[i - 1] * i % m;
    }
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        if(n < k) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << mint(kai[n]) / mint(kai[n - k]) / mint(kai[k])
                      << std::endl;
        }
    }
    return 0;
}