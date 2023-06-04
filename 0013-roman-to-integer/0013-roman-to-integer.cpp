class Solution {
public:
    bool check(char c1 , char c2){
        if( (c1=='I' && c2=='V') || (c1=='I' && c2=='X') ||
            (c1=='X' && c2=='C') || (c1=='X' && c2=='L') ||
            (c1=='C' && c2=='D') || (c1=='C' && c2=='M') ) return true;
        return false;
    }
    int romanToInt(string s) {
        int sum=0,n=s.size();
        unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<n;i++){
            if(i==(n-1)) sum+=m[s[i]];
            else if(check(s[i],s[i+1])) sum-=m[s[i]];
            else sum+=m[s[i]];
        }
        return sum;
    }
};