class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
       int m=max(firstWord.size(),max(secondWord.size(),targetWord.size()));
        int a=0,b=0,c=0,i=0;
        while(m)
        {
            if(i<firstWord.size())a=a*10+(firstWord[i]-97);
            if(i<secondWord.size())b=b*10+(secondWord[i]-97);
            if(i<targetWord.size())c=c*10+(targetWord[i]-97);
            m--;i++;
        }
      
        return ((a+b)==c);
    }
};