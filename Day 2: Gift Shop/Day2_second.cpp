#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

bool isSymetric(unsigned long n){
    std::stringstream strstream;
    std::string number;
    strstream << n;
    strstream >> number;
    size_t len = number.size();
    for(size_t numParts = 2; numParts <= len; numParts++){
        if(len % numParts != 0)
            continue;
        size_t partSize = len / numParts;
        std::string reference = number.substr(0, partSize);
        bool allMatch = true;
        for(size_t i = 1; i < numParts; i++){
            std::string currentPart = number.substr(i * partSize, partSize);
            if(currentPart != reference){
                allMatch = false;
                break;
            }
        }
        if(allMatch)
            return true;
    }
    
    return false;
}

int main(){
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::string line;
    unsigned long result = 0;
    while (getline(myFile, line)){
        std::string start;
        std::string end;
        size_t posHyp = line.find('-');
        size_t posComma = line.find(',');
        start = line.substr(0, posHyp);
        end = line.substr(posHyp + 1, posComma - posHyp - 1);
        unsigned long startN = 0;
        for(size_t i = 0; i < start.size(); i++){
            startN = (startN * 10) + (start[i] - '0');
        }
        unsigned long endN = 0;
        for(size_t i = 0; i < end.size(); i++){
            endN = (endN * 10) + (end[i] - '0');
        }
        while (startN <= endN){
            if(isSymetric(startN)){
                result += startN;
            }
            startN++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}