/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int maxn = 1e5 + 1;
int n, m, trace[maxn];
vector<int> a[maxn];
bool ok = 0, used[maxn];
 
void bfs(int u, int pu){
    for (int v: a[u]) {
        if (!used[v]) used[v] = 1, trace[v] = u, bfs(v, u); 
        else if (v != pu) {
            vector<int> ans = {v};
            while (u != v) ans.push_back(u), u = trace[u];
            ans.push_back(v);
            cout << ans.size() << "\n";
            for (int i: ans) cout << i << " ";
            exit(0);
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i ++) if (!used[i]) used[i] = 1, bfs(i, 0);
    cout << "IMPOSSIBLE";
}