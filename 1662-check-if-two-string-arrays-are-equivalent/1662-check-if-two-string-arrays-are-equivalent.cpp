class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        int ip1=0,ip2=0,op1=0,op2=0;
        
        while(op1<word1.size() && op2<word2.size()){
            s1=word1[op1] , s2=word2[op2];
            
            if(s1[ip1]!=s2[ip2]) return false;
            ip1++ , ip2++;
            
            if(ip1>=s1.size()) ip1=0 , op1++;
            if(ip2>=s2.size()) ip2=0 , op2++;
        }
        
        return (op1==word1.size() && op2==word2.size());
    }
};