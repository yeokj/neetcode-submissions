class Solution {
private:
    bool dfs(vector<vector<int>> &edges, unordered_map<int, vector<int>> &adjList, unordered_set<int> &visited, int i, int parent) {
        if (visited.count(i)) return false;
        visited.insert(i);

        for (const auto &node : adjList[i]) {
            if (node == parent) continue;
            bool noCycle = dfs(edges, adjList, visited, node, i);
            if (!noCycle) return false;
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        unordered_set<int> visited;
        int connections;

        bool noCycle = dfs(edges, adjList, visited, 0, -1);
        if (noCycle && visited.size() == n) return true;

        return false;
    }
};
