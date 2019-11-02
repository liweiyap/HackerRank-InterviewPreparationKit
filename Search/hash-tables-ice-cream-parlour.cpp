#include <vector>
#include <unordered_map>
#include <utility>  // make_pair
#include <iostream>
#include <iterator>  // next


// IN: vector of cost for each flavour
// OUT: money required to buy EXACTLY TWO flavours
void whatFlavors(std::vector<int> cost, int money){
    int n = cost.size();
    
    // initialise and define hash map
    std::unordered_multimap<int, int> hash;
    for (int i = 0; i < n; ++i){
        if (cost[i] < money){
            hash.insert(make_pair(cost[i], i+1));  // one-indexing
        }
    }
    
    // case 1: if both flavours to be bought with the money have distinctly different costs
    for (auto kv:hash){
        if (hash.find(money-kv.first) != hash.find(kv.first) && hash.find(money-kv.first) != hash.end()){
            // output flavour with lower cost before flavour with higher cost
            if (kv.second < hash.find(money-kv.first)->second){
                std::cout << kv.second << " " << hash.find(money-kv.first)->second << "\n";
                return;
            }
            std::cout << hash.find(money-kv.first)->second << " " << kv.second << "\n";
            return;
        }
    }
    
    // case 2: if both flavours to be bought with the money have identical cost
    auto rep_it = hash.equal_range(money/2);
    // output flavour with lower cost before flavour with higher cost
    if ((rep_it.first)->second < std::next(rep_it.first,1)->second){
        std::cout << (rep_it.first)->second << " " << std::next(rep_it.first,1)->second << "\n";
        return;
    }
    std::cout << std::next(rep_it.first,1)->second << " " << (rep_it.first)->second << "\n";
}
