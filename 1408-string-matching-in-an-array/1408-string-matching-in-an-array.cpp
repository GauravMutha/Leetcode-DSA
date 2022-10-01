class Solution {
public:
    
    void lpsmaker(string patt , vector<int>& lps){
        int n=patt.size(),len=0,i=1;
        
        while(i<n){
            if(patt[i]==patt[len]){
                lps[i]=len+1;
                i++, len++;
            }
            else{
                if(len!=0)
                    len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    
    bool kmp(string patt, string text){
        int i=0,j=0,m=text.size(),n=patt.size();
        vector<int>lps(n);
        
        lpsmaker(patt,lps);
        
        while(i<text.size()){
            if(text[i]==patt[j])
                i++, j++;
            else{
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
            if(j==n) return true;
        }
        return false;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string>res;
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(words[i]==words[j]) continue;
                if(kmp(words[i],words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};