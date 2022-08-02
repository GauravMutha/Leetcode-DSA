class Solution {
public:
    char findTheDifference(string s, string t) {
        int helper[26]={0},ans=0;
        for(int i=0;i<s.length();i++){
            helper[(s[i]-97)]++;
        }
        for(int i=0;i<t.length();i++){
            helper[(t[i]-97)]--;
        }
        for(ans=0;ans<26;ans++){
            if(helper[ans]!=0){
                break;
            }
        }
        return (char)(ans+97);
    }
};