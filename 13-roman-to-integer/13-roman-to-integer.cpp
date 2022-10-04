class Solution {
public:
    bool except(char i,char ip1){
        string temp=string()+i+ip1;
        return (temp=="IV" || temp=="IX" || temp=="XL" || temp=="XC" || temp=="CD" || temp=="CM");
    }
    
    int romanToInt(string s) {
        unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res=0;
        
        for(int i=0;i<s.size();i++)
            res+= (except(s[i],s[i+1])) ? (m[s[i]]*-1) : m[s[i]];
            
        return res;
    }
};