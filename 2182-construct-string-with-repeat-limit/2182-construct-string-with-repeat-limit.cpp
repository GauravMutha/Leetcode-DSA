//USing ordered map
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        string res="";
        map<char,int ,greater<char>>m;
        int cnt=0,freq=0;
        char ch;
        for(auto &c : s) m[c]++;
        
        
        while(!m.empty()){
            ch=m.begin()->first , freq=m.begin()->second;
            m.erase(m.begin());
            cnt=0;
            while(freq>0){
                cnt++;
                if(cnt>limit){
                    if(m.empty()) return res;
                    res.push_back(m.begin()->first);
                    m.begin()->second--;
                    if(m.begin()->second==0) m.erase(m.begin());
                    cnt=1;
                }
                res.push_back(ch);
                freq--;
            }
        }
        
        return res;
    }
};