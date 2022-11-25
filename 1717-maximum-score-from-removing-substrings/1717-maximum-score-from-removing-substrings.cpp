class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st1,st2;
        char c1,c2;
        int ans=0,inc=0,i=0,k=0;
        if(x>y) c1='a' , c2='b' ,inc=x;
        else c1='b' , c2='a' , inc=y;
        
        //pass 1
        for(int j=0;j<s.size();i++,j++){
            s[i]=s[j];
            if(i>0 && s[i]==c2 && s[i-1]==c1) i-=2 , ans+=inc;
        }
        //pass 2
        s=s.substr(0,i);
        inc=(inc==x) ? y:x;
        for(int j=0;j<s.size();k++,j++){
            s[k]=s[j];
            if(k>0 && s[k]==c1 && s[k-1]==c2) k-=2 , ans+=inc;
        }
        return ans;
    } 
};