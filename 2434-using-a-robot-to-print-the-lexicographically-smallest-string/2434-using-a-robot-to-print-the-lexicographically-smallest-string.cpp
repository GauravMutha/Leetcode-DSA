class Solution {
public:
    char checkSmaller(vector<int>freq){
        for(int i=0;i<26;i++)
            if(freq[i]!=0) return 'a'+i;
        return 'a';
    }
    string robotWithString(string s) {
        string ans,robo;
        vector<int>freq(26,0);
        for(auto c : s){
            freq[c-'a']++;
        }
        for(auto c:s){
            robo.push_back(c);
            freq[c-'a']--;
            while(robo.size() && robo.back()<=checkSmaller(freq)){
                char x=robo.back();
                robo.pop_back();
                ans.push_back(x);
            }
        }
        reverse(begin(robo),end(robo));
        ans.append(robo);
        return ans;
        return ""; 
    }
};

//sc-->O(N)
//tc-->O(N)