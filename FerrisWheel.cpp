#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, s; cin >> n >> s;
    vector<int> a(n); for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int i = 0, j = a.size() - 1;
    int ans = 0;
    while (i <= j){
        if (i == j) {
            ans ++; 
            break;
        }
 
        if (a[i] + a[j] <= s) ans ++, i ++, j --;
        else ans ++, j --;
    }
 
    cout << ans;
}
 
 
