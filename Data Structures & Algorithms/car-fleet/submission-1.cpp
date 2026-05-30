class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> s;
        int size = speed.size();

        vector<pair<int, int>> p;
        for(int i = 0; i< size; i++){
            p.push_back({position[i],speed[i]});
        }
        sort(p.begin(), p.end());
        if(size <=1){
            return size;
        }
        int answer= 0;
        
        s.push((target-p[size-1].first)/p[size-1].second);
        double longest = 0;
        for(int i = size-1; i >=0; i--){
            double time = (target- p[i].first)/(1.0*p[i].second);
            if(time > longest){
                answer++;
                longest = time;
            }
        }
        return answer;
    }
};
