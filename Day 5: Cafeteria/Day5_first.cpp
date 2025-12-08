#include <fstream>
#include <iostream>
#include <string>
#include <vector>

size_t stringToInt(const std::string& str){
    size_t value = 0;
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] < '0' || str[i] > '9')
            break;
        value = value * 10 + (str[i] - '0');
    }
    return value;
}

bool isInRange(const std::string& range, const std::string& idStr){
    size_t pos = range.find('-');
    if (pos == std::string::npos)
        return false;
    std::string leftV = range.substr(0, pos);
    std::string rightV = range.substr(pos + 1);
    size_t rangeStart = stringToInt(leftV);
    size_t rangeEnd = stringToInt(rightV);
    size_t id = stringToInt(idStr);
    return (id >= rangeStart && id <= rangeEnd);
}

int main() {
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::string line;
    std::vector<std::string> ranges;
    std::vector<std::string> ids;
    while (getline(myFile, line)) {
        if (line.empty())
            break;
        ranges.push_back(line);
    }
    while (getline(myFile, line)) {
        if (!line.empty())
            ids.push_back(line);
    }
    myFile.close();
    int freshCount = 0;
    for (const std::string& id : ids) {
        bool isFresh = false;
        for (const std::string& range : ranges) {
            if (isInRange(range, id)) {
                isFresh = true;
                break;
            }
        }
        if (isFresh)
            freshCount++;
    }
    std::cout << freshCount << std::endl;
    return 0;
}