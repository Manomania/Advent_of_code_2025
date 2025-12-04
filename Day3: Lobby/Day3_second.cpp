#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

int main(){
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::string line;
    unsigned long long result = 0;
    while (getline(myFile, line)){
        std::string tempLine = line;
        int toRemove = tempLine.size() - 12;
        std::string bestLine;
        for (size_t i = 0; i < tempLine.size(); i++) {
            while (toRemove > 0 && !bestLine.empty() && bestLine.back() < tempLine[i]) {
                bestLine.pop_back();
                toRemove--;
            }
            bestLine += tempLine[i];
        }
        bestLine = bestLine.substr(0, 12);
        unsigned long long value = 0;
        for (size_t i = 0; i < bestLine.size(); i++) {
            value = value * 10 + (bestLine[i] - '0');
        }
        std::cout << value << std::endl;
        result += value;
    }
    std::cout << result << std::endl;
    return 0;
}