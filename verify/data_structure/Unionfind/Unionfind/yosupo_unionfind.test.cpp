#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "lib/data_structure/Unionfind/Unionfind.hpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    akTARDIGRADE13::Unionfind uf(n);
    while(q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if(t == 0) {
            uf.merge(u, v);
        } else {
            std::cout << uf.same(u, v) << std::endl;
        }
    }
    return 0;
}