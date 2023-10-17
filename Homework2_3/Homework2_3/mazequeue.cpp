#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Coord
{
public:
    Coord(int r, int c) : m_row(r), m_col(c) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (nRows <= 0 || nCols <= 0 || sr <= 0 || sc <= 0 || er <= 0 || ec <= 0)
    {
        return false;
    }

    queue<Coord> cq;
    Coord a(sr, sc);
    cq.push(a);
    maze[sr][sc] = '-';

    while (!cq.empty())
    {
        Coord b(cq.front().r(), cq.front().c());
        cq.pop();
        if (b.r() == er && b.c() == ec) {
            return true;
        }
        if (maze[b.r()][b.c() + 1] != '-' && maze[b.r()][b.c() + 1] != 'X') {
            //if EAST is not explored
            cq.push(Coord(b.r(), b.c() + 1));
            maze[b.r()][b.c() + 1] = '-';
        }
        if (maze[b.r() - 1][b.c()] != '-' && maze[b.r() - 1][b.c()] != 'X') {
            //if NORTH is not explored
            cq.push(Coord(b.r() - 1, b.c()));
            maze[b.r() - 1][b.c()] = '-';
        }
        if (maze[b.r()][b.c() - 1] != '-' && maze[b.r()][b.c() - 1] != 'X') {
            //if WEST is not explored
            cq.push(Coord(b.r(), b.c() - 1));
            maze[b.r()][b.c() - 1] = '-';
        }
        if (maze[b.r() + 1][b.c()] != '-' && maze[b.r() + 1][b.c()] != 'X') {
            //if SOUTH is not explored
            cq.push(Coord(b.r() + 1, b.c()));
            maze[b.r() + 1][b.c()] = '-';
        }
    }
    return false;
}
/*
int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X..X...X.X",
        "X.XXXX.X.X",
        "X.X.X..X.X",
        "X...X.XX.X",
        "XXX......X",
        "X.X.XXXX.X",
        "X.XXX....X",
        "X...X..X.X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 5, 3, 8, 8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
} */

/*My Tests
int main()
{
    string maze[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze1[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze2[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze3[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze4[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze5[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };
    string maze6[10] = {
                "XXXXXXXXXX",
                "X..X...X.X",
                "X.XXXX.X.X",
                "X.X.X..X.X",
                "X...X.XX.X",
                "XXX......X",
                "X.X.XXXX.X",
                "X.XXX....X",
                "X...X..X.X",
                "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 5, 3, 5, 3)) //solved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;

    if (pathExists(maze2, 10, 10, 5, 3, 8, 8)) //solved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;

    if (pathExists(maze3, 10, 10, 5, 3, 6, 1)) //unsolved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    if (pathExists(maze4, 10, 10, 5, 3, 2, 8)) //solved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;

    if (pathExists(maze5, 10, 10, 5, 3, 8, 2)) //unsolved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    if (pathExists(maze6, 10, 10, 8, 1, 8, 3)) //solved
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
} */