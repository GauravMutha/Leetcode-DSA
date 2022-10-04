class Solution {
public:
    string largestGoodInteger(string num) {
        set<string>v={"111","222","333","444","555","666","777","888","999","000"};
        string res="   ",temp;
        for(int i=0;i<num.size()-2;i++){
            temp=num.substr(i,3);
            if(v.count(temp) && (res[0]<=temp[0])) res=temp;
        }
        return (res=="   ")?"":res;
    }
};