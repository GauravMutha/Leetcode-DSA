class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i=0,n=text.size(),count=0,flag=1;
        vector<bool>hash(26,false);
        for(auto c : brokenLetters) hash[c-'a']=true;
        for(int i=0;i<=n;i++){
            if((i==n) || (text[i]==' ')){
                count+=flag;
                flag=1;
            }
            else if(hash[text[i]-'a']) flag=0; 
        }
        
        return count;
    }
};