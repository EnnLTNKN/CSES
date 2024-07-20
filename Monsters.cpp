/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int maxn = 1e3 + 1;
int n, m, d[maxn][maxn][2];
char a[maxn][maxn];
bool used[maxn][maxn][2];
 
#define pii pair<int, int>
queue<pii> q[2];
pii H[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, trace[maxn][maxn], st;
 
bool check(int x, int y, int t){
    if (t == 0) return x >= 1 && x <= n && y >= 1 && y <= m && !used[x][y][t] && a[x][y] != '#' && a[x][y] != 'M';
    return x >= 1 && x <= n && y >= 1 && y <= m && !used[x][y][t] && a[x][y] != '#';
}
 
void dfs(int t){
    while (q[t].size()){
        auto [x, y] = q[t].front(); q[t].pop();
        for (auto [addx, addy]: H){
            int nx = x + addx, ny = y + addy;
            if (check(nx, ny, t)){
                used[nx][ny][t] = 1;
                q[t].push(pii(nx, ny));
                d[nx][ny][t] = d[x][y][t] + 1;
                if (t == 0) trace[nx][ny] = pii(x, y);
            }
        }
    }
}
 
void Trace(int x, int y){
    string ans;
    while (pii(x, y) != st){
        auto [lx, ly] = trace[x][y];
        if (lx + 1 == x) ans += 'D';
        if (lx - 1 == x) ans += 'U';
        if (ly - 1 == y) ans += 'L';
        if (ly + 1 == y) ans += 'R';
 
        x = lx, y = ly;
    }
 
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << "\n" << ans;
    exit(0);
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    // freopen("enn.inp", "r", stdin);
    // freopen("enn.out", "w", stdout);
 
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
        cin >> a[i][j];
        d[i][j][0] = d[i][j][1] = 1e18;
        if (a[i][j] == 'A') q[0].push(pii(i, j)), used[i][j][0] = 1, st = pii(i, j), d[i][j][0] = 0;
        if (a[i][j] == 'M') q[1].push(pii(i, j)), used[i][j][1] = 1, d[i][j][1] = 0;
    }
 
    dfs(0);
    dfs(1);
 
    for (int i = 1; i <= m; i ++){
        if (a[1][i] != '#' && a[1][i] != 'M' && d[1][i][0] < d[1][i][1]) Trace(1, i);
        if (a[n][i] != '#' && a[n][i] != 'M' && d[n][i][0] < d[n][i][1]) Trace(n, i);
    }
 
    for (int i = 1; i <= n; i ++){
        if (a[i][1] != '#' && a[i][1] != 'M' && d[i][1][0] < d[i][1][1]) Trace(i, 1);
        if (a[i][m] != '#' && a[i][m] != 'M' && d[i][m][0] < d[i][m][1]) Trace(i, m);
    }
 
    cout << "NO";
