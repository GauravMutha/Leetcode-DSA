class Solution {
public:
    vector<int> mostCompetitive(vector<int>& n, int k) {
        vector<int>st;
        for(int i=0;i<n.size();i++){
            while(!st.empty() && st.back()>n[i] && n.size()-i-1>=k-st.size())
                st.pop_back();
            if(st.size()<k) st.push_back(n[i]);
        }
        return st;
    }
};
 //SC-->O(1)
//TC-->O(n)
