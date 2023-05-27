//Two pointers , odd even method
//O(n^2);
//Constant space
class Solution {
private:
public:
    int l=0,r=0,maxLen=-1;
    void palCheck(string &s,int j,int k){
        while(j>=0 && k<s.size()){
            if(s[j]!=s[k]) break;
            j-- , k++;
        }
        k--,j++;
        if((k-j+1)>maxLen)
            maxLen=k-j+1 , l=j , r=k;
        return;
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        for(int i=0;i<s.size();i++){
            if(i>0) palCheck(s,i-1,i+1); //odd palin check
            palCheck(s,i,i+1); //even palin check
        }
        return s.substr(l,r-l+1);
    }
};