class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence=" "+sentence;
        string res="";
        int i=1,r=0,count=0;
        while(i<sentence.size()){
            r=i,count++, res="";
            while((sentence[r]!=' ') && (r<sentence.size())){
                res+=sentence[r];
                r++;
                if(res==searchWord) return count;
            }
            if(r==sentence.size()) break;
            if(sentence[r]==' ') i=r+1;
        }
        
        return -1;
    }
};