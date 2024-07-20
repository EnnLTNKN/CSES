/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int maxn = 1e5 + 1;
int n, m, cnt[maxn], trace[maxn];
vector<int> a[maxn];
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    queue<int> q; q.push(1); cnt[1] = 1;
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v: a[u]){
            if (!cnt[v]) cnt[v] = cnt[u] + 1, trace[v] = u, q.push(v);
        }
    }
 
    if (cnt[n] == 0) return cout << "IMPOSSIBLE", 0;
    vector<int> ans;
    cout << cnt[n] << "\n";
    ans.push_back(n);
    while (n != 1){
        n = trace[n];
        ans.push_back(n);
    }
 
    reverse(ans.begin(), ans.end()); 
    for (int i: ans) cout << i << " ";
}