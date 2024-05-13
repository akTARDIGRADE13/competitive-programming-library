---
title: 拡張ユークリッドの互除法
documentation_of: //lib/math/number-theory/extGCD.hpp
---

## 概要

拡張ユークリッドの互除法

## 使い方

- `extGCD<T>(T a, T b, T &x, T &y)`：$gcd(a, b)$ を返す．$x$ と $y$ には $ax+by=gcd(a,b)$ を満たす値が代入される．$abs(x)+abs(y)$ が最小となる値が代入される．計算量$\mathrm{O}(\log min(a, b))$
