class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence=" " + sentence;
        int ptr,count=0;
        for(int i=1;i<sentence.size();i++){
            if((sentence[i-1]==' ') && ((i+searchWord.size()-1)<sentence.size())){
                ptr=i , count++;
                string res=sentence.substr(ptr,searchWord.size());
                if(res==searchWord) return count;
            }
        }
        return -1;
    }
};