#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "lib/data_structure/Unionfind/UndoUnionfind.hpp"

#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    akTARDIGRADE13::UndoUnionfind uf(n);
    std::vector<std::vector<std::vector<int>>> query(q);
    for(int i = 0; i < q; ++i) {
        int t, k, u, v;
        std::cin >> t >> k >> u >> v;
        ++k;
        query[k].push_back(std::vector<int>{t, i, u, v});
    }
    std::vector<bool> ans(q, -1);
    auto dfs = [&](auto dfs, std::vector<int> inp) -> void {
        if(!inp[0]) {
            if(inp[0] == 0)
                uf.unite(a[2], a[3]);
            for(auto &i : query[inp[1]])
                dfs(dfs, i);
            if(inp[0] == 0)
                uf.undo();
        } else {
            ans[inp[1]] = uf.same(a[2], a[3]);
        }
    };
    dfs(dfs, std::vector<int>{-1, 0, -1, 0});
    for(auto i : ans)
        if(i != -1)
            std::cout << i << std::endl;
    return 0;
}