class Solution {
public:
    int secondHighest(string s) {
        int l=0,r=0;
        vector<int>hash(10,-1);
        for(int i=0;i<s.size();i++)
            if(isdigit(s[i])){
                int val=s[i]-'0';
                hash[9-val]=val;
            }
        l=std::max_element(hash.begin(),hash.end()) - hash.begin();
        r=l+1;
        while(r<10){
            if(hash[r]!=-1 && hash[r]<hash[l]) return hash[r];
            r++;
        }
        
        return -1;
    }
};