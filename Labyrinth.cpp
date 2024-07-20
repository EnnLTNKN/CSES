/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
const int maxn = 1e3 + 1;
int n, m;
char a[maxn][maxn];
bool used[maxn][maxn];
#define pii pair<int, int>
pii trace[maxn][maxn], h[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    pii st, ed;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
        cin >> a[i][j];
        if (a[i][j] == 'A') st = pii(i, j);
        if (a[i][j] == 'B') ed = pii(i, j);
    }
 
    queue<pii> q; q.push(st); used[st.first][st.second] = 1;
    while (q.size()){
        auto [x, y] = q.front(); q.pop();
        for (auto [addX, addY]: h){
            int nx = x + addX, ny = y + addY;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !used[nx][ny] && a[nx][ny] != '#'){
                trace[nx][ny] = pii(x, y);
                used[nx][ny] = 1;
                q.push(pii(nx, ny));
 
                if (a[nx][ny] == 'B'){
                    string ans;
                    while (nx != st.first || ny != st.second){
                        auto [lstx, lsty] = trace[nx][ny];
                        if (lstx + 1 == nx) ans += 'D';
                        if (lstx - 1 == nx) ans += 'U';
                        if (lsty + 1 == ny) ans += 'R';
                        if (lsty - 1 == ny) ans += 'L';
 
                        nx = lstx, ny = lsty; 
                    }
 
                    reverse(ans.begin(), ans.end());
                    return cout << "YES\n" << ans.size() << "\n" << ans, 0;
                }
 
            }
        }
    }
 
    cout << "NO";
 
}