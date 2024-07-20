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
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    int l = 0, r = 1e18, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        int sum = 0;
        for (auto x: a) {
            sum += mid / x;
            if (sum >= k) break;
        }
        
        if (sum >= k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    cout << ans;

}
