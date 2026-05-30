class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) 
            return false;
        if(n <=1 && edges.size()==0)
            return true;
        vector<vector<int>> adjList;
        adjList.resize(n);

        for(vector<int> cur : edges){
            if(cur[0]==cur[1])
                return false;
            adjList[cur[0]].push_back(cur[1]);
            adjList[cur[1]].push_back(cur[0]);
        }
        vector<int> processed;
        processed.resize(n,0);
        bool stuff = true;
        
        if(!dfs(adjList,processed, 0, -1)){
            stuff = false;
        }
        for(int i :processed){
            if(i == 0){
                return false;
            }
        }
        return true;

    }

    bool dfs(vector<vector<int>> &adjList, vector<int> & processed, int ind, int parent){
        if(processed[ind]!= 0){
            return false;
        }
        if(adjList[ind].size()==0){
            return true;
        }
        processed[ind] = 1;
        for(int i = 0; i < adjList[ind].size(); i++){
            if(adjList[ind][i]==parent)
                continue;
            if(!dfs(adjList,processed, adjList[ind][i],ind)){
                return false;
            }
        }
        processed[ind]=2;
        return true;
    }
};
