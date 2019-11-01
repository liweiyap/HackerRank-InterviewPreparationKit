#include <string>
#include <unordered_set>


// IN: two strings
// OUT: return whether both strings share a common substring
std::string twoStrings(std::string s1, std::string s2){
    // construct hash set from one string
    std::unordered_set<std::string> hash;
    for (auto s1_it = s1.begin(); s1_it != s1.end(); ++s1_it){
        string s(1, *s1_it);
        hash.insert(s);
    }
    
    // find characters in other string in the hash set
    for (auto s2_it = s2.begin(); s2_it != s2.end(); ++s2_it){
        string s(1, *s2_it);
        if (hash.find(s) != hash.end()){
            return "YES";
        }
    }
    return "NO";
}
