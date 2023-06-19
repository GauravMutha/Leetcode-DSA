class Solution {
public:
    bool breakout(char c,int sign,string& dig,string &zeroes){
        return (c=='.' || isalpha(c) ||
                ((dig.size()>0 || zeroes.size()>0 || sign!=-1) && c==' ') ||
                ((c=='-' || c=='+') && (sign!=-1 || dig.size()>0 || zeroes.size()>0)) );
    }
    int myAtoi(string s) {
        string dig="",zeroes="";
        int sign=-1;
        double res=0;
        
        for(auto c :s){
            if(breakout(c,sign,dig,zeroes))
                break;
            else if(c!=' '){
                if(c=='+') sign=1;
                else if(c=='-') sign=0;
                else if(isdigit(c)) (c=='0' && dig.size()==0)?zeroes.push_back(c):dig.push_back(c); 
                if(dig.size()>10) return (sign==0)?INT_MIN:INT_MAX; 
            }
        }
        
        if(dig.size()==0) return 0;
        
        for(auto d:dig)
            res=res*10.0 + (double)(d-'0');
        if(sign==0) res=-1.0*res;
        
        if(res>INT_MAX) return INT_MAX;
        else if(res<INT_MIN) return INT_MIN;
        return res;
    }
};