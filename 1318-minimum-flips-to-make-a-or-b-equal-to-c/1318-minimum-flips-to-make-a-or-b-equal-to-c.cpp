class Solution {
public:
int minFlips(int a, int b, int c)
{
    int count = 0, i = 0;
    for (int j = 0; j < 32; j++)
    {
        i = 1 << j;
        if (c & i){
            if (!(a & i) && !(b & i))
            count++;
        }
        else
            {
                if ((a & i) ^ (b & i))
                    count += 1;
                else if ((a & i) && (b & i))
                    count += 2;
            }       
    }
    return count;
}
};