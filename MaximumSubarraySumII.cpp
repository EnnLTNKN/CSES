#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];

    multiset<int> ms; 
    int ans = -1e18;
    for (int i = 1; i <= n; i ++){
        if (i >= l) ms.insert(s[i - l]);
        if (i >= r + 1) ms.erase(ms.lower_bound(s[i - r - 1]));
        if (ms.size()) ans = max(ans, s[i] - *ms.begin());

    }

    cout << ans;

}
