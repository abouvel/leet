class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool first = false;
        bool last = false;
        for(int i = 0; i < wordList.size(); i++){
            first = first || wordList[i]==beginWord;
            last = last || wordList[i]==endWord;
        }
        if(!first){wordList.push_back(beginWord);}
        if(!last){return 0;}
        unordered_map<string, vector<string>> v;

        for(int i  =0; i < wordList.size(); i++){
            for(int c = 0; c< beginWord.size();c++){
                string temp= wordList[i];
                temp[c] = '*';
                v[temp].push_back(wordList[i]);
            }
        }
        unordered_map<string,vector<string>> adjList;
        for(auto it = v.begin(); it != v.end(); it++){
            vector<string> temp = it->second;
            if(temp.size()<=1){
                continue;
            }
            for(int i = 0; i < temp.size(); i++){
                for(int x = i+1; x < temp.size(); x++){
                    if(i!=x){
                        adjList[temp[i]].push_back(temp[x]);
                        adjList[temp[x]].push_back(temp[i]);
                    }
                }
            }
        }
        set<string> visited;
        //dfs implementation. Remember to exclude if key =value
        int val = dfs(adjList, beginWord, endWord, 1, 200, visited);
        return val !=200 ? val : 0;
        
    }
    int dfs(unordered_map<string,vector<string>> &adjList, string cur, string fin,int count, int min,set<string> & visited){
        vector<string> temp = adjList[cur];
        if(cur == fin){
            return count;
        }
        for(int i = 0; i < temp.size(); i++){
            if(temp[i]== cur|| visited.count(temp[i])>0)
                continue;
            visited.insert(temp[i]);
            min =(std::min(dfs(adjList, temp[i],fin,count+1, min, visited ),min));
            visited.erase(temp[i]);
        }
        return min;

    }
};
