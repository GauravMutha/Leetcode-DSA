class Solution {
public:
    string decodeString(string s) {
        stack<string>st; st.push(""); //initialise a stack with empty string
        string num="";
        string res="";
        for(auto c:s){
            if(isalpha(c)) st.top()+=c;
            else if(isdigit(c)) num+=c;
            else if(c=='['){
                st.push(num);
                st.push("");
                num="";
            }
            else{
                string temp=st.top() , temp2=temp; st.pop();
                int n=stoi(st.top()) ; st.pop();
                for(int i=0;i<n-1;i++)
                    temp+=temp2;
                st.top()+=temp;
            }
        }
        return st.top();
    }
};

//Uses 1 stack
//SC-->O(n)
//TC-->O(n)