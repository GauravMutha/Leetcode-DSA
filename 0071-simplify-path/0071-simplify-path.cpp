class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string>st1,st2;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/') continue;
            string temp;
            while(i<size(path) && path[i]!='/')
                temp+=path[i++];
            if(temp==".") 
                continue;
            else if(temp=="..") {
                if(!st1.empty()) 
                    st1.pop();
            }
            else st1.push(temp);
        }
        if(st1.empty()) return "/";
        while(!st1.empty()){
            string temp=st1.top();
            st1.pop();
            st2.push(temp);
        }
        while(!st2.empty()){
            res+= ("/" + st2.top()); 
            st2.pop();
        }
        return res;
    }
};

//3 pass
//SC-->O(N)
//TC-->O(N)