class Solution {
public:
    int minWindowSubstr(string s,string str){
        vector<int>hash(26,0);
        int r=0,l=0,res=INT_MAX,n=str.size();
        for(auto c:str) hash[c-'A']++;
        
        while(r<s.size()){
            hash[s[r]-'A']--;
            if(hash[s[r]-'A']>=0) n--;
            r++;
            while(l<r && n==0){
                res=min(res,r-l);
                hash[s[l]-'A']++;
                if(hash[s[l]-'A']>0) n++;
                l++;
            }
        }
        return res;
    }
    int balancedString(string s) {
        unordered_map<char,int>freq;
        int len=s.size()/4;
        for(auto c :s) freq[c]++;
        
        string str="";
        for(auto it : freq){
            if(it.second>len) 
                str+=(string(it.second-len,it.first));
        }
        if(str.size()==0) return 0;
        return minWindowSubstr(s,str);
    }
};