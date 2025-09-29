class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for (int i=1;i<=n;i++) numbers.push_back(i);
        vector<int>fact(n+1,1);
        for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i;
        k--;
        string s="";


        for(int i=n;i>0;i--){
            int in=k/fact[i-1];
            k=k%fact[i-1];
           s += to_string(numbers[in]);
           numbers.erase(numbers.begin()+in);

        }

return s;
    }
};