#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (auto &x: a) cin >> x; 
    for (auto &x: b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    
    int j = 0, ans = 0;
    for (int i = 0; i < n; i ++){
        while (j < m && b[j] < a[i] - k) j ++;
        if (j == m) break;
        if (abs(a[i] - b[j]) <= k) ans ++, j ++;
    }
    
    cout << ans << "\n";
 
}
