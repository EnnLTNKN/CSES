#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &i: a) cin >> i;
    
    function<int(int)> check = [&](int mid){
        int sum = 0, cnt = 1;
        for (auto x: a){
            if (x > mid) return false;
            if (sum + x > mid) cnt ++, sum = x;
            else sum += x; 
        }

        return cnt <= k;
    };

    int l = 0, r = 2e14, ans;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    cout << ans;
}
