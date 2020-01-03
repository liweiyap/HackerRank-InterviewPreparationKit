#include <iostream>
#include <vector>


// IN: integer n
// OUT: print value of nth factorial, stored as a vector of ints
void extraLongFactorials(int maxN)
{
    std::vector<int> facVec{1};
    for (int n = 2; n <= maxN; ++n)
    {
        for (auto it = facVec.begin(); it != facVec.end(); ++it)
        {
            *it *= n;
        }

        for (size_t digit = 0; digit < facVec.size(); ++digit)
        {
            if (facVec[digit] < 10)
            {
                continue;
            }

            if (digit == facVec.size() - 1)
            {
                facVec.push_back(0);
            }

            facVec[digit+1] += facVec[digit] / 10;  // carry
            facVec[digit] %= 10;
        }
    }

    for (auto it = facVec.rbegin(); it != facVec.rend(); ++it)
    {
        std::cout << *it;
    }
}
