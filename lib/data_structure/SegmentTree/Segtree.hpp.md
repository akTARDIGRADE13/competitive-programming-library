---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
    title: verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/SegmentTree/Segtree.hpp\"\n\n#include\
    \ <cassert>\n#include <functional>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> struct Segtree {\n    explicit Segtree(int _n, std::function<T(T,\
    \ T)> _fx, T _ex)\n        : fx(_fx), ex(_ex) {\n        n = 1;\n        while(n\
    \ < _n)\n            n *= 2;\n        val.assign(n * 2, ex);\n    }\n\n    void\
    \ set_vec(std::vector<T> a) {\n        for(int i = 0; i < (int)a.size(); ++i)\n\
    \            val[i + n] = a[i];\n        for(int i = n - 1; i > 0; --i)\n    \
    \        val[i] = fx(val[i << 1], val[(i << 1) | 1]);\n    }\n\n    void set(int\
    \ i, T x) {\n        assert(i >= 0 && i < n);\n        i += n;\n        val[i]\
    \ = x;\n        i >>= 1;\n        while(i) {\n            val[i] = fx(val[i <<\
    \ 1], val[(i << 1) | 1]);\n            i >>= 1;\n        }\n    }\n\n    T prod(int\
    \ l, int r) {\n        assert(l >= 0 && r <= n && l <= r);\n        T vl = ex,\
    \ vr = ex;\n        l += n;\n        r += n;\n        while(l < r) {\n       \
    \     if(l & 1)\n                vl = fx(vl, val[l++]);\n            if(r & 1)\n\
    \                vr = fx(val[--r], vr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return fx(vl, vr);\n    }\n\n  private:\n    int n;\n\
    \    std::vector<T> val;\n    std::function<T(T, T)> fx;\n    const T ex;\n};\n\
    \n} // namespace akTARDIGRADE13\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\
    \nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct Segtree {\n    explicit\
    \ Segtree(int _n, std::function<T(T, T)> _fx, T _ex)\n        : fx(_fx), ex(_ex)\
    \ {\n        n = 1;\n        while(n < _n)\n            n *= 2;\n        val.assign(n\
    \ * 2, ex);\n    }\n\n    void set_vec(std::vector<T> a) {\n        for(int i\
    \ = 0; i < (int)a.size(); ++i)\n            val[i + n] = a[i];\n        for(int\
    \ i = n - 1; i > 0; --i)\n            val[i] = fx(val[i << 1], val[(i << 1) |\
    \ 1]);\n    }\n\n    void set(int i, T x) {\n        assert(i >= 0 && i < n);\n\
    \        i += n;\n        val[i] = x;\n        i >>= 1;\n        while(i) {\n\
    \            val[i] = fx(val[i << 1], val[(i << 1) | 1]);\n            i >>= 1;\n\
    \        }\n    }\n\n    T prod(int l, int r) {\n        assert(l >= 0 && r <=\
    \ n && l <= r);\n        T vl = ex, vr = ex;\n        l += n;\n        r += n;\n\
    \        while(l < r) {\n            if(l & 1)\n                vl = fx(vl, val[l++]);\n\
    \            if(r & 1)\n                vr = fx(val[--r], vr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return fx(vl, vr);\n    }\n\
    \n  private:\n    int n;\n    std::vector<T> val;\n    std::function<T(T, T)>\
    \ fx;\n    const T ex;\n};\n\n} // namespace akTARDIGRADE13"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/SegmentTree/Segtree.hpp
  requiredBy: []
  timestamp: '2024-03-17 10:08:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
documentation_of: lib/data_structure/SegmentTree/Segtree.hpp
layout: document
title: Segtree
---

## 概要

抽象化された SegmentTree のライブラリ．

## 使い方

- `SegmentTree<T>(int n, function<T(T, T)> fx, T ex)`：サイズ$n$の SegmentTree を生成する．計算量$\mathrm{O}(n)$
- `set_vec(vector<T> vec)`：SegmentTree を$vec$で初期化する．計算量$\mathrm{O}(n)$
- `set(int i, T x)`：$i$番目(0-index)の要素に$x$を代入する．計算量$\mathrm{O}(\log n)$
- `prod(int l, int r)`：モノイドの性質を満たしていると仮定して，$[l, r)$の要素の総積を返す．計算量$\mathrm{O}(\log n)$
