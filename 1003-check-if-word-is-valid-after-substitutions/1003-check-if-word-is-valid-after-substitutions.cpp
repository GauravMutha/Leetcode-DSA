class Solution {
public:
    bool isValid(string s) {
        int i=0;
        for(int j=0;j<s.size();j++,i++){
            s[i]=s[j];
            if(s[j]=='c'){
                if(i<=1 || s[i-1]!='b' || s[i-2]!='a') return false;
                i-=3;
            }
        }
        i--;
        return (i<0);
    }
};
//Two pointers + No extra space
//SC-->O(1)
//TC--> O(n)