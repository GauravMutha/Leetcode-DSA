class Solution {
public:
    int strStr(string h, string n) {
        int l=0,i=0,j=0;
        for(int i=0;i<h.size();i++){
            if(h[i]==n[j]){
                l=i;
                while(h[l]==n[j] && j<n.size() && i<h.size()) l++,j++;
                if(j==n.size()) return i;
                else j=0;
            }
        }
        return -1;
    }
};

//using brute force