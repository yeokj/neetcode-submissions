class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;

        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList(numCourses);
        for (const auto &edge : prerequisites) {
            int a = edge[0], b = edge[1];
            adjList[b].push_back(a);
            ++indegree[a];
        }

        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (const auto &neighbor : adjList[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return topo.size() == numCourses;
    }
};
