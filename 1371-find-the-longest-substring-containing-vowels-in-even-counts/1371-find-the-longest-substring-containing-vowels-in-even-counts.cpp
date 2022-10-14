class Solution {
public:
    int charMap[26]={1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int findTheLongestSubstring(string s) {
        vector<int>freq(32,-1);
        int currMask=0,maxi=0;
        
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                currMask^=charMap[s[i]-'a'];
            }
            if(currMask!=0 && freq[currMask]==-1) freq[currMask]=i;
            
            maxi=max(maxi,i-freq[currMask]);
        }
        return maxi;
    }
};