class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& vec) {
        vector<int>ans(vec.size(),-1);
        stack<int>st;
        for(int i=vec.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=vec[i]) st.pop();
            st.push(vec[i]);
        }
        for(int i=vec.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=vec[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(vec[i]);
        }
        return ans;
    }
};

//2 pass