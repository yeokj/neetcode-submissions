class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mp;
        for (const int &card : hand) ++mp[card];

        sort(hand.begin(), hand.end());
        for (int card : hand) {
            if (mp[card] == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                int currCard = card + i;
                if (mp[currCard] == 0) return false;
                if (mp[currCard] > 0) --mp[currCard];
            }
        }
        return true;
    }
};
