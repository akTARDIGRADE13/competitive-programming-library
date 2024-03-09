#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace akTARDIGRADE13 {

struct Unionfind {
  public:
    Unionfind() : n(0), c(0) {}
    explicit Unionfind(int _n) : n(_n), c(_n), par(_n, -1) {}

    int root(int x) {
        assert(x >= 0 && x < n);
        if(par[x] < 0)
            return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        x = root(x), y = root(y);
        return x == y;
    }

    int count_group() { return c; }

    int size(int x) {
        x = root(x);
        return -par[x];
    }

    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y)
            return false;
        --c;
        if(par[x] > par[y])
            std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(n);
        for(int i = 0; i < n; ++i) {
            ret[root(i)].emplace_back(i);
        }
        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<int> &e) -> bool {
                                     return e.empty();
                                 }),
                  ret.end());
        return ret;
    }

  private:
    int n;
    int c;
    std::vector<int> par;
};

}