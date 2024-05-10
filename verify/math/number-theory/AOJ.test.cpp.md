---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/number-theory/extGCD.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"verify/math/number-theory/AOJ.test.cpp\"\n#define PROBLEM\
    \                                                                \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#line 2 \"lib/math/number-theory/extGCD.hpp\"\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> T extgcd(T a, T b, T &x, T &y) {\n    T d = a;\n\
    \    if(b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) *\
    \ x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n\
    } // namespace akTARDIGRADE13\n#line 5 \"verify/math/number-theory/AOJ.test.cpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\nint main()\
    \ {\n    int a, b, x, y;\n    std::cin >> a >> b;\n    akTARDIGRADE13::extgcd(a,\
    \ b, x, y);\n    std::cout << x << \" \" << y << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include \"lib/math/number-theory/extGCD.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nint main() {\n    int a, b, x, y;\n    std::cin\
    \ >> a >> b;\n    akTARDIGRADE13::extgcd(a, b, x, y);\n    std::cout << x << \"\
    \ \" << y << std::endl;\n    return 0;\n}"
  dependsOn:
  - lib/math/number-theory/extGCD.hpp
  isVerificationFile: true
  path: verify/math/number-theory/AOJ.test.cpp
  requiredBy: []
  timestamp: '2024-05-09 18:22:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/number-theory/AOJ.test.cpp
layout: document
redirect_from:
- /verify/verify/math/number-theory/AOJ.test.cpp
- /verify/verify/math/number-theory/AOJ.test.cpp.html
title: verify/math/number-theory/AOJ.test.cpp
---
