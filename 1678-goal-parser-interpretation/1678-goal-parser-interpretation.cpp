class Solution {
public:
    string interpret(string command) {
        string res;
        
        for(int i=0;i<command.size();i++){
            if(command[i]=='G')
                res+="G";
            else if(command[i]==')')
                res+="o";
            else if(command[i]=='a'){
                res+="al";
                i+=2;
            }
        }
        return res;
    }
};