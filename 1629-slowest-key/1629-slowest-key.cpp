class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int>hash(26);
        hash[keysPressed[0]-'a']=releaseTimes[0];
        int res=0;
        for(int i=1;i<releaseTimes.size();i++)
            hash[keysPressed[i]-'a']=max(hash[keysPressed[i]-'a'],releaseTimes[i]-releaseTimes[i-1]);
        
        res=max_element(hash.rbegin(), hash.rend())-hash.rbegin();
        return char(25-res+'a');    
    }
};