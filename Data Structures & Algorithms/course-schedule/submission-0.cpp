class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &mp, unordered_set<int> &visiting, unordered_set<int> &visited, int vertex) {
        if (visiting.count(vertex)) return false;
        if (visited.count(vertex)) return true;

        visiting.insert(vertex);
        for (const auto &edge : mp[vertex]) {
            bool taken = dfs(mp, visiting, visited, edge);
            if (!taken) return false;
        }
        visiting.erase(vertex);
        visited.insert(vertex);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;

        unordered_map<int, vector<int>> mp;
        for (const auto &edge : prerequisites) {
            mp[edge[0]].push_back(edge[1]);
        }

        unordered_set<int> visited;
        unordered_set<int> visiting;

        for (int j = 0; j < numCourses; ++j) {
            bool taken = dfs(mp, visiting, visited, j);
            if (!taken) return false;
        }

        return true;
    }
};
