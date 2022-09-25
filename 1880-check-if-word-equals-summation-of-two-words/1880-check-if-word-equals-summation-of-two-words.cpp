class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1=0,num2=0,num3=0,sz1=firstWord.size(),sz2=secondWord.size(),sz3=targetWord.size();
        
        for(int i=0,j=0,k=0; i<sz1 || j<sz2 || k<sz3 ;){
            if(i<sz1)
                num1+=(firstWord[i]-'a')*pow(10,sz1-1-i++);
            if(j<sz2)
                num2+=(secondWord[j]-'a')*pow(10,sz2-1-j++);
            if(k<sz3)
                num3+=(targetWord[k]-'a')*pow(10,sz3-1-k++);
        }
        
        return (num1+num2)==num3;
    }
};