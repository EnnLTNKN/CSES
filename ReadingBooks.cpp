#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int mx = 0, sm = 0;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x; mx = max(mx, x);
        sm += x;
    }

    sm -= mx;
    cout << ((sm >= mx) ? mx + sm : mx * 2);
    
}
