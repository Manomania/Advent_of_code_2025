#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

bool isSymetric(unsigned long n){
    std::stringstream strstream;
    std::string number;
    strstream << n;
    strstream >> number;
    std::string fHalf = number.substr(0, number.size()/2);
    std::string sHalf = number.substr(number.size()/2);
    if (fHalf == sHalf)
        return true;
    return false;
}

int main(){
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::string line;
    unsigned long result;
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