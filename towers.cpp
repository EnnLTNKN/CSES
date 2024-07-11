#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    multiset<int> ms;

    int ans = 0;
    for (int x: a){
        if (ms.upper_bound(x) == ms.end()) ans ++;
        else ms.erase(ms.upper_bound(x));
        ms.insert(x);
    }
   
   cout << ans;
}
 
