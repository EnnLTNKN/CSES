#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, s; cin >> n >> s;
    #define pii pair<int, int>
    vector<pii> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i].first, a[i].second = i + 1;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i ++){
        if (a[i].first >= s - a[i].first){
            int l = 0, r = i - 1, j = -1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (a[mid].first > s - a[i].first) r = mid - 1;
                else if (a[mid].first < s - a[i].first) l = mid + 1;
                else {
                    j = mid;
                    break;
                }
            }

            if (j != -1) return cout << a[j].second << " " << a[i].second, 0;
        }
    }

    cout << "IMPOSSIBLE";

}
 
 
