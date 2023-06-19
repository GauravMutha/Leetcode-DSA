class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign;
        long ans=0;
        
        /*trimming the leading whitespaces
        but we should npt trim leading zeroes
        because 0000-123 return 0 not -123*/
        while(i<s.size() && s[i]==' ') i++;
        s=s.substr(i);
        sign = (s[0]=='-') ? -1 : 1;
        
        /*Now taking sign into account above
        we now just start focusing on digits*/
        i=(s[0]=='-' || s[0]=='+') ? 1 : 0;
        
        for(;i<s.size();i++){
            /*since we have dealt with spaces
            and sign already , anyhting else now
            other than digit breaks the loop*/
            if(!isdigit(s[i])) break;
            ans=ans*10 + (s[i]-'0');
            if(sign==-1 && -1*ans < INT_MIN) return INT_MIN;
            if(sign==1 && ans > INT_MAX) return INT_MAX;
        }
        ans=sign*ans; //assigning the sign to our number
        return (int)(ans);
    }
};