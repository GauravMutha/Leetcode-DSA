class Solution {
public:
    int numSplits(string s) {
        int res =0;
        int H=0,x=0,count=0;
        int n=s.size ();
        vector<int>prexor(n,0);
        vector<int>suffxor(n,0);
        for(int i=0;i<n;i++){
            x=1;
            x<<=(s[i]-97);
            if((H&x)==0){
                count++;
                H|=x;
            }
            prexor[i]=count;
        }
        H=0;count=0;
        for(int i=n-1;i>=0;i--){
            x=1;
            x<<=(s[i]-97);
            if((H&x)==0){
                count++;
                H|=x;
            }
            
            suffxor[i]=count;
        }
        for(int i=0;i<n-1;i++){
            if(prexor[i]==suffxor[i+1])
                res++;
        }
        return res;
    }
};