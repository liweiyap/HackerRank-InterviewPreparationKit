#include <vector>

// IN: vector of integers, in which all integers occur twice except for one of them
// OUT: integer that occurs just once in the vector
int lonelyinteger(std::vector<int> a)
{
    int res = 0;
    for (int i:a)
    {
        res ^= i;
    }
    return res;
}
