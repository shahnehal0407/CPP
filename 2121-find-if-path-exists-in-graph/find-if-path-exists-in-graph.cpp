class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>store(n);
        for(int i=0;i<edges.size();i++){
            store[edges[i][0]].push_back(edges[i][1]);
            store[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>visited(n,0);

        return dfs(source,destination,visited,store);

    }


   bool dfs(int source,int destination, vector<int>& visited, vector<vector<int>> & store){
    if(source==destination)return true;
    visited[source]=1;
    for(int i=0;i<store[source].size();i++){

        if(!visited[store[source][i]]){if (dfs(store[source][i],destination,visited,store)) return true;}
    }
    return false;
   }
};