class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        stack<int>cnt;
        for(int i=0;i<s.size();i++){
            if(res.size()==0 || res.back()!=s[i]){
                res.push_back(s[i]);
                cnt.push(1);
            }
            else{
                res.push_back(s[i]);
                cnt.top()++;
                if(cnt.top()==k){
                    int n=k;
                    while(n--) res.pop_back();
                    cnt.pop();
                }
            }
        }
        return res;
    }
};

//1 pass + 1 count Stack
//TC==O(n*k)
//SC-->O(n) worst case