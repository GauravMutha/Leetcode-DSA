class Solution {
public:
    
    string parse(string& s){
        int dompos=s.find('@');
        string local,domain=s.substr(dompos);
        
        for(int i=0;i<dompos;i++){
            if(s[i]=='+') break;
            else if(s[i]!='.') local+=s[i];
        }
        
        return (local+domain);
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>uset;
        for(auto email :emails)
            uset.insert(parse(email));
        
        return (uset.size());
    }
};