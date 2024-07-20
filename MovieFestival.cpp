#include<bits/stdc++.h>
using namespace std;
#define int long long

struct fenwick{
    int n; vector<int> f;
    fenwick(int n){
        this -> n = n;
        f.resize(n + 1);
    }

    void update(int i, int val){
        for (; i <= n; i += i & -i) f[i] = max(f[i], val);
    }

    int get(int i){
        int ans = 0;
        for (; i; i -= i & -i) ans = max(ans, f[i]);
        return ans;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    #define pii pair<int, int>
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;

    fenwick Bit(n);
    sort(a.begin() + 1, a.end(), [&](pii a, pii b){
        return a.second < b.second;
    });

    int ans = 1;
    for (int i = 1; i <= n; i ++){
        int l = 1, r = i - 1, j = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (a[mid].second <= a[i].first) j = mid, l = mid + 1;
            else r = mid - 1;
        }

        int cur = Bit.get(j) + 1;
        ans = max(ans, cur);
        Bit.update(i, cur);
    }

    cout << ans;

}
 
 
