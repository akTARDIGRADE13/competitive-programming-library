---
title: Segtree
documentation_of: //lib/data_structure/SegmentTree/Segtree.hpp
---

## 概要

抽象化された SegmentTree のライブラリ．

## 使い方

- `SegmentTree<T>(int n, function<T(T, T)> fx, T ex)`：サイズ$n$の SegmentTree を生成する．計算量$\mathrm{O}(n)$
- `set_vec(vector<T> vec)`：SegmentTree を$vec$で初期化する．計算量$\mathrm{O}(n)$
- `set(int i, T x)`：$i$番目(0-index)の要素に$x$を代入する．計算量$\mathrm{O}(\log n)$
- `prod(int l, int r)`：モノイドの性質を満たしていると仮定して，$[l, r)$の要素の総積を返す．計算量$\mathrm{O}(\log n)$
