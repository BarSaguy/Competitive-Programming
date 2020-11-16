#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> grid;
vector<vector<bool>> visited;
int cnt;
int n, m;
bool bad;

void dfs(int x, int y)
{
    if (visited[x][y])
        return;
    visited[x][y] = true;
    if (grid[x][y] == 'B')
        bad = true;
    else if (grid[x][y] == 'G')
        cnt++;
    else if (grid[x][y] == '#')
        return;
    if (y < m - 1)
        dfs(x, y + 1);
    if (y > 0)
        dfs(x, y - 1);
    if (x > 0)
        dfs(x - 1, y);
    if (x < n - 1)
        dfs(x + 1, y);
}

int main()
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        cin >> n >> m;
        int good_count = 0;
        bool g = false;
        visited.resize(n);
        for (int b = 0; b < n; b++)
        {
            visited[b].resize(m);
            for (int j = 0; j < m; j++)
            {
                visited[b][j] = false;
            }
        }
        grid.resize(n);
        for (int b = 0; b < n; b++)
        {
            cin >> grid[b];
        }
        for (int i = 0; i < n; i++)
        {
            g = false;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'B')
                {
                    g = false;
                    if (j < m - 1)
                    {
                        if (grid[i][j + 1] == 'G')
                            g = true;
                        else if (grid[i][j + 1] == '.')
                            grid[i][j + 1] = '#';
                    }
                    if (j > 0)
                    {
                        if (grid[i][j - 1] == 'G')
                            g = true;
                        else if (grid[i][j - 1] == '.')
                            grid[i][j - 1] = '#';
                    }
                    if (i > 0)
                    {
                        if (grid[i - 1][j] == 'G')
                            g = true;
                        else if (grid[i - 1][j] == '.')
                            grid[i - 1][j] = '#';
                    }
                    if (i < n - 1)
                    {
                        if (grid[i + 1][j] == 'G')
                            g = true;
                        else if (grid[i + 1][j] == '.')
                            grid[i + 1][j] = '#';
                    }
                    if (g)
                    {
                        cout << "NO" << endl;
                        break;
                    }
                }
                else if (grid[i][j] == 'G')
                    good_count++;
            }
            if (g)
                break;
        }
        if (g)
            continue;
        cnt = 0;
        bad = false;
        dfs(n - 1, m - 1);
        if (bad && good_count > 0)
            cout << "NO" << endl;
        else if (cnt == good_count)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}