class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string test=to_string(num);
        int count=0;       
        for(int i=0;i<test.size()-k+1;i++){
            int val = stoi(test.substr(i,k));
            if(val) count+=(num%val==0);            
        }
        return count;
    }
};