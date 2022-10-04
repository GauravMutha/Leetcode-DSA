class Solution {
public:
    int minOperations(string s) {
        int count1=0,count2=0,n=s.size();
        string zero(n,'0'),one(n,'1');
        if(n==1) return 0;
        for(int i=1;i<n;i+=2){
            zero[i]='1';
            one[i]='0';
        }
        
        for(int i=0;i<n;i++){
            count1+=(s[i]!=zero[i]);
            count2+=(s[i]!=one[i]);
        }
        return min(count1,count2);
    }
};