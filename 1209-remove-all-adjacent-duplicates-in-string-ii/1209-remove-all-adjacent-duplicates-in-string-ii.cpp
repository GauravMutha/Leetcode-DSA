class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int>count;
        int i=0;
        for(int j=0;j<s.size();j++,i++){
            s[i]=s[j];
            if(i>0 && s[i-1]==s[i]) count.top()++;
            else count.push(1);
            if(count.top()==k) i-=k , count.pop();
        }
        return s.substr(0,i);
    }
};

//Two pointers
//TC---> O(n) (optimised from n*k of last code to n)
//SC-->O(n)