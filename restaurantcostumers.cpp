#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    #define pii pair<int, int>
    vector<pii> a;
    for (int i = 1; i <= n; i ++){
        int x, y; cin >> x >> y;
        a.push_back(pii(x, 1));
        a.push_back(pii(y, -1));
    }
    
    sort(a.begin(), a.end());
    int sum = 0, ans = 0;
    for (int i = 0; i < a.size(); i ++){
        sum += a[i].second;
        ans = max(ans, sum);
    }

    cout << ans;
}
 
 
