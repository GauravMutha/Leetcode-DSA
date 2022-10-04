class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int curr=0,pow=1,res=0;
        
        for(int n=num;n>0;n/=10){
            curr+=(n%10)*pow;
            if(--k>0)
                pow*=10;
            else{
                res+=(curr && (num%curr==0));
                curr/=10;
            }
        }
        return res;
    }
};