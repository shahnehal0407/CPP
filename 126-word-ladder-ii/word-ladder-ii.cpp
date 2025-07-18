class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;

        if (!dict.count(endWord)) return results;

        unordered_map<string, int> level;
        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.length();
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                string original = word;

                for (int j = 0; j < wordLen; ++j) {
                    char oldChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (!dict.count(word)) continue;

                        if (!level.count(word)) {
                            level[word] = level[original] + 1;
                            q.push(word);
                            visitedThisLevel.insert(word);
                        }

                        if (level[word] == level[original] + 1)
                            parent[word].push_back(original);

                        if (word == endWord) found = true;
                    }
                    word[j] = oldChar;
                }
            }

            for (const string& w : visitedThisLevel)
                dict.erase(w);
        }

        if (!parent.count(endWord)) return results;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parent, path, results);
        return results;
    }

    void backtrack(string word, const string& beginWord,
                   unordered_map<string, vector<string>>& parent,
                   vector<string>& path, vector<vector<string>>& results) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            results.push_back(temp);
            return;
        }

        for (const string& p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parent, path, results);
            path.pop_back();
        }
    }
};
