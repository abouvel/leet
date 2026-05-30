class Solution {
public:
    int trap(vector<int>& height) {
        int maxL =height[0];
        int maxR = height[height.size()-1];
        int leftInd = 0;
        int rightInd= height.size()-1;
        int count = 0;
        int curInd = 0;
        while(leftInd< rightInd){
            if(maxL < maxR){
                leftInd++;
                count+= max(min(maxL,maxR)-height[leftInd],0);
                maxL = max(maxL, height[leftInd]);
            }else{
                rightInd--;
                count+= max(min(maxL,maxR)-height[rightInd],0);
                maxR = max(maxR, height[rightInd]);
            }
        
        }
        return count;


    }
    
};
