class Solution {
public:
vector<string> letterCasePermutation(string s) {
        string temp;
        vector<string>ans; vector<int>helper;
       for(int i=0;i<s.size();i++){
           int x=s[i];
           if((x>96&&x<123) || (x>64&&x<91)){
            temp+=s[i];
            helper.push_back(i);
           }
       }
        for(int num=0;num<pow(2,temp.size());num++){
            string temp2=temp; string result=s;;
            for(int i=0;i<temp.size();i++){
                if(num&(1<<i)){result[helper[i]]=char(toupper(temp[i]));}
                else{result[helper[i]]=char(tolower(temp[i]));}
            }
            ans.push_back(result);
        }
        return ans;
    }
};