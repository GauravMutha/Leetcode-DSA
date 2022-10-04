class Solution {
public:
    int minOperations(string s) {
        int count1=0,count2=0,n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                count1+=(s[i]=='0');
                count2+=(s[i]=='1');
            }
            else{
                count1+=(s[i]=='1');
                count2+=(s[i]=='0');
            }
        }
        return min(count1,count2);
    }
};