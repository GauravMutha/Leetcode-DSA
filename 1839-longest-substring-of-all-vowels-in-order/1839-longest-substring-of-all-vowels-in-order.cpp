class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxlen=0,len=1,count=1;
        
        for(int i=1;i<word.size();i++){
            if(word[i-1]==word[i])
                len++;
            else if(word[i-1]<word[i])
                count++,len++;
            else len=1,count=1;
            
            if(count==5) maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};