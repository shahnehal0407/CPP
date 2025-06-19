class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int i = 0; i < hand.size(); i++) {
            count[hand[i]]++;
        }
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
            int card = it->first;
            int freq = it->second;

            if (freq > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }

        return true;
    }
};
