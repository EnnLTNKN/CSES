#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        s.insert(x);
    }
 
    cout << s.size();
}
