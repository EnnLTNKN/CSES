#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    vector<pair<int, int>> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i].first, a[i].second = i;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) pos[a[i].second] = i;

    function<int(int, int)> get = [&](int l, int r){
        if (l < 1) l = 1; if (r > n) r = n;
        int ans = 1;
        for (int i = l + 1; i <= r; i ++) if (a[i].second < a[i - 1].second) ans ++;
        return ans;
    };

    int initial = get(1, n);

    while (q --){
        int i, j; cin >> i >> j;
        int l = min(pos[i], pos[j]), r = max(pos[i], pos[j]);

        if (l == r - 1){
            int prev = get(l - 1, r + 1);
            swap(pos[i], pos[j]); swap(a[l], a[r]);
            int cur = get(l - 1, r + 1);

            initial -= prev -  cur;
            cout << initial << "\n";
        }

        else {
            int prev1 = get(l - 1, l + 1), prev2 = get(r - 1, r + 1);
            swap(pos[i], pos[j]); swap(a[l], a[r]);
            int cur1 = get(l - 1, l + 1), cur2 = get(r - 1, r + 1);

            initial -= prev1 + prev2 - cur1 - cur2;
            cout << initial << "\n";
        }
    }
}
 
