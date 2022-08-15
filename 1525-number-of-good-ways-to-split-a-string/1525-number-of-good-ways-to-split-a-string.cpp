class Solution {
public:
    int numSplits(string s) {
    int count=0;
    unordered_map<char,int> m;
    vector<int>prexor(s.size()); 
    vector<int>suffxor(s.size());
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
        prexor[i]=m.size();
    }
    m.clear();
    for(int i=s.size()-1;i>=0;i--){
        m[s[i]]++;
        suffxor[i]=m.size();
    }
    for(int i=0;i<s.size()-1;i++){
        if(prexor[i]==suffxor[i+1])
            count++;
       
}
        return count;
}
};

//TC--->O(n)
//SC--->O(n)