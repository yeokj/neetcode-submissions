class Solution {
private:
    bool dfs(unordered_map<int, vector<int>> &adjList, unordered_set<int> &visiting, unordered_set<int> &visited, vector<int> &v, int vertex) {
        if (visiting.count(vertex)) return false;
        if (visited.count(vertex)) return true;

        visiting.insert(vertex);
        for (const auto &edge : adjList[vertex]) {
            bool taken = dfs(adjList, visiting, visited, v, edge);
            if (!taken) return false;
        }

        visiting.erase(vertex);
        visited.insert(vertex);
        v.push_back(vertex);

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for (const auto &prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }
        
        unordered_set<int> visiting;
        unordered_set<int> visited;
        vector<int> results;

        for (int i = 0; i < numCourses; ++i) {
            bool taken = dfs(adjList, visiting, visited, results, i);
            if (!taken) return {};
        }

        return results;
    }
};
