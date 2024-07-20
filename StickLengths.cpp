#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());
    vector<int> sum(n);
    for (int i = 0; i < n; i ++) sum[i] = (i ? sum[i - 1] + a[i] : a[i]);

    function<int(int, int)> get = [&](int l, int r){
        if (l > r) return 0ll;
        if (l == 0) return sum[r];
        return sum[r] - sum[l - 1];
    };

    int ans = 1e18;
    for (int i = 0; i < n; i ++)
        ans = min(ans, a[i] * i - get(0, i - 1) - a[i] * (n - i - 1) + get(i + 1, n - 1));
    
    cout << ans;

}
 
 
