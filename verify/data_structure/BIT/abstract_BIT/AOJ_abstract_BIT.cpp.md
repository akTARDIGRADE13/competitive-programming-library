---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/data_structure/BIT/abstract_BIT.hpp
    title: abstract_BIT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A
  bundledCode: "#line 1 \"verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A\"\
    \n\n#line 2 \"lib/data_structure/BIT/abstract_BIT.hpp\"\n\n#include <functional>\n\
    #include <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct\
    \ BIT {\n    BIT() : n(0) {}\n    explicit BIT(int _n, function<T(T, T)> _fx,\
    \ function<T(T)> _inv, T _ex)\n        : n(_n + 1), vec(_n + 1, 0), fx(_fx), inv(_inv),\
    \ ex(_ex) {}\n\n    void add(int i, T x) {\n        ++i;\n        while(i < n)\
    \ {\n            vec[i] = fx(vec[i], x);\n            i += i & (-i);\n       \
    \ }\n    }\n\n    T sum(int i) {\n        if(i == 0)\n            return 0;\n\
    \        T ret = ex;\n        while(i > 0) {\n            ret = fx(vec[i], ret);\n\
    \            i -= i & (-i);\n        }\n        return ret;\n    }\n\n    T query(int\
    \ l, int r) { return fx(sum(r), inv(sum(l))); }\n\n    int binary_search(T x)\
    \ {\n        int ret = 0, r = 1;\n        while(r < n)\n            r = r << 1;\n\
    \        while(r > 0) {\n            if(ret + r < n && vec[ret + r] < x) {\n \
    \               x = fx(x, rev(vec[ret + r]));\n                ret += r;\n   \
    \         }\n            r = r >> 1;\n        }\n        return ret;\n    }\n\n\
    \  private:\n    int n;\n    std::vector<T> vec;\n    std::function<T(T, T)> fx;\n\
    \    std::function<T(T)> inv;\n    const T ex;\n};\n\n}\n#line 5 \"verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp\"\
    \n\n#include <algorithm>\n#line 8 \"verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp\"\
    \n#include <iostream>\n#line 10 \"verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for(int i = 0; i < n; ++i)\n        std::cin >> a[i];\n    std::sort(a.begin(),\
    \ a.end());\n    auto fx = [](int x, int y)->int{return x+y;};\n    auto inv =\
    \ [](int x)->int{return -x;};\n    int ex = 0;\n    akTARDIGRADE13::BIT<int> bt(n,\
    \ fx, inv, ex);\n    bt.add(0, a[0]);\n    for(int i = 1; i < n; ++i) {\n    \
    \    bt.add(i, a[i] - a[i - 1]);\n    }\n    int q;\n    std::cin >> q;\n    while(q--)\
    \ {\n        int k;\n        std::cin >> k;\n        int idx = bt.binary_search(k);\n\
    \        if(idx < n && bt.sum(idx+1) == k) {\n            std::cout << 1 << std::endl;\n\
    \        } else {\n            std::cout << 0 << std::endl;\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A\"\
    \n\n#include \"lib/data_structure/BIT/abstract_BIT.hpp\"\n\n#include <algorithm>\n\
    #include <functional>\n#include <iostream>\n#include <vector>\n\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for(int i = 0;\
    \ i < n; ++i)\n        std::cin >> a[i];\n    std::sort(a.begin(), a.end());\n\
    \    auto fx = [](int x, int y)->int{return x+y;};\n    auto inv = [](int x)->int{return\
    \ -x;};\n    int ex = 0;\n    akTARDIGRADE13::BIT<int> bt(n, fx, inv, ex);\n \
    \   bt.add(0, a[0]);\n    for(int i = 1; i < n; ++i) {\n        bt.add(i, a[i]\
    \ - a[i - 1]);\n    }\n    int q;\n    std::cin >> q;\n    while(q--) {\n    \
    \    int k;\n        std::cin >> k;\n        int idx = bt.binary_search(k);\n\
    \        if(idx < n && bt.sum(idx+1) == k) {\n            std::cout << 1 << std::endl;\n\
    \        } else {\n            std::cout << 0 << std::endl;\n        }\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - lib/data_structure/BIT/abstract_BIT.hpp
  isVerificationFile: false
  path: verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp
  requiredBy: []
  timestamp: '2024-03-09 02:47:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp
layout: document
redirect_from:
- /library/verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp
- /library/verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp.html
title: verify/data_structure/BIT/abstract_BIT/AOJ_abstract_BIT.cpp
---
