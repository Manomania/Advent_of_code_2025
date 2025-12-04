#include <fstream>
#include <iostream>
#include <vector>
#include <string>

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
    int totalRemoved = 0;
    bool changed = true;
    while (changed) {
        changed = false;
        std::vector<std::pair<int, int>> toRemove;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if(grid[y][x] != '@')
                    continue;
                int neighbor = 0;
                for (int i = 0; i < 8; i++) {
                    int newY = y + dy[i];
                    int newX = x + dx[i];
                    if (newY >= 0 && newY < height && newX >= 0 && newX < width) {
                        if (grid[newY][newX] == '@')
                            neighbor++;
                    }
                }
                if (neighbor < 4) {
                    toRemove.push_back({y, x});
                }
            }
        }
        if (!toRemove.empty()) {
            changed = true;
            totalRemoved += toRemove.size();
            for (auto& pos : toRemove) {
                grid[pos.first][pos.second] = '.';
            }
        }
    }
    std::cout << totalRemoved << std::endl;
    return 0;
}