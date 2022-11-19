class Solution {
public:
    string decodeString(string s) {
        stack<string>chars;
        stack<int>nums;
        int num=0;
        string res="";
        for(auto c:s){
            if(isalpha(c)) res.push_back(c);
            else if(isdigit(c)) num=num*10 + (c-'0');
            else if(c=='['){
                chars.push(res);
                nums.push(num);
                res="";
                num=0;
            }
            else{
                string temp=res;
                for(int i=0;i<nums.top()-1;i++)
                    res+=temp;
                res=chars.top()+res;
                nums.pop();
                chars.pop();
            }
        }
        return res;
    }
};

//Uses 2 Stack
//SC-->O(n)
//TC-->O(n)