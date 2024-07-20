#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    #define pii pair<int, int> 
    vector<pii> a(n);
    for (auto &[x, y]: a) cin >> x >> y;
    sort(a.begin(), a.end(), [&](pii a, pii b){
        return a.second < b.second;
    });

    multiset<int, greater<int>> ms; for (int i = 1; i <= k; i ++) ms.insert(0);

    int ans = 0;
    for (auto [x, y]: a){
        if (ms.lower_bound(x) != ms.end()){
            ans ++;
            ms.erase(ms.lower_bound(x));
            ms.insert(y);
        }
    }

    cout << ans;
}
