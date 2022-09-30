class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word=" "+searchWord;
        string sent=" "+sentence;
        
        int pos=sent.find(word);
        
        if(pos!=string::npos)
            return count(begin(sent),begin(sent)+pos+1,' ');
        
        return -1;
    }
};