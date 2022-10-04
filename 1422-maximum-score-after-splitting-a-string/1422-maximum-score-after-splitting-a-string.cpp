class Solution {
public:
    int maxScore(string s) {
        int ans=0,left=0,score=0,right=count(begin(s),end(s),'1');
        
        for(int i=0;i<s.size()-1;i++){
            (s[i]=='0')?left++:right--;
            score=left+right;
            ans=max(score,ans);
        }
        
        return ans;
    }
};