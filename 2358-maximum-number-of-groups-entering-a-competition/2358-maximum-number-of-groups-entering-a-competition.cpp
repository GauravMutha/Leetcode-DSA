//math
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return (sqrt(1+8*grades.size())-1.0)/2;
    }
};