#include <climits>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList; //pair of int and distance
        adjList.resize(n);
        for(int i = 0; i <times.size(); i ++){
            vector<int> cur = times[i];
            adjList[cur[0]-1].push_back({cur[1]-1,cur[2]});
        }

        //we have adj list in this format
        /*
            index 0: {1,1},{3,4}
            1: 2
            2: 3
            3:0
        */


        //djikstras

        int cur = k-1;

        bool done = false;
        vector<pair<int,int>> f(n,{-1,-1});
        f[cur].second = 0;
        vector<bool> visited(n, false);
        while(cur!=-1){
            //add a visited vector

            for(int i = 0;i < adjList[cur].size(); i++){
                int curInd = adjList[cur][i].first;
                int dist = adjList[cur][i].second+f[cur].second;
                if(f[curInd].second == -1 || f[curInd].second > dist){
                    f[curInd].second = dist;
                    f[curInd].first = cur;
                }
            }
            visited[cur]=true;
            int min = INT_MAX; 
            int minInd = -1;
            for(int i =0; i < n; i++){
                if(!visited[i] && f[i].second < min&& f[i].second!=-1){
                    min = f[i].second;
                    minInd = i;
                }
            }
            cur = minInd;
        }

        int max = -1;
        for(int i = 0; i < f.size(); i++){
            if(f[i].second ==-1){
                return -1;
            }
            max = std::max(f[i].second,max);
        }
        return max;

    }

    
};
