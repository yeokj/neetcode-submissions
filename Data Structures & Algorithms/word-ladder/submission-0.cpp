class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string currWord = q.front().first;
            int currLevel = q.front().second;
            q.pop();

            if (currWord == endWord) return currLevel;
            if (visited.count(currWord)) continue;
            visited.insert(currWord);

            for (int i = 0; i < currWord.length(); ++i) {
                char originalChar = currWord[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    currWord[i] = c;
                    if (wordSet.count(currWord) && !visited.count(currWord)) 
                        q.push({currWord, currLevel + 1});
                }
                currWord[i] = originalChar;
            }
        }
        return 0;
    }
};
