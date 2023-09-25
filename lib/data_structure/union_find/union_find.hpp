#include <algorithm>
#include <vector>

namespace akTARDIGRADE13 {

struct Union_find {
 public:
  Union_find() : n(0), c(0) {}
  explicit Union_find(int _n) : n(_n), c(_n), par(_n, -1) {}

  int root(int x) {
    if (par[x] < 0) return x;
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
    if (x == y) return false;
    --c;
    if (par[x] > par[y]) std::swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  std::vector<std::vector<int>> groups() {
    std::vector<std::vector<int>> ret;
    std::vector<int> cnt(n), rec(n);
    for (int i = 0; i < n; ++i) {
      rec[i] = root(i);
      ++cnt[rec[i]];
    }
    for (int i = 0; i < n; ++i) {
      ret[i].reserve(cnt[i]);
    }
    for (int i = 0; i < n; ++i) {
      ret[rec[i]].push_back(i);
    }
    ret.erase(std::remove_if(
                  ret.begin(), ret.end(),
                  [&](const std::vector<int>& e) -> bool { return e.empty(); }),
              ret.end());
    return ret;
  }

 private:
  int n;
  int c;
  std::vector<int> par;
};

}  // namespace akTARDIGRADE13