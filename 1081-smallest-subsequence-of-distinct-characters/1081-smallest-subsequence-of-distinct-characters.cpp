class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        vector<bool>visit(26,false);
       string res;
        for(auto c:s)
            freq[c-'a']++;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            freq[c-'a']--;
            if(visit[c-'a']) continue;
            while(res.size() && res.back()>c && freq[res.back()-'a']>0)
                visit[res.back()-'a']=false , res.pop_back();
            res.push_back(c);
            visit[c-'a']=true;
        }
        return res;
    }
};

//2 pass
//SC--> O(1) NO STACK
//TC--> O(n)