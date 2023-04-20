//BFS
//Using queues instead of vectors + the vector::swap method
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return vector<string>();
        
        deque<string>q;
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans={""},next;
        for(auto &d : digits){
            int padNum=d-'0';
            for(int i=0;i<ans.size();i++){
                string curr=ans[i];
                for(auto ch : pad[padNum])
                    next.push_back(curr+ch);
            }
            ans.swap(next);
            next.clear();
        }
        
        return ans;
    }
};