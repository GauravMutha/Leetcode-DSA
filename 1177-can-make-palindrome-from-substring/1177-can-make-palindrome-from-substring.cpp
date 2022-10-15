class Solution {
public:
vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
{
    vector<bool> res(queries.size());
    unordered_map<int, int> IndToBit;
    IndToBit[0] = -1;
    int currMask = 0;
    for (int i = 0; i < s.size(); i++)
    {
        currMask ^= (1 << (s[i] - 'a'));
        IndToBit[i] = currMask;
    }
    for (int i = 0; i < queries.size(); i++)
    { 
        int setbits=__builtin_popcount(IndToBit[queries[i][0] - 1] ^ IndToBit[queries[i][1]]);
        res[i] = (setbits<2 || queries[i][2]>=(setbits/2));
    }
    return res;
}
};