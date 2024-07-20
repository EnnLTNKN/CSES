#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
// #define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 20;

#define pii pair<int, int>
pii H[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char a[1001][1001];
bool cnt[1001][1001];

int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) cin >> a[i][j];

    int curcnt = 0;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (!cnt[i][j] && a[i][j] == '.'){
        queue<pii> q; q.push(pii(i, j)); curcnt ++;
        while (q.size()){
            auto [x, y] = q.front(); q.pop();
            cnt[x][y] = 1;
            for (auto [addX, addY]: H){
                int nx = x + addX, ny = y + addY;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.' && cnt[nx][ny] == 0) 
                    q.push(pii(nx, ny)), cnt[nx][ny] = 1;
            }
        }
    }

    cout << curcnt;
}
