class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        vector<int>directh(words.size());
        int maxlen=0,prod=0;
        
        for(int i=0;i<words.size();i++)
            for(auto elem:words[i])
                directh[i]|=(1<<(elem-'a'));
        
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if((directh[i] & directh[j])==0){
                    prod=words[i].length() * words[j].length();
                    maxlen=max(maxlen,prod);
                }
            }
        }
        return maxlen;
    }
};