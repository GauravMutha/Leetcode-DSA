class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        stack<char>st;
        stack<int>cnt;
        for(int i=s.size()-1;i>=0;i--){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
                cnt.push(1);
            }
            else{
                st.push(s[i]);
                cnt.top()++;
                if(cnt.top()==k){
                    int n=k;
                    while(n--) st.pop();
                    cnt.pop();
                }
            }
        }
        while(!st.empty()) res+=st.top() , st.pop();
        return res;
    }
};

//2 pass + Using two Stacks
//TC==O(n*k)
//SC-->O(1)