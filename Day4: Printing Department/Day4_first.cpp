#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>


int main() {
    std::ifstream myFile("input/input.txt");
    if(!myFile.is_open())
        return 1;
    std::vector<std::string> grid;
    std::string line;
    while (getline(myFile, line))
        grid.push_back(line);
    myFile.close();
    int height = grid.size();
    int width = grid[0].size();
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int result = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbor = 0;
            if(grid[y][x] != '@')
                continue;
            for (int i = 0; i < 8; i++) {
                int newY = y + dy[i];
                int newX = x + dx[i];
                if (newX == x && newY == y)
                    continue;
                if (newY >= 0 && newY < height && newX >= 0 && newX < width && grid[newY][newX] == '@'){
                        neighbor++;
                }
            }
            if (neighbor < 4)
                result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}