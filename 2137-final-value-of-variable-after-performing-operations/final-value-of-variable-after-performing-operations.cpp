class Solution {
public:
    int finalValueAfterOperations(vector<string>& o) {
        int sum=0;
        for(int i=0;i<o.size();i++){
            sum+=(o[i][1]=='+')?1:-1;
        }
        return sum;
    }
};