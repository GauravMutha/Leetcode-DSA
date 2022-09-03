class Solution {
public:
    int numSteps(string s) {
        int res=0;
        while(s.back()=='0'){
            s.erase(s.size()-1);
            res++;
        }
        if(s.size()==1)return res;
        calc(s,res);
        return res;
    }
    
    void calc(string str,int &res){
        if(str.size()==1)return;
        
        int pos=str.rfind('0');
        
        if(pos==string::npos){
            res+=(str.size()+1);
            return;
        }
        str[pos]='1';
        res+=(str.size()-pos);
        str=str.substr(0,pos+1);
        calc(str,res);
    }
};