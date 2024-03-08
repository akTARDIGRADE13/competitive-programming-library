---
title: Unionfind
documentation_of: //lib/data_structure/Unionfind/Unionfind.hpp
---

## 概要

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

また，以下では，$\alpha(n)$はアッカーマン関数$A(n,n)$の逆関数とします．

## 使い方

- `Union_find(int n)`：サイズ$n$のunion_findを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y)`：「$x$の属する集合」と「$y$の属する集合」をマージする．返り値はマージに成功したら`true`，失敗したら`false`を返す．計算量$\mathrm{O}(\alpha(n))$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\alpha(n))$
- `size(int k)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\alpha(n))$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$