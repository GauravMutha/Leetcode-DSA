class Solution {
public:
    string addBinary(string a, string b) {
        int c=0,i=a.length()-1,j=b.length()-1;
        string s={};
        while(i>=0 || j>=0 || c==1){
            c+=(i>=0)?(a[i]-'0'):0;
            c+=(j>=0)?(b[j]-'0'):0;
            i--;j--;
            s+=c%2+'0';
            c/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};