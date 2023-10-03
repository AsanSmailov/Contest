bool check(const std::vector<std::string>& maze, int row, int col, std::vector<std::vector<bool>>& visited) {
    if (maze[row][col] == 'E') {
        return true;
    }
    visited[row][col] = true;
    std::vector<std::pair<int, int>> pos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& p : pos) {
        int newRow = row + p.first;
        int newCol = col + p.second;
        
        if (!visited[newRow][newCol] && maze[newRow][newCol] != '#') {
            if (check(maze, newRow, newCol, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool is_can_exit_from_maze(const std::vector<std::string>& maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    return check (maze, row, col, visited);
}