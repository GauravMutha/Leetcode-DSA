class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (((coordinates[0]-96)+(coordinates[1]-'0'))%2==0)? false: true;
    }
};