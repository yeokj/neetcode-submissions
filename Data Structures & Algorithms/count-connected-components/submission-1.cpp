class Solution {
private:
    void dfs(unordered_map<int, vector<int>> &adjList, unordered_set<int> &visited, int i) {
        if (visited.count(i)) return;
        visited.insert(i);

        for (const auto &node : adjList[i]) {
            dfs(adjList, visited, node);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        unordered_set<int> visited;
        int connect = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                dfs(adjList, visited, i);
                ++connect;
            }
        }
        return connect;
    }
};
