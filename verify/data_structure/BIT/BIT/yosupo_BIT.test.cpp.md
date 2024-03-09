---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/BIT/BIT.hpp
    title: BIT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 2 \"\
    lib/data_structure/BIT/BIT.hpp\"\n\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> struct BIT {\n    BIT() : n(0) {}\n    explicit BIT(int\
    \ _n) : n(_n + 1), vec(_n + 1, 0) {}\n\n    void add(int i, T x) {\n        ++i;\n\
    \        while(i < n) {\n            vec[i] += x;\n            i += i & (-i);\n\
    \        }\n    }\n\n    T sum(int i) {\n        T ret(0);\n        while(i >\
    \ 0) {\n            ret += vec[i];\n            i -= i & (-i);\n        }\n  \
    \      return ret;\n    }\n\n    T query(int l, int r) { return sum(r) - sum(l);\
    \ }\n\n    int binary_search(T x) {\n        int ret = 0, r = 1;\n        while(r\
    \ < n)\n            r = r << 1;\n        while(r > 0) {\n            if(ret +\
    \ r < n && vec[ret + r] < x) {\n                x -= vec[ret + r];\n         \
    \       ret += r;\n            }\n            r = r >> 1;\n        }\n       \
    \ return ret;\n    }\n\n  private:\n    int n;\n    std::vector<T> vec;\n};\n\n\
    }\n#line 4 \"verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    akTARDIGRADE13::BIT<long\
    \ long> bt(n);\n    for(int i = 0; i < n; ++i) {\n        int x;\n        std::cin\
    \ >> x;\n        bt.add(i, x);\n    }\n    while(q--) {\n        int t;\n    \
    \    std::cin >> t;\n        if(!t) {\n            int p, x;\n            std::cin\
    \ >> p >> x;\n            bt.add(p, x);\n        } else {\n            int l,\
    \ r;\n            std::cin >> l >> r;\n            std::cout << bt.query(l, r)\
    \ << std::endl;\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"lib/data_structure/BIT/BIT.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    akTARDIGRADE13::BIT<long long>\
    \ bt(n);\n    for(int i = 0; i < n; ++i) {\n        int x;\n        std::cin >>\
    \ x;\n        bt.add(i, x);\n    }\n    while(q--) {\n        int t;\n       \
    \ std::cin >> t;\n        if(!t) {\n            int p, x;\n            std::cin\
    \ >> p >> x;\n            bt.add(p, x);\n        } else {\n            int l,\
    \ r;\n            std::cin >> l >> r;\n            std::cout << bt.query(l, r)\
    \ << std::endl;\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - lib/data_structure/BIT/BIT.hpp
  isVerificationFile: true
  path: verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 02:38:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp
- /verify/verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp.html
title: verify/data_structure/BIT/BIT/yosupo_BIT.test.cpp
---
