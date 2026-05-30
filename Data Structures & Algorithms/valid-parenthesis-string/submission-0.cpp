class Solution {
public:
    bool checkValidString(string s) {
        // ( is 1 and ) is -1

        return checkStuff(s, 0,0);

    }
    bool checkStuff(string &s, int count, int ind){
            if(ind == s.size()){
                return count ==0;
            }
            if(s[ind] == '(' && count>=0){
                return checkStuff(s, count+1, ind+1);
            }else if (s[ind] == ')' && count>0){
                return checkStuff(s, count-1, ind+1);
            }else if(s[ind] == '*'){ 
                return checkStuff(s, count+1, ind+1) || checkStuff(s, count-1, ind+1) ||checkStuff(s, count, ind+1);
            }
            return false;
        }
    
};
