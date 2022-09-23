class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> vec(26);
        int k=0;
        for(auto i:key){
            if(i!=32 && !vec[i-'a']){
                vec[i-'a']= (k+'a');
                k++;
        }
	}
    for(int i=0;i<message.size();i++) if(message[i]!=32) message[i]= vec[message[i]-'a'];
    return message;
    }
};