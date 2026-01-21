// CSES Problem 1193: Labyrinth
// Link: https://cses.fi/problemset/task/1193/
// Description: You are given a map of a labyrinth, and your task is to find a path from start t...

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int m_inf = INT_MIN;
#define int long long
int sx, sy, ex, ey, n, m;
vector<vector<int>> vis;
vector<vector<char>> par;
vector<vector<char>> grid;
vector<char> ans;
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    par.resize(n, vector<char>(m));
    vis.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        cin >> grid[i][j];
        if (grid[i][j] == 'A')
        {
            sx = i;
            sy = j;
        }
        if (grid[i][j] == 'B')
        {
            ex = i;
            ey = j;
        }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
            if (grid[nx][ny] == '#' || vis[nx][ny])
            continue;

            vis[nx][ny] = 1;
            par[nx][ny] = dir[i];
            if (nx == ex && ny == ey)
            break;

            q.push({nx, ny});
        }
    }

    if (!vis[ex][ey])
    {
        cout << "NO\n";
        return;
    }

    string path = "";
    int x = ex, y = ey;

    while (x != sx || y != sy)
    {
        char d = par[x][y];
        path.push_back(d);

        if (d == 'U')
        x++;
        else if (d == 'D')
        x--;
        else if (d == 'L')
        y++;
        else
        y--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n"
    << path.size() << "\n"
    << path << "\n";
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
