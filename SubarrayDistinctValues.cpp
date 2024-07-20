#include<bits/stdc++.h>
using namespace std;
#define int long long

map<int, int> mp;
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &i : a) cin >> i;
    int j = 0, num = 0;

    int ans = 0;
    for (int i = 0; i < n; i ++){
        mp[a[i]] ++;
        if (mp[a[i]] == 1) num ++;

        while (j < i && num > k){
            mp[a[j]] --;
            if (mp[a[j]] == 0) num --;
            j ++;
        }
        ans += (i - j + 1);
    }

    cout << ans;
}
