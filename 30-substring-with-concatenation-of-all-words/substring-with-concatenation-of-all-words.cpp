class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        unordered_map<string,int> wordFreq;

        for(string w : words)
            wordFreq[w]++;

        for(int i = 0; i < wordLen; i++){

            int left = i;
            int count = 0;
            unordered_map<string,int> window;

            for(int j = i; j + wordLen <= s.size(); j += wordLen){

                string word = s.substr(j, wordLen);

                if(wordFreq.count(word)){

                    window[word]++;
                    count++;

                    while(window[word] > wordFreq[word]){
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == wordCount){
                        result.push_back(left);
                    }

                }
                else{
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};