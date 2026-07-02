class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (int i = 0; i < times.size(); ++i) {
            int source = times[i][0], destination = times[i][1], weight = times[i][2];
            adjList[source].push_back({destination, weight});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, 1e9);
    
        distance[k] = 0;
        pq.push({0, k});
    
        while (!pq.empty()) {
            int weightOne = pq.top().first, nodeOne = pq.top().second;
            pq.pop();

            if (weightOne > distance[nodeOne]) continue;
      
            for (const auto &node : adjList[nodeOne]) {
                int nodeTwo = node.first, weightTwo = node.second;
    
                if (weightOne + weightTwo < distance[nodeTwo]) {
                    distance[nodeTwo] = weightOne + weightTwo;
                    pq.push({distance[nodeTwo], nodeTwo});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == 1e9) return -1;
            result = max(result, distance[i]);
        }
        
        return result;
    }
};
