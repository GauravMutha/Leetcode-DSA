class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        vector<bool>visit(26,false);
        stack<char>st;
        for(auto c:s)
            freq[c-'a']++;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            freq[c-'a']--;
            if(visit[c-'a']) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0)
                visit[st.top()-'a']=false , st.pop();
            st.push(c);
            visit[c-'a']=true;
        }
        string res(st.size(),' ');
        for(int i=st.size()-1;i>=0;i--) res[i]=st.top(), st.pop();
        return res;
    }
};

//3 pass
//SC--> O(n) because of stack
//TC--> O(n)