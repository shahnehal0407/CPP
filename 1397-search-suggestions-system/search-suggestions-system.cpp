class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        vector<vector<string>>ans;
        for(int i=1;i<=searchWord.size();i++){
            string s=searchWord.substr(0,i);
            vector<string>temp;
            for(int j=0;j<products.size();j++){
                if(products[j].find(s)==0){
                    temp.push_back(products[j]);

                }
                 }
                sort(temp.begin(),temp.end());

            vector<string>curr;
            for (int k = 0; k < temp.size() && k < 3; k++)curr.push_back(temp[k]);
           
                ans.push_back(curr);
            }

        return ans;
    }
};