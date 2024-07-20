#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    multiset<int, greater<int>> ms;

    for (auto &x: a) cin >> x, ms.insert(x);
    for (auto &x: b) {
        cin >> x;
        if (ms.lower_bound(x) == ms.end()){
            cout << -1 << "\n";
            continue;
        }

        int ans = *(ms.lower_bound(x));
        ms.erase(ms.find(ans));
        cout << ans << "\n";
    }
    
}
 
 
