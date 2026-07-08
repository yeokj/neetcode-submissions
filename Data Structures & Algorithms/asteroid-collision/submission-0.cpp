class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> results;
        int absVal;
        bool collide;

        for (const auto &rock : asteroids) {
            if (rock < 0) {
                    absVal = -1 * rock;
                }
            else {
                absVal = rock;
            }
            collide = false;
            while (!results.empty()) {
                if (rock < 0 && results.back() < 0) {
                    results.push_back(rock);
                    break;
                }
                else if (rock < 0) {
                    if (absVal == results.back()) {
                        results.pop_back();
                        collide = true;
                        break;
                    }
                    else if (absVal > results.back()) {
                        results.pop_back();
                    }
                    else {
                        break;
                    }
                }
                else if (rock < 0 && absVal < results.back()) {
                    break;
                }
                else if (rock > 0 && results.back() > 0) {
                    results.push_back(rock);
                    break;
                }
                else if (rock > 0 && results.back() < 0) {
                    results.push_back(rock);
                    break;
                }
            }
            if (collide) continue;
            if (results.empty()) results.push_back(rock);
        }
        return results;
    }
};