#include <set>
#include <vector>
#include <cmath>      // abs
#include <algorithm>  // min
#include <cassert>


// IN: two 3-by-3 matrices
// OUT: absolute difference between the values of both matrices
int computeDiff(std::vector<std::vector<int>> mat1,
                std::vector<std::vector<int>> mat2)
{
    assert(mat1.size() == 3 && mat1[0].size() == 3);
    assert(mat2.size() == 3 && mat2[0].size() == 3);

    int diff = 0;
    for (size_t rowIdx = 0; rowIdx < 3; ++rowIdx)
    {
        for (size_t colIdx = 0; colIdx < 3; ++colIdx)
        {
            diff += std::abs(mat1[rowIdx][colIdx] - mat2[rowIdx][colIdx]);
        }
    }
    return diff;
}

// IN: 3-by-3 matrix
// OUT: minimum cost required to convert input matrix to magic square matrix
int formingMagicSquare(std::vector<std::vector<int>> s)
{
    // set of all possible magic square matrices
    std::set<std::vector<std::vector<int>>> magicSquares
    {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };
    std::set<std::vector<std::vector<int>>>::iterator it;
    
    // minimum diff cannot be more than the maximum sum of a magic square matrix,
    // which is 1 + 2 + ... + 9 = 45
    int minDiff = 45;
    for (it = magicSquares.begin(); it != magicSquares.end(); ++it)
    {
        int diff = computeDiff(s, *it);
        minDiff = std::min(diff, minDiff);
    }
    return minDiff;
}
