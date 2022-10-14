class Solution {
public:
    int minswaps(string src,string dest){
        int i=0,j=0,res=0;
        while(i<dest.size()){
            j=i;
            while(src[j]!=dest[i]) j++;
            
            while(i<j){
                swap(src[j],src[j-1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
    int getMinSwaps(string num, int k) {
        int count=0,n=num.size(),l,r;
        string source=num;
        while(k--){
            for(l=n-2;l>=0;l--)
                if(num[l]<num[l+1]) break;
            for(r=n-1;r>l;r--)
                if(num[r]>num[l]) break;
            swap(num[r],num[l]);
            reverse(num.begin()+l+1,num.end());
        }
        return (minswaps(source,num));
    }
};