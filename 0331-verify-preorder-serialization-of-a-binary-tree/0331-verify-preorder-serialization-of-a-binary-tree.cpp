//USING STACK
//TC-->O(N)
//SC-->o(N)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int>vec;
        stack<int>st;
        string temp="";
        for(auto c : preorder){
            if(c==','){
                if(temp=="") continue;
                else vec.push_back(stoi(temp)) , temp="";
            }
            else if(c=='#') vec.push_back(-1);
            else temp.push_back(c);
        }
        if(temp!="") vec.push_back(stoi(temp));
        for(int i=0;i<vec.size();i++){
            int val=vec[i];
            while(val==-1 && !st.empty() && st.top()==val){
                st.pop();
                if(st.empty()) return false;
                st.pop();
            }
            st.push(val);
        }
        
        return ((st.size()==1) && (st.top()==-1));
    }
};