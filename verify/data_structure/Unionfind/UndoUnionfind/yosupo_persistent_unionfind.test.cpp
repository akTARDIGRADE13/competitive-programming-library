#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "lib/data_structure/Unionfind/UndoUnionfind.hpp"

#include <array>
#include <iostream>
#include <vector>

using A = std::array<int, 4>;

int main() {
    int n, q;
    std::cin >> n >> q;
    akTARDIGRADE13::UndoUnionfind uf(n);
    std::vector<std::vector<A>> query(q);
    for(int i = 1; i <= q; ++i) {
        int t, k, u, v;
        std::cin >> t >> k >> u >> v;
        ++k;
        query[k].push_back(A{t, i, u, v});
    }
    std::vector<int> ans(q + 1, -1);
    auto dfs = [&](auto dfs, const A &inp) -> void {
        if(inp[0] <= 0) {
            if(inp[0] == 0)
                uf.merge(inp[2], inp[3]);
            for(auto &i : query[inp[1]])
                dfs(dfs, i);
            if(inp[0] == 0)
                uf.undo();
        } else {
            ans[inp[1]] = uf.same(inp[2], inp[3]);
        }
    };
    A sta = {-1, 0, -1, 0};
    dfs(dfs, sta);
    for(auto i : ans)
        if(i != -1)
            std::cout << i << std::endl;
    return 0;
}