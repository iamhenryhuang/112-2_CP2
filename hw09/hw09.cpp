#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// directions: left, right, down, up
const vector<Point> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// n = grid's size (n * n)
bool isValid(int x, int y, int n) {
    return x > 0 && y > 0 && x < n-1 && y < n-1;
}

int bfs(const vector<vector<int>>& grid, Point start, Point end) {
    int n = grid.size();
    vector<vector<int>> map(n, vector<int>(n, -1)); // -1 means unreachable
    queue<Point> q;
    q.push(start);
    map[start.x][start.y] = 0;

    while (q.empty() == false) {
        Point current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y) {
            return map[current.x][current.y];
        }

        for (const auto& dir : directions) {
            int newX = current.x;
            int newY = current.y;

            while (isValid(newX + dir.x, newY + dir.y, n) == true && grid[newX + dir.x][newY + dir.y] == 0) {
                newX += dir.x;
                newY += dir.y;
            }

            if (map[newX][newY] == -1) {
                map[newX][newY] = map[current.x][current.y] + 1;
                q.push(Point(newX, newY));
            }
        }
    }

    return -1;
}

int main() {
    int N;
    while (cin >> N) {
        vector<vector<int>> grid(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> grid[i][j];

        int M;
        cin >> M;

        for (int i = 0; i < M; ++i) {
            int Sx, Sy, Ex, Ey;
            cin >> Sx >> Sy >> Ex >> Ey;

            if ((Sx == Ex && Sy == Ey)) {
                cout << "No\n";
            } else {
                int result = bfs(grid, Point(Sx, Sy), Point(Ex, Ey));
                if (result == -1) {
                    cout << "No\n";
                } else {
                    cout << result << "\n";
                }
            }
        }
    }

    return 0;
}
