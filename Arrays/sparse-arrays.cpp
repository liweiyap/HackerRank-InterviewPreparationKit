#include <vector>
#include <string>
#include <unordered_map>

// IN: array of strings to search, array of query strings
// OUT: integer array of frequencies of queries in the strings to be searched
std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries) {
    std::unordered_map<std::string, int> hash;
    std::vector<int> output;

    for (auto it = strings.begin(); it != strings.end(); ++it){
        ++hash[*it];
    }

    for (auto it = queries.begin(); it != queries.end(); ++it){
        output.push_back(hash[*it]);
    }

    return output;
}
