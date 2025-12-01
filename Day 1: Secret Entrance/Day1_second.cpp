#include <fstream>
#include <iostream>

int main(){
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    int result = 50;
    std::string line;
    int count = 0;
    while (getline(myFile, line)){
        int number = 0;
        for(size_t i = 1; i < line.size(); i++){
            number = number * 10 + (line[i] - '0');
        }
        if (line[0] == 'L'){
            if (result == 0)
                count += number / 100;
            else if (number >= result)
                count += 1 + (number - result) / 100;
            result = ((result - number) % 100 + 100) % 100;
        }
        else if (line[0] == 'R'){
            count += (result + number) / 100;
            result = (result + number) % 100;
        }
    } 
    std::cout << count << std::endl;
    myFile.close();
    return 0;
}