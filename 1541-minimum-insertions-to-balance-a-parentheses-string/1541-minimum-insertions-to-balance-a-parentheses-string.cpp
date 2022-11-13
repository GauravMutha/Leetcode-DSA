class Solution {
public:
    int minInsertions(string s) {
        int open=0 , openReq=0,closeReq=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else{
                if(i+1<s.size() && s[i+1]==')'){
                    if(open==0) openReq++;
                    else open--;
                    i++;
                }
                else{
                    if(open==0) openReq++ ,closeReq++;
                    else open-- , closeReq++;
                }
            }
        }
        return (2*open + openReq + closeReq);
    }
};

//Without Stack
//SC-->O(1)
//open is the number of ( 
//openReq is the number of ( required to balance orphan ))
//closeReq is the number of ) required to balance