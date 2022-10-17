class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int j=0,n=s.size();
        
        for(int i=0;i<n;i++){
            if(i==0 || s[i]=='2'){
                for(j=max(j,i+minJump);j<=min(n-1,i+maxJump);j++){
                    if(s[j]=='0') s[j]='2';
                }
            }
        }
        return (s[n-1]=='2');
    }
};