#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, s; cin >> n >> s;

    #define pii pair<int, int>
    vector<int> a(n); vector<pii> b(n);
    for (int i = 0; i < n; i ++) cin >> a[i], b[i].first = a[i], b[i].second = i + 1;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j ++){
            if (s - a[i] - a[j] >= a[j]){
                auto cur = lower_bound(a.begin() + j + 1, a.end(), s - a[i] - a[j]);
                if (cur != a.end() && *cur == s - a[i] - a[j]) \
                    return cout << b[i].second << " " << b[j].second << " " << b[(cur - a.begin())].second, 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}
