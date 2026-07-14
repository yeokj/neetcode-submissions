class Solution {
private:
    bool dfs(unordered_map<int, vector<int>> &adjList, unordered_set<int> &visited, int u, int v) {
        if (u == v) return true;
        if (visited.count(u)) return false;
        visited.insert(u);

        for (const auto &node :adjList[u]) {
            bool exist = dfs(adjList, visited, node, v);
            if (exist) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            unordered_set<int> visited;
            bool exist = dfs(adjList, visited, u, v);
            if (exist) return {u, v};
            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        
        return {};
    }
};
