//Brute force
class Solution {
public:
    int strStr(string hay, string needle) {
        int i=0,j=0,k=0;
        for(int i=0;i<hay.size();i++){
            if(hay[i]==needle[j]){
                k=i;
                while(hay[k]==needle[j] && k<hay.size() && j<needle.size())
                    j++,k++;
                if(j==needle.size()) return i;
                j=0;
            }
        }
        return -1;
    }
};