#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    
    if (a[0] > 1) return cout << 1, 0;
    int sum = 1;
    for (int i = 0; i < n; i ++){
        if (sum < a[i]) return cout << sum, 0;
        sum += a[i];
    }
    
    cout << sum;

}
 
 
