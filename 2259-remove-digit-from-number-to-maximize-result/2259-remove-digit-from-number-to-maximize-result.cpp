class Solution {
public:
    string removeDigit(string n, char d) {
        int last=-1;
        
        for(int i=0;i<n.size();i++){
            if(n[i]==d){
                last=i;
                if(i<n.size()-1 && n[i+1]>d) return n.substr(0,i)+n.substr(i+1);
            }
        }
        
        return (n.substr(0,last)+n.substr(last+1));
    }
};