class Solution {
public:

    int find(int x, vector<int>& store){
        if(store[x]==x)return x;
        return store[x]=find(store[x],store);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>store(n+1);
        for(int i=1;i<=n;i++){
            store[i]=i;
        }


        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];

            int c=find(a,store);
            int d= find(b,store);
            if(c==d)return edges[i];

            store[c]=d;
            
        }
        return {};
    }
};