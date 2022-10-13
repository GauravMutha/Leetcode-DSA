class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res=0;
        vector<int>freq((1<<10)+1,0);
        freq[0]=1;
        int count=0;
        for(int i=0;i<word.size();i++){
            int mask=1<<(word[i]-'a');
            count^=mask;
            
            res+=freq[count];
            
            int chmask=1;
            for(int j=1;j<=10;j++){
                res+=freq[count^chmask];
                chmask<<=1;
            }
            freq[count]++;
        }
        return res;
    }
};