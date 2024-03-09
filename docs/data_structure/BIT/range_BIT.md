---
title: range_BIT
documentation_of: //lib/data_structure/BIT/range_BIT.hpp
---

## 概要

区間加算Binary indexed tree(BIT, Fenwick tree)のライブラリ．

## 使い方

- `range_BIT<T>(int n)`：サイズ$n$のBITを生成する．計算量$\mathrm{O}(n)$
- `add(int l, int r, T x)`：$[0, i)$の要素に$x$を足す．計算量$\mathrm{O}(\log n)$
- `sum(int i)`：$[0, i)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `query(int l, int r)`：$[l, r)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$