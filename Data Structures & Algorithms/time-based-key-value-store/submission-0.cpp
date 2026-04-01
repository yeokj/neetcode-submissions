class TimeMap {
public:
unordered_map<string, vector<pair<string, int>>> tm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!tm.count(key)) {
            return "";
        }
        auto it = upper_bound(tm[key].begin(), tm[key].end(), timestamp,
            [](int t, const pair<string, int> &p) {
                return t < p.second;
        });
        if (it == tm[key].begin()) {
            return "";
        }
        else {
            --it;
        }
        
        return it->first;
    }
};
