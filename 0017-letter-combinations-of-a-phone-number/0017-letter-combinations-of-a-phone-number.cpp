//BFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return vector<string>();
        
        deque<string>q;
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        q.push_back("");
        
        for(auto &d : digits){
            int padNum=d-'0';
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop_front();
                for(auto ch : pad[padNum])
                    q.push_back(curr+ch);
            } 
        }
        
        return vector<string>(q.begin(),q.end());
    }
};