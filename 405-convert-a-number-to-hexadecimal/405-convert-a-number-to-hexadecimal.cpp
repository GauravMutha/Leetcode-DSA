class Solution {
public:
    string converter(uint32_t num)
{
    string res = {};
    vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
    while (num)
    {
        int x = num % 16;
        if (x < 10)
            res += to_string(x);
        else
            res += (v[x % 10]);
        num /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

string toHex(int num)
{
    if(num==0){return "0";}
    
    else if (num >= 0)
    {
        return converter(num);
    }
    else
    {
        uint32_t x = abs(num);
        for (int i = 0; i < 32; i++)
        {
            (x & (1 << i)) ? (x &= ~(1 << i)) : (x |= (1 << i));
        }
        x += 1;
        return converter(x);
    }
}
};