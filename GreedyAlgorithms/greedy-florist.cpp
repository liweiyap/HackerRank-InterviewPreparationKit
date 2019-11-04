#include <vector>
#include <algorithm>  // sort

// IN: number of people in the group; cost per flower type
// OUT: minimum cost to buy one of each flower in total
int getMinimumCost(int k, std::vector<int> c){
    int n = c.size();
    int minCost = 0;
    
    // increment of multiple for cost of any flower
    int surcharge = 1;
    
    // number of buyers that have bought flower at old surcharge
    int buyers = 0;
    
    // sort costs in order to run greedy algorithm
    std::sort(c.begin(), c.end());
    
    // iterate from most expensive flower
    for (int i = n-1; i >= 0; --i){
        minCost += surcharge * c[i];
        ++buyers;
        
        // if all buyers have bought a flower at the old surcharge
        if (buyers == k){
            // increment surcharge and reset the number of buyers at given surcharge
            ++surcharge;
            buyers = 0;
        }
    }
    return minCost;
}
