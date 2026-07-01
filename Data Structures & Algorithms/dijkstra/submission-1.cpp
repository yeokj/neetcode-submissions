class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (int i = 0; i < edges.size(); ++i) {
            int source = edges[i][0], destination = edges[i][1], weight = edges[i][2];
            adjList[source].push_back({destination, weight});
        }
        
        unordered_map<int, int> results;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int weightOne = pq.top().first, nodeOne = pq.top().second;
            pq.pop();
            
            if (results.count(nodeOne)) continue;
            results[nodeOne] = weightOne;

            for (const auto &node : adjList[nodeOne]) {
                if (!results.count(node.first)) pq.push({node.second + weightOne, node.first});
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!results.count(i)) results[i] = -1;
        }

        return results;
    }
};
