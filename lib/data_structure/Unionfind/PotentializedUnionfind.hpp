#pragma once

#include <algorithm>
#include <functional>
#include <vector>

namespace akTARDIGRADE13 {

template <typename T> struct PotentializedUnionfind {
  public:
    PotentializedUnionfind() : n(0), c(0) {}
    explicit PotentializedUnionfind(int n, std::function<T(T, T)> _fx,
                                    std::function<T(T)> _inv, T _ex)
        : n(n), c(n), fx(_fx), inv(_inv) {
        parents.assign(n, -1);
        potential.assign(n, _ex);
    }

    bool merge(int x, int y, T w) {
        w += get_potential(x);
        w -= get_potential(y);
        x = root(x), y = root(y);

        if(x == y) {
            if(diff(x, y) == w) {
                return true;
            } else {
                return false;
            }
        }
        --c;

        if(parents[x] > parents[y])
            std::swap(x, y), w = inv(w);
        parents[x] += parents[y];
        parents[y] = x;
        potential[y] = w;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) {
        if(parents[x] < 0) {
            return x;
        } else {
            int r = root(parents[x]);
            potential[x] = fx(potential[x], potential[parents[x]]);
            return parents[x] = r;
        }
    }

    int count_group() { return c; }

    int size(int x) { return -parents[root(x)]; }

    T get_potential(int x) {
        root(x);
        return potential[x];
    }

    T diff(int x, int y) { return fx(get_potential(y), inv(get_potential(x))); }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(n);
        std::vector<int> cnt(n), roots(n);
        for(int i = 0; i < n; ++i) {
            roots[i] = root(i);
            ++cnt[roots[i]];
        }
        for(int i = 0; i < n; ++i)
            ret[i].reserve(cnt[i]);
        for(int i = 0; i < n; ++i)
            ret[roots[i]].push_back(i);
        ret.erase(
            remove_if(ret.begin(), ret.end(),
                      [&](const std::vector<int> &i) { return i.empty(); }),
            ret.end());
        return ret;
    }

  private:
    const int n;
    int c;
    std::vector<int> parents;
    std::vector<T> potential;
    std::function<T(T, T)> fx;
    std::function<T(T)> inv;
};

}