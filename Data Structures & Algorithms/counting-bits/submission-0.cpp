class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count;
        for(int i= 0; i < n+1; i++){
            uint32_t iu = static_cast<uint32_t>(i);
            int counter = 0;
            while(iu){
                iu &= iu-1;
                counter++;
            }
            count.push_back(counter);
        }
        return count;
        
    }
};
