class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int>hash;
        int j=0;
        for(int i=0;i<number.size();i++)
            if(number[i]==digit) hash.push_back(i);
        
        for(j=0;j<hash.size()-1;j++)
            if(number[hash[j]+1]>number[hash[j]]) return number.substr(0,hash[j])+number.substr(hash[j]+1);
        
        return number.substr(0,hash.back()) + number.substr(hash.back()+1);
    
    }
};