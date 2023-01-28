typedef pair<int,char> p;
class Solution {
public:
    string reorganizeString(string s) {
        char prev='#';
        vector<int>hash(26,0);
        priority_queue<p>maxh;
        for(auto &c : s) hash[c-'a']++;
        for(int i=0;i<26;i++) if(hash[i]) maxh.push({hash[i],i+'a'});
        
        int i=0;
        while(!maxh.empty()){
            auto [cnt1,c1]=maxh.top(); maxh.pop();
            if(prev==c1){
                if(maxh.empty()) return "";
                auto [cnt2,c2]=maxh.top(); maxh.pop();
                s[i++]=c2;
                prev=c2;
                maxh.push({ cnt1, c1 });
                cnt2--;
                if(cnt2>0) maxh.push({cnt2,c2});
            }
            else{
                prev=c1;
                s[i++]=c1;
                cnt1--;
                if(cnt1>0) maxh.push({cnt1,c1});
            }
        }
        
        return s;
    }
};