#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
struct item{
    int l, r, id;
    item(){}
    bool operator < (item other){
        return this -> r < other.r;
    }
};

int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i].l >> a[i].r, a[i].id = i;
    sort(a.begin(), a.end());

    #define pii pair<int, int>
    set<pii, greater<pii>> s;

    vector<int> ans(n);

    int cnt = 0;
    for (int i = 0; i < n; i ++){
        if (s.upper_bound(pii(a[i].l, 0)) == s.end()) {
            cnt ++; 
            ans[a[i].id] = cnt;
            s.insert(pii(a[i].r, cnt));
        }

        else {
            auto [val, id] = *s.upper_bound(pii(a[i].l, 0));
            s.erase(s.upper_bound(pii(a[i].l, 0)));
            ans[a[i].id] = id;
            s.insert(pii(a[i].r, id));
        }
    }

    cout << cnt << "\n";
    for (int i: ans) cout << i << " ";
}