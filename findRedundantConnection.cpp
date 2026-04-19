//
// Created by A on 2026/4/19.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x]==x) return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            // 极其致命的发现：教父是同一个人！出现环了！
            return false;
        }

        // 吞并：让 X 的教父臣服于 Y 的教父
        parent[rootX] = rootY;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        //初始化parent集合
        parent.resize(n+1);
        for (int i=1;i<n+1;i++)
        {
            parent[i]=i;
        }
        for (auto& edge:edges)
        {
            if (!unite(edge[0],edge[1])) return edge;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{1,2}, {1,3}, {2,3}};
    vector<int> res1 = sol.findRedundantConnection(edges1);
    cout << "测试 1 (预期 2 3): " << res1[0] << " " << res1[1] << endl;

    return 0;
}