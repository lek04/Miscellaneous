
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (nRows <= 0 || nCols <= 0 || sr <= 0 || sc <= 0 || er <= 0 || ec <= 0)
    {
        return false;
    }
    if (sr == er && sc == ec) {
        return true;
    }
    maze[sr][sc] = '-';
    if (maze[sr][sc + 1] != 'X' && maze[sr][sc + 1] != '-') {//is east is undiscovered
        if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
        {
            return true;
        }
    }
    if (maze[sr-1][sc] != 'X' && maze[sr-1][sc] != '-') {//is north is undiscovered
        if (pathExists(maze, nRows, nCols, sr-1, sc, er, ec))
        {
            return true;
        }
    }
    if (maze[sr][sc - 1] != 'X' && maze[sr][sc - 1] != '-') {//is west is undiscovered
        if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
        {
            return true;
        }
    }
    if (maze[sr+1][sc] != 'X' && maze[sr+1][sc] != '-') {//is south is undiscovered
        if (pathExists(maze, nRows, nCols, sr+1, sc, er, ec))
        {
            return true;
        }
    }
    return false;
}