#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int cnt[maxn];

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n); for (int &i: a) cin >> i;
    vector<int> c = a; sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());

    for (int &i: a) i = lower_bound(c.begin(), c.end(), i) - c.begin() + 1;
    
    int curDis = 0, j = 0, curNum = 0, ans = 0;
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < n; i ++){

        cnt[a[i]] ++;
        if (cnt[a[i]] == 1) curNum ++;
        if (cnt[a[i]] == 2) curDis ++;

        while (curDis > 0 && j < i){
            cnt[a[j]] --;
            if (cnt[a[j]] == 1) curDis --;
            if (cnt[a[j ++]] == 0) curNum --;
        } 

        ans = max(ans, curNum);
    }

    cout << ans;
}
 
