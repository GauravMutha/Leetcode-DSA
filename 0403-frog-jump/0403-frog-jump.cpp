//Memoization approach 2
class Solution {
public:
    map<pair<int,int>,bool>dp;
    int helper(int currPos,int prevJump,set<int>& st,int finalStone){
        if(st.find(currPos)==st.end() || currPos>finalStone) return false;
        if(currPos==finalStone) return true;
        
        if(dp.find({currPos,prevJump}) != dp.end()) return dp[{currPos,prevJump}];
        
        if(currPos==0) return dp[{currPos,prevJump}]=helper(currPos+1,1,st,finalStone);
        else {
            if(prevJump>1 && helper(currPos+prevJump-1,prevJump-1,st,finalStone)){
                return dp[{currPos,prevJump}]=true;
            }
            if(helper(currPos+prevJump,prevJump,st,finalStone))
                return dp[{currPos,prevJump}]=true;
            if(helper(currPos+prevJump+1,prevJump+1,st,finalStone)) 
                return dp[{currPos,prevJump}]=true;
        }
        return dp[{currPos,prevJump}]=false;

    }
    bool canCross(vector<int>& stones) {
        int finalStone=stones.back();
        set<int>st(stones.begin(),stones.end());
        return helper(0,1,st,finalStone);
    }
};