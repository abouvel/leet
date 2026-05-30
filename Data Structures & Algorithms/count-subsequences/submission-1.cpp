class Solution {
public:
    int numDistinct(string s, string t) {
        // caaat and cat

        // aaat and at

        // aat t, at t, t t

        // 3
        if(t.size() >s.size()){
            return 0;
        }
        //we could just use recursion if we want it to be o(mn) time
        //we will use dp
        vector<vector<int>> dist(s.size(),vector<int>(t.size(), -1));

        return recurs(dist, s, t, 0, 0);


    }

    int recurs(vector<vector<int>> &dist, string &s, string &t, int sInd, int tInd){
        if(tInd == t.size()){
            return 1;
        }
        else if(sInd == s.size()){
            return 0;
        }
        
        if(dist[sInd][tInd] !=-1){
            return dist[sInd][tInd];
        }
        
        else if(s[sInd]!= t[tInd]){
            dist[sInd][tInd] = recurs(dist, s, t, sInd+1, tInd);
        }else{
            dist[sInd][tInd] = recurs(dist, s, t, sInd+1, tInd) + recurs(dist, s, t, sInd+1, tInd+1) ;
        }
        return dist[sInd][tInd];

    }
};
