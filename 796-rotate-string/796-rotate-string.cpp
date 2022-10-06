class Solution {
public:
    bool rotateString(string s, string goal) {
        /*When a string is concatenated with itself then all charaters become cyclic
        in such a way that it covers all the possible results of an cyclic operation
        mentioned imn this question */
        return (s.size()==goal.size())&& ((s+s).find(goal)!=string::npos);
    } 
};