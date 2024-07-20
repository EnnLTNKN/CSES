#include<bits/stdc++.h>
using namespace std;
#define int long long
struct fenwick{
    int n; vector<int> f;
    fenwick(int n){
        this -> n = n;
        f.resize(n + 1, 0);
    }

    void add(int i){
        for (; i <= n; i += i & -i) f[i] ++;
    }

    int get(int i){
        int ans = 0;
        for (; i; i -= i & -i) ans += f[i];
        return ans;
    }
};

struct item{
    int l, r, index;
    item(int l, int r, int index){
        this -> l = l, this -> r = r, this -> index = index;
    }
    item(){}
};

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    #define pii pair<int, int>    
    vector<item> a(n + 1);

    vector<int> c;
    vector<pair<int, int>> ans(n + 1);

    for (int i = 1; i <= n; i ++){
        cin >> a[i].l >> a[i].r; c.push_back(a[i].l), c.push_back(a[i].r);
        a[i].index = i;
    }

    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int i = 1; i <= n; i ++){
        a[i].l = lower_bound(c.begin(), c.end(), a[i].l) - c.begin() + 1;
        a[i].r = lower_bound(c.begin(), c.end(), a[i].r) - c.begin() + 1;
    }

    sort(a.begin() + 1, a.end(), [&](item a, item b){
        return a.l < b.l || (a.l == b.l && a.r > b.r);
    });

    fenwick bit(c.size());
    for (int i = 1; i <= n; i ++){
        ans[a[i].index].second = bit.get(c.size()) - bit.get(a[i].r - 1);
        bit.add(a[i].r);
    }

    sort(a.begin() + 1, a.end(), [&](item a, item b){
        return a.l > b.l || (a.l == b.l && a.r < b.r);
    });

    bit = fenwick(c.size());
    for (int i = 1; i <= n; i ++){
        ans[a[i].index].first = bit.get(a[i].r);
        bit.add(a[i].r);
    }

    for (int i = 1; i <= n; i ++) cout << ans[i].first << " \n"[i == n];
    for (int i = 1; i <= n; i ++) cout << ans[i].second << " ";
}
