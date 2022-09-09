class Solution {
public:
    string getHappyString(int n, int k) {
        string res;
        string temp="";
        generate(res,temp,n,k);
        
        return res;
    }
    
    void generate(string& res,string& curr,int n,int& k){
        static vector<char>vect={'a','b','c'};
        
        if((curr.size()==n) || res.size()){
            if(--k==0)res=curr;
            return;
        }
        for(int i=0;i<vect.size();i++){
            if(curr.size() && (curr.back()==vect[i]))continue;
            curr+=vect[i];
            generate(res,curr,n,k);
            curr.pop_back();
        }
    }
};