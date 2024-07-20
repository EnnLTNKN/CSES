#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
rbTree s;

struct fenwick{
    int n; vector<int> f;
    fenwick(int n){
        this -> n = n;
        f.resize(n + 1);
    }

    void add(int i, int val){
        for (; i <= n; i += i & -i) f[i] += val;
    }

    int get(int i){
        int sum = 0;
        for (; i; i -= i & -i) sum += f[i];
        return sum;
    }
};

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> a(n), c; for (auto &x: a) cin >> x;

    c = a; sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    for (auto &x: a) x = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
    
    fenwick f(c.size());
    fenwick cnt(c.size());

    for (int i = 0; i < n; i ++){

        s.insert(a[i]);
        f.add(a[i], c[a[i] - 1]);
        cnt.add(a[i], 1);
        
        if (i >= k) {
            s.erase(s.upper_bound(a[i - k]));
            f.add(a[i - k], -c[a[i - k] - 1]);
            cnt.add(a[i - k], -1);
        }

        if (i >= k - 1){

            int median = *s.find_by_order(k / 2 + k % 2 - 1);
            cout << - f.get(median - 1) + c[median - 1] * cnt.get(median - 1) 
            + f.get(c.size()) - f.get(median) - c[median - 1] * (cnt.get(c.size()) - cnt.get(median)) << " ";
        }
    }
    
    
}
