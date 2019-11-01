#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>


// IN: vectors of strings representing magazine and note
// OUT: print whether magazine has enough words to form note
void checkMagazine(std::vector<std::string> magazine, std::vector<std::string> note){
    // constructor hash map from magazine
    std::unordered_map<std::string,int> hash;
    for (auto mag_it = magazine.begin(); mag_it != magazine.end(); ++mag_it){
        ++hash[*mag_it];
    }
    
    // check whether note can be constructed from hash map
    for (auto note_it = note.begin(); note_it != note.end(); ++note_it){
        if (hash[*note_it] == 0){
            std::cout << "No\n";
            return;
        }
        --hash[*note_it];
    }

    std::cout << "Yes\n";
}
