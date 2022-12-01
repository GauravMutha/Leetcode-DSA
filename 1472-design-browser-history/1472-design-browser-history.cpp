class BrowserHistory {
public:
    stack<string>st,stFw;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        while(!stFw.empty()) stFw.pop();
        st.push(url);
    }
    
    string back(int steps) {
        while(st.size()>1 && steps){
            string temp=st.top();
            st.pop();
            stFw.push(temp);
            steps--;
        }
        return st.top();
    }
    
    string forward(int steps) {
        while(!stFw.empty() && steps){
            string temp=stFw.top();
            stFw.pop();
            st.push(temp);
            steps--;
        }
        return st.top();
    }
};

//2 stacks

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */