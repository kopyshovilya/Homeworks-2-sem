#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <vector>
#include <functional>

void passingThroughAVector(std::vector<std::string> &words, std::function <void(std::string&)> func){
    for (auto &word:words)
    {
        func(word);
    }
}

int main() {
    std::vector<std::string> words;

    std::filesystem::create_directories("processed");

    std::filesystem::path filename{"text.txt"};
    std::filesystem::path cFile{"processed/c.txt"};
    std::filesystem::path evenFile{"processed/even.txt"};
    std::filesystem::path oddFile{"processed/odd.txt"};

    std::ofstream cFileOut(cFile);
    std::ofstream evenFileOut(evenFile);
    std::ofstream oddFileOut(oddFile);

    std::ifstream fileIn(filename);
    
    for (std::string word; fileIn >> word;) {
        words.push_back(std::move(word));
    }
    passingThroughAVector(words, [](std::string &str){for(auto &c:str) {c = std::isupper(c) ? tolower(c) : c;
                                                                                c = c == 'c' ? std::toupper(c) : c;}});

    //passingThroughAVector(words, [](std::string &str){if(str.find('C')){cFileOut << str;}});             почему не работает?

    for (auto &word:words) {
        if(word.find('C') + 1)
            {cFileOut << word << '\n';}
        else{
            if (word.length() % 2) oddFileOut << word + "_" << '\n';
            else evenFileOut << word + "_" << '\n';
        }
    }
    
    evenFileOut.close();
    oddFileOut.close();
    cFileOut.close();
    fileIn.close();

    return 0;
}
