// CSES Problem 1193: Labyrinth
// Link: https://cses.fi/problemset/task/1193/
// Description: You are given a map of a labyrinth, and your task is to find a path from start t...

#include <stdio.h>
#include <string.h>

#define MAXN 1005
#define int long long

int sx, sy, ex, ey, n, m;

char grid[MAXN][MAXN];
char par[MAXN][MAXN];
int vis[MAXN][MAXN];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

/* Simple queue implementation */
int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
int front = 0, rear = 0;

void push(int x, int y)
{
    qx[rear] = x;
    qy[rear] = y;
    rear++;
}

void pop()
{
    front++;
}

int empty()
{
    return front == rear;
}

void solve()
{
    scanf("%lld %lld", &n, &m);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        scanf(" %c", &grid[i][j]);

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

    memset(vis, 0, sizeof(vis));

    push(sx, sy);
    vis[sx][sy] = 1;

    while (!empty())
    {
        int x = qx[front];
        int y = qy[front];
        pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
            if (grid[nx][ny] == '#' || vis[nx][ny])
            continue;

            vis[nx][ny] = 1;
            par[nx][ny] = dir[i];

            if (nx == ex && ny == ey)
            break;

            push(nx, ny);
        }
    }

    if (!vis[ex][ey])
    {
        printf("NO\n");
        return;
    }

    char path[MAXN * MAXN];
    int len = 0;

    int x = ex, y = ey;

    while (x != sx || y != sy)
    {
        char d = par[x][y];
        path[len++] = d;

        if (d == 'U')
        x++;
        else if (d == 'D')
        x--;
        else if (d == 'L')
        y++;
        else
        y--;
    }

    /* reverse path */
    for (int i = 0; i < len / 2; i++)
    {
        char tmp = path[i];
        path[i] = path[len - i - 1];
        path[len - i - 1] = tmp;
    }

    printf("YES\n");
    printf("%lld\n", len);

    for (int i = 0; i < len; i++)
    printf("%c", path[i]);

    printf("\n");
}

signed main()
{
    solve();
    return 0;
}
