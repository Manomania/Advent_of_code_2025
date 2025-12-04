#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

int main(){
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::string line;
    int result = 0;
    int temp = 0;
    while (getline(myFile, line)){
        int left = 0;
        int right = 0;
        for (size_t i = 0; i < line.size(); i++){
            for (size_t j = i+1; j < line.size(); j++){
                temp = (left * 10) + right;
                if (left < (line[i] - '0')){
                    left = line[i] - '0';
                    right = 0;
                }
                if (right < (line[j] - '0'))
                    right = line[j] - '0';
                int newTemp = (left * 10) + right;
                if (temp < newTemp)
                    temp = newTemp;
            }
        }
        result += temp;
    }
    std::cout << result << std::endl;
    return 0;
}