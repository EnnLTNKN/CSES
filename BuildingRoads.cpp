/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int maxn = 1e5 + 1;
int n, m, cnt[maxn];
vector<int> a[maxn];
 
void dfs(int u){
    for (int v: a[u]) if (!cnt[v]) cnt[v] = cnt[u], dfs(v);
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    vector<int> ans;
    int num = 0;
    for (int i = 1; i <= n; i ++){
        if (!cnt[i]){
            ans.push_back(i);
            cnt[i] = ++num;
            dfs(i);
        }
    }
 
    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size() - 1; i ++) cout << ans[i] << " " << ans[i + 1] << "\n";
    
 
    
}