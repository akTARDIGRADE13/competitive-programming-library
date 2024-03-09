---
title: UndoUnionfind
documentation_of: //lib/data_structure/Unionfind/UndoUnionfind.hpp
---

## 概要

Undo付きUnionfindのライブラリ．

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

## 使い方

- `UndoUnionfind(int n)`：サイズ$n$のUnionfindを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y)`：「$x$の属する集合」と「$y$の属する集合」をマージする．返り値はマージに成功したらtrue，失敗したらfalseを返す．計算量$\mathrm{O}(\log n)$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\log n)$
- `size(int x)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\log n)$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `undo()`：1個前のmergeを無かったことにする．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$