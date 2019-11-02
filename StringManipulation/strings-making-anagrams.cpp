#include <string>
#include <unordered_map>


// IN: two strings
// OUT: number of deletions required to make both strings anagrams of each other
int makeAnagram(std::string a, std::string b){
    // initialise hash table
    std::unordered_map<std::string, int> hash;
    
    // fill hash table with characters from first string
    for (auto a_it = a.begin(); a_it != a.end(); ++a_it){
        std::string s(1, *a_it);
        ++hash[s];
    }
    
    // iterate over all characters from second string
    int n_deletions = 0;
    for (auto b_it = b.begin(); b_it != b.end(); ++b_it){
        std::string s(1, *b_it);
        
        // if character from second string not found in first string
        if (--hash[s] < 0){
            hash.erase(s);
            // increment number of deletions required
            ++n_deletions;
        }
        
        // erase for efficiency
        if (hash[s] == 0){
            hash.erase(s);
        }
    }
    
    // all remaining characters in hash table are found in first string but not in second string
    for (auto kv:hash){
        n_deletions += kv.second;
    }

    return n_deletions;
}
