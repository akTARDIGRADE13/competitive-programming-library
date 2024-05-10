---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/number-theory/AOJ.test.cpp
    title: verify/math/number-theory/AOJ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/number-theory/extGCD.hpp\"\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> T extgcd(T a, T b, T &x, T &y) {\n    T d = a;\n\
    \    if(b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) *\
    \ x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n\
    } // namespace akTARDIGRADE13\n"
  code: "#pragma once\n\nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> T extgcd(T\
    \ a, T b, T &x, T &y) {\n    T d = a;\n    if(b != 0) {\n        d = extgcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n   \
    \     y = 0;\n    }\n    return d;\n}\n\n} // namespace akTARDIGRADE13"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/number-theory/extGCD.hpp
  requiredBy: []
  timestamp: '2024-05-09 18:22:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/number-theory/AOJ.test.cpp
documentation_of: lib/math/number-theory/extGCD.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---

## 概要

拡張ユークリッドの互除法

## 使い方

- `extGCD<T>(T a, T b, T &x, T &y)`：$gcd(a, b)$ を返す．$x$ と $y$ には $ax+by=gcd(a,b)$ を満たす値が代入される．$|x|+|y|$ が最小となる値が代入される．計算量$\mathrm{O}(\log min(a, b))$
