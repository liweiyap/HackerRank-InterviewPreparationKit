#include <string>
#include <unordered_map>
#include <cassert>
#include <iterator>  // next
#include <cmath>     // abs


// IN: string
// OUT: YES/NO string indicating whether all characters of the string appear the same number of times, given that at most one deletion is allowed
std::string isValid(std::string s){
    // hash table of every char in string
    std::unordered_map<std::string, int> charHash;
    
    // hash table of frequency of chars
    std::unordered_map<int, int> freqHash;
    
    // iterate over all chars in string
    for (auto str_it = s.begin(); str_it != s.end(); ++str_it){
        std::string c(1, *str_it);
        
        // insert char into first hash table
        ++charHash[c];
        
        // manipulate second hash table
        ++freqHash[charHash[c]];
        if (--freqHash[charHash[c]-1] <= 0){
            freqHash.erase(charHash[c]-1);
        }
    }
    
    // get size of second hash table
    int freqHashSize = freqHash.size();
    
    // size cannot be 0 or negative if string is not empty
    assert(freqHashSize > 0);
    
    // if more than two frequencies are present, then we need more than one deletion, so invalid
    if (freqHashSize > 2){
        return "NO";
    }
    
    // if only one frequency is present, then automatically valid, as no deletions required
    if (freqHashSize == 1){
        return "YES";
    }
    
    // the only remaining case is that exactly two frequencies are present
    
    // if first element occurs more frequently than second element
    if (freqHash.begin()->second >= std::next(freqHash.begin(),1)->second){
        // if second element does not have a frequency of 1, then we need more than one deletion, so invalid
        if (std::next(freqHash.begin(),1)->second != 1){
            return "NO";
        /* otherwise, if second element has a frequency of 1 but the difference between the first
         * and the second elements is so big that more than one deletion is required, so still invalid
         */
        } else if (std::next(freqHash.begin(),1)->first != 1 && std::abs(freqHash.begin()->first - std::next(freqHash.begin(),1)->first) > 1){
            return "NO";
        }
    }
    
    // if first element occurs less frequently than second element
    if (freqHash.begin()->second <= std::next(freqHash.begin(),1)->second){
        // if first element does not have a frequency of 1, then we need more than one deletion, so invalid
        if (freqHash.begin()->second != 1){
            return "NO";
        /* otherwise, if first element has a frequency of 1 but the difference between the first
         * and the second elements is so big that more than one deletion is required, so still invalid
         */
        } else if (freqHash.begin()->first != 1 && std::abs(freqHash.begin()->first - std::next(freqHash.begin(),1)->first) > 1){
            return "NO";
        }
    }
    
    // if all tests above are passed, then valid
    return "YES";
}
