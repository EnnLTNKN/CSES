#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i].first, a[i].second = i;
    sort(a.begin() + 1, a.end());

    int ans = 0; a[0].second = 1e9;
    for (int i = 1; i <= n; i ++) if (a[i].second < a[i - 1].second) ans ++;
    cout << ans;
}
 
