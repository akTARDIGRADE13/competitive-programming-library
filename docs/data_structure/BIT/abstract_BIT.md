---
title: abstract_BIT
documentation_of: //lib/data_structure/BIT/abstract_BIT.hpp
---

## 概要

抽象化されたBinary indexed tree(BIT, Fenwick tree)のライブラリ．

## 使い方

- `BIT<T>(int n, function<T(T, T)> fx, function<T(T)> inv, T ex)`：サイズ$n$のBITを生成する．計算量$\mathrm{O}(n)$
- `add(int i, T x)`：$i$番目(0-index)の要素に$x$を足す．計算量$\mathrm{O}(\log n)$
- `sum(int i)`：$[0, i)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `query(int l, int r)`：$[l, r)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `binary_search(T x)`：$sum(i-1)$が$x$以上となるような最小の$i$を返す．存在しない場合は$n$を返す．計算量$\mathrm{O}(\log n)$