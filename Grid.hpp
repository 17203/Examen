#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid{
private:
int rows, cols;
int sizeX, sizeY;
Vector2i size;
vector<vector<int>> next;
vector <vector<int>> grid;

public:
    Grid(int rows, int cols);
    Grid(int rows, int cols, int width, int height);
    
    void uptdate();
    void drawTo(RenderWindow &window);
    void click(int x, int y);
    
};

#endif