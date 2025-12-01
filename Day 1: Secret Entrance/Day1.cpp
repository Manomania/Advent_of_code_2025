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
        number = line[1] - '0';
        if (line.size() > 2)
            number = number * 10 + (line[2] - '0');
        if (line[0] == 'L'){
            result += number;
            if (result < 0){
                result %= 100;
            }
        }
        if (line[0] == 'R'){
            result -= number;
            if (result > 99){
                result = (result % 100 + 100) % 100;
            }
        }
        if (result == 0)
            count++;
    }
    std::cout << count << std::endl;
    myFile.close();
    return 0;
}