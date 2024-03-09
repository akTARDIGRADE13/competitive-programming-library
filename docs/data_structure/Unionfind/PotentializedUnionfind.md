---
title: PotentializedUnionfind
documentation_of: //lib/data_structure/Unionfind/PotentializedUnionfind.hpp
---

## 概要

ポテンシャル付き（重み付き）Unionfind のライブラリ．

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

## 使い方

- `Unionfind<T>(int n, function<T(T, T)> fx, function<T(T)> inv, T ex)`：サイズ$n$のUnionfindを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y, T z)`：$x$に対する$y$のポテンシャルが$+z$となるようにマージする
．返り値はマージに成功したらtrue，失敗したらfalseを返す．矛盾する場合もfalseを返す．計算量$\mathrm{O}(\log n)$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\log n)$
- `size(int x)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\log n)$
- `diff(int x, int y)`：$x$に対する$y$のポテンシャルを返す．$x$と$y$が連結していない場合は無意味な値が返ってくるので注意．計算量$\mathrm{O}(\log n)$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$