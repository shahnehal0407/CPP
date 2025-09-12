class Solution {
public:
    int totalFruit(vector<int>& store) {
        unordered_map<int, int>fruits;
        
        int i=0;
       
        int maxi=0;
     for(int j=0;j<store.size();j++){
        fruits[store[j]]++;
        while(fruits.size()>2){
            fruits[store[i]]--;
            if(fruits[store[i]]==0)fruits.erase(store[i]);
            i++;
        }
        
        maxi=max(maxi,j-i+1);
     }
     

        return maxi;
    }
};