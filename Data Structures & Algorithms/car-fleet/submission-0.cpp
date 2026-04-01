class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        stack<double> fleet;
        double time;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.first > b.first;
        });

        time = (double)(target - cars[0].first) / cars[0].second;
        fleet.push(time);

        for (int i = 1; i < n; i++) {
            time = (double)(target - cars[i].first) / cars[i].second;

            if (time > fleet.top()) {
                fleet.push(time);
            }
            else {
                continue;
            }
        }
        return fleet.size();
    }
};
