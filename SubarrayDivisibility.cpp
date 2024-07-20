#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];

    map<int, int> mp; mp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int cur = abs(s[i]) % n;
        if (s[i] < 0) cur = (n - cur) % n;
        ans += mp[cur];
        mp[cur] ++;
    }

    cout << ans;
}
