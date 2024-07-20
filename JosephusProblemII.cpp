#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree <int, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    ordered_set s;
    for (int i = 1; i <= n; i ++) s.insert(i);
    int t = 0;
    for (int i = 1; i <= n; i ++){
        t = (t + k) % s.size();
        cout << *s.find_by_order(t) << " ";
        s.erase(*s.find_by_order(t));
    }
    
}
