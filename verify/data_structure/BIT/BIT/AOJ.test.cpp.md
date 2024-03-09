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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A
  bundledCode: "#line 1 \"verify/data_structure/BIT/BIT/AOJ.test.cpp\"\n#define PROBLEM\
    \                                                                \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A\"\
    \n\n#line 2 \"lib/data_structure/BIT/BIT.hpp\"\n\n#include <vector>\n\nnamespace\
    \ akTARDIGRADE13 {\n\ntemplate <typename T> struct BIT {\n    BIT() : n(0) {}\n\
    \    explicit BIT(int _n) : n(_n + 1), vec(_n + 1, 0) {}\n\n    void add(int i,\
    \ T x) {\n        ++i;\n        while(i < n) {\n            vec[i] += x;\n   \
    \         i += i & (-i);\n        }\n    }\n\n    T sum(int i) {\n        T ret(0);\n\
    \        while(i > 0) {\n            ret += vec[i];\n            i -= i & (-i);\n\
    \        }\n        return ret;\n    }\n\n    T query(int l, int r) { return sum(r)\
    \ - sum(l); }\n\n    int binary_search(T x) {\n        int ret = 0, r = 1;\n \
    \       while(r < n)\n            r = r << 1;\n        while(r > 0) {\n      \
    \      if(ret + r < n && vec[ret + r] < x) {\n                x -= vec[ret + r];\n\
    \                ret += r;\n            }\n            r = r >> 1;\n        }\n\
    \        return ret;\n    }\n\n  private:\n    int n;\n    std::vector<T> vec;\n\
    };\n\n}\n#line 5 \"verify/data_structure/BIT/BIT/AOJ.test.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#line 9 \"verify/data_structure/BIT/BIT/AOJ.test.cpp\"\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n   \
    \ for(int i = 0; i < n; ++i)\n        std::cin >> a[i];\n    std::sort(a.begin(),\
    \ a.end());\n    akTARDIGRADE13::BIT<int> bt(n);\n    bt.add(0, a[0]);\n    for(int\
    \ i = 1; i < n; ++i) {\n        bt.add(i, a[i] - a[i - 1]);\n    }\n    int q;\n\
    \    std::cin >> q;\n    while(q--) {\n        int k;\n        std::cin >> k;\n\
    \        int idx = bt.binary_search(k);\n        if(idx < n && bt.sum(idx+1) ==\
    \ k) {\n            std::cout << 1 << std::endl;\n        } else {\n         \
    \   std::cout << 0 << std::endl;\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/6/ITP2_6_A\"\
    \n\n#include \"lib/data_structure/BIT/BIT.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nint main() {\n    int n;\n    std::cin >> n;\n\
    \    std::vector<int> a(n);\n    for(int i = 0; i < n; ++i)\n        std::cin\
    \ >> a[i];\n    std::sort(a.begin(), a.end());\n    akTARDIGRADE13::BIT<int> bt(n);\n\
    \    bt.add(0, a[0]);\n    for(int i = 1; i < n; ++i) {\n        bt.add(i, a[i]\
    \ - a[i - 1]);\n    }\n    int q;\n    std::cin >> q;\n    while(q--) {\n    \
    \    int k;\n        std::cin >> k;\n        int idx = bt.binary_search(k);\n\
    \        if(idx < n && bt.sum(idx+1) == k) {\n            std::cout << 1 << std::endl;\n\
    \        } else {\n            std::cout << 0 << std::endl;\n        }\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - lib/data_structure/BIT/BIT.hpp
  isVerificationFile: true
  path: verify/data_structure/BIT/BIT/AOJ.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 03:30:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/BIT/BIT/AOJ.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/BIT/BIT/AOJ.test.cpp
- /verify/verify/data_structure/BIT/BIT/AOJ.test.cpp.html
title: verify/data_structure/BIT/BIT/AOJ.test.cpp
---
