#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    vector<int> used(n + 1); int cnt = 0;
    int t = 0;
    while (cnt < n){
        for (int i = 1; i <= n; i ++){
            if (!used[i]){
                if (t) cout << i << " ", cnt ++, used[i] = 1;
                t ^= 1;
            }
        }

    }
}