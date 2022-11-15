class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        vector<int>ans(temp.size(),0);
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i]) st.pop();
            
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;
            
            st.push(i);
        }
        return ans;
    }
};

//Unlike next greater element question here we store indexes so that we can talk in terms of days as indexes i means ith day