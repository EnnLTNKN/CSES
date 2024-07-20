#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;

    int sum = 0, ans = *max_element(a.begin(), a.end());
    for (auto x: a){
        sum += x;
        if (sum < 0) sum = 0;
        else ans = max(ans, sum);
    }

    cout << ans;
    
}
 
 
