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
        // Secon Option: Use 2 pointers where the first loop is i, and the second loop is j
        // if prev val and curr val are the same, continue. else, decrement the value from the map, and increment group value
    }
};
