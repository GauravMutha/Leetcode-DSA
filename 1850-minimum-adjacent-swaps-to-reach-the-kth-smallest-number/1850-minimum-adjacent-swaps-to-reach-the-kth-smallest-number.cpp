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
            next_permutation(begin(num),end(num));
        }
        return (minswaps(source,num));
    }
};

//now using stl function next_permutation