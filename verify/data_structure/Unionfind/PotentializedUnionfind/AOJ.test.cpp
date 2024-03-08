#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "lib/data_structure/Unionfind/PotentializedUnionfind.hpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    auto fx = [](long long x, long long y)->long long{return x+y;};
    auto inv = [](long long x)->long long{return -x;};
    auto ex = 0;
    akTARDIGRADE13::PotentializedUnionfind<long long> uf(n, fx, inv, ex);
    while(q--) {
        int t;
        std::cin >> t;
        if(!t){
            int x, y, z;
            std::cin >> x >> y >> z;
            uf.merge(x, y, z);
        }else{
            int x, y;
            std::cin >> x >> y;
            if(uf.same(x, y)){
                std::cout << uf.diff(x, y) << std::endl;
            }else{
                std::cout << '?' << std::endl;
            }
        }
    }
    return 0;
}