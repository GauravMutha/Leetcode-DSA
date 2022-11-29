class Solution {
public:
    char checkSmaller(vector<int> &freq){
        for(int i=0;i<26;i++)
            if(freq[i]!=0) return 'a'+i;
        return 'a';
    }
    string robotWithString(string s) {
        string ans;
        stack<char>robo;
        vector<int>freq(26,0);
        for(auto c : s){
            freq[c-'a']++;
        }
        for(auto c:s){
            robo.push(c);
            freq[c-'a']--;
            while(!robo.empty() && robo.top()<=checkSmaller(freq)){
                char x=robo.top();
                robo.pop();
                ans.push_back(x);
            }
        }
        while(!robo.empty()){
            char x=robo.top();
            robo.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
//Just like previous solution but it uses stack robo instead of string robo
//sc-->O(N)
//tc-->O(N)