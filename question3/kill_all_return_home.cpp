#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct Position
{
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
    bool operator==(const Position &other) const
    {
        return x == other.x && y == other.y;
    }
};

struct Castle
{
    Position pos;
    Castle(int x, int y) : pos(x, y) {}

    bool isAtHome(Position home)
    {
        return pos.x == home.x && pos.y == home.y;
    }
};

void displayPath(const vector<string> &path)
{
    for (const auto &step : path)
    {
        cout << step << endl;
    }
}

void findPaths(Castle castle, Position home, vector<Position> &soldiers, vector<string> &path, vector<vector<string>> &paths, vector<pair<int, int>> directions)
{
    if (castle.isAtHome(home) && soldiers.empty())
    {
        paths.push_back(path);
        return;
    }

    for (auto dir : directions)
    {
        int nx = castle.pos.x;
        int ny = castle.pos.y;

        while (true)
        {
            nx += dir.first;
            ny += dir.second;

            Position newPos(nx, ny);
            auto it = find(soldiers.begin(), soldiers.end(), newPos);

            if (it != soldiers.end())
            {
                path.push_back("Kill (" + to_string(newPos.x) + ", " + to_string(newPos.y) + ")");
                soldiers.erase(it);

                // Turn left
                path.push_back("Turn Left (" + to_string(newPos.x) + ", " + to_string(newPos.y) + ")");
                int temp = dir.first;
                dir.first = -dir.second;
                dir.second = temp;

                castle.pos = newPos;
                findPaths(castle, home, soldiers, path, paths, directions);

                // Backtrack
                castle.pos = Position(nx - dir.first, ny - dir.second);
                dir.first = temp;
                dir.second = -temp;
                soldiers.push_back(newPos);
                path.pop_back();
                path.pop_back();
                break;
            }

            if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10)
                break; // Assuming a 10x10 grid for bounds check
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of soldiers: ";
    cin >> n;

    vector<Position> soldiers;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Enter coordinates for soldier " << i + 1 << ": ";
        cin >> x >> y;
        soldiers.push_back(Position(x, y));
    }

    int cx, cy;
    cout << "Enter the coordinates for your 'special' castle: ";
    cin >> cx >> cy;

    Castle castle(cx, cy);
    Position home(cx, cy);

    vector<string> path;
    vector<vector<string>> paths;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    findPaths(castle, home, soldiers, path, paths, directions);

    cout << "Thanks. There are " << paths.size() << " unique paths for your 'special_castle'" << endl;
    for (size_t i = 0; i < paths.size(); i++)
    {
        cout << "Path " << i + 1 << endl;
        cout << "=======" << endl;
        displayPath(paths[i]);
    }

    return 0;
}
