#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// 4 directions: up, down, left, right
const vector<Point> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// check if a point is inside the grid boundaries
bool isValid(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void bfs(const vector<vector<int>>& grid, vector<vector<int>>& dist, Point start) {
    queue<Point> q;
    q.push(start);
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // Explore each direction from the current point
        for (const auto& dir : directions) {
            int newX = current.x + dir.x;
            int newY = current.y + dir.y;
            if (isValid(newX, newY, grid.size()) && grid[newX][newY] == 0 && dist[newX][newY] > dist[current.x][current.y] + 1) {
                dist[newX][newY] = dist[current.x][current.y] + 1;
                q.push(Point(newX, newY));
            }
        }
    }
}

int main() {
    int size;
    while (cin >> size) {
        vector<vector<int>> grid(size, vector<int>(size));

        // Read the grid input where 0 is passable and 1 is blocked
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> grid[i][j];

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;  // Start and end coordinates

        vector<vector<int>> dist_from_start(size, vector<int>(size, numeric_limits<int>::max()));
        vector<vector<int>> dist_from_end(size, vector<int>(size, numeric_limits<int>::max()));

        // Calculate distances from the start and end points
        bfs(grid, dist_from_start, Point(sx, sy));
        bfs(grid, dist_from_end, Point(ex, ey));

        int m, x, y;
        cin >> m;  // Number of queries
        while (m--) {
            cin >> x >> y;  // Query coordinates
            if ((x == sx && y == sy) || (x == ex && y == ey)) {
                cout << "No\n";  // Start and end cannot be bus stops
            } else if (dist_from_start[x][y] == numeric_limits<int>::max() || dist_from_end[x][y] == numeric_limits<int>::max()) {
                cout << "No\n";  // Unreachable point
            } else if (dist_from_start[x][y] + dist_from_end[x][y] == dist_from_start[ex][ey]) {
                cout << "Yes\n";  // Point is on the shortest path
            } else {
                cout << "No\n";  // Point is not on the shortest path
            }
        }
        cout << "\n";
    }
    return 0;
}
