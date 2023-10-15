// W, S, D, A to move. your objective is to goal the 'P' letter to the 'G' letter without hiting those '#'
#include <iostream>
#include <cstdlib>
#include <ctime>

const int gridSize = 5; 
const char playerChar = 'P';
const char goalChar = 'G';
const char obstacleChar = '#';

void initializeGrid(char grid[][gridSize], int& playerX, int& playerY, int& goalX, int& goalY) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = ' ';
        }
    }

    playerX = std::rand() % gridSize;
    playerY = std::rand() % gridSize;
    grid[playerX][playerY] = playerChar;

    goalX = std::rand() % gridSize;
    goalY = std::rand() % gridSize;
    grid[goalX][goalY] = goalChar;

    int numObstacles = gridSize - 2; 
    for (int i = 0; i < numObstacles; i++) {
        int obstacleX, obstacleY;
        do {
            obstacleX = std::rand() % gridSize;
            obstacleY = std::rand() % gridSize;
        } while (grid[obstacleX][obstacleY] != ' ');
        grid[obstacleX][obstacleY] = obstacleChar;
    }
}

void printGrid(const char grid[][gridSize]) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    char grid[gridSize][gridSize];
    int playerX, playerY, goalX, goalY;

    initializeGrid(grid, playerX, playerY, goalX, goalY);

    while (true) {
        printGrid(grid);
        std::cout << "Enter your move (w/a/s/d to move up/left/down/right, or q to quit): ";
        char move;
        std::cin >> move;

        if (move == 'q') {
            std::cout << "You quit the game." << std::endl;
            break;
        }

        int newPlayerX = playerX;
        int newPlayerY = playerY;

        if (move == 'w') {
            newPlayerX--;
        } else if (move == 'a') {
            newPlayerY--;
        } else if (move == 's') {
            newPlayerX++;
        } else if (move == 'd') {
            newPlayerY++;
        }

        if (newPlayerX >= 0 && newPlayerX < gridSize && newPlayerY >= 0 && newPlayerY < gridSize) {
            if (grid[newPlayerX][newPlayerY] == obstacleChar) {
                std::cout << "You hit an obstacle. Game over!" << std::endl;
                break;
            } else if (newPlayerX == goalX && newPlayerY == goalY) {
                std::cout << "Congratulations! You reached the goal!" << std::endl;
                break;
            }

            grid[playerX][playerY] = ' ';
            playerX = newPlayerX;
            playerY = newPlayerY;
            grid[playerX][playerY] = playerChar;
        }
    }

    return 0;
}
