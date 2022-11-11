class Solution {
public:
    vector<int> finalPrices(vector<int>& vec) {
        vector<int>ans(vec.size(),-1);
        stack<int>st;
        for(int i=vec.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=vec[i];
                st.push(vec[i]);
            }
            else{
                if(st.top()<vec[i]){
                    ans[i]=vec[i]-st.top();
                    st.push(vec[i]);
                }
                else if(st.top()>vec[i]){
                    while(!st.empty() && st.top()>vec[i]) st.pop();
                    if(st.empty()){
                        ans[i]=vec[i];
                        st.push(vec[i]);
                    }
                    else if(st.top()<vec[i]){
                        ans[i]=vec[i]-st.top();
                        st.push(vec[i]);
                    }
                    else if(st.top()==vec[i]) ans[i]=vec[i]-st.top();
                }
                else  ans[i]=vec[i]-st.top();
            }
        }
        return ans;
    }
};
//Redundant code