#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "lib/math/number-theory/extGCD.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int a, b, x, y;
    std::cin >> a >> b;
    akTARDIGRADE13::extgcd(a, b, x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}