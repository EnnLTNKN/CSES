#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    orderedSet s; 

    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i ++){
        s.insert(a[i]);
        if (i >= k) 
            s.erase(s.upper_bound(a[i - k]));
        if (i >= k - 1) 
            cout << *s.find_by_order(k / 2 + k % 2 - 1) << " ";
    }
}
