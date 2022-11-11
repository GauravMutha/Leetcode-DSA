class Solution {
public:
    vector<int> finalPrices(vector<int>& vec) {
        vector<int>ans(vec.size(),-1);
        stack<int>st;
        
        for(int i=vec.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>vec[i]) st.pop();
            if(st.empty()){
                ans[i]=vec[i];
            }
            else{
                ans[i]=vec[i]-st.top();
            }
            if(st.empty() || st.top()!=vec[i]) st.push(vec[i]);
        }
        return ans;
    }
};
//Refactoring previous code