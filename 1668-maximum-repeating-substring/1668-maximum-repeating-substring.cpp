class Solution {
public:
    int maxRepeating(string s, string w) {
        int count=0,res=0,n=s.size();

        for(int i=0,j=0,l=0;i<n;i++,l=0,j=0,count=0){
            while(i+j<n && s[i+j]==w[l]){
                l++ , j++;
                if(l==w.size()) l=0, count++;
            }
            res=max(count,res);
        }
        return res;
    }
};

//Brute force / Naive