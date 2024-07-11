#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200010
int par[maxn], siz[maxn], val[maxn];
int Find(int u){
    return u == par[u] ? u : par[u] = Find(par[u]);
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    val[a] = val[a] + val[b];
}

map<int, int> pos;
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int s, n; cin >> s >> n;
    vector<int> a(n + 1); for (int i = 1; i <= n; i ++) cin >> a[i];
    vector<int> b = a; sort(b.begin() + 1, b.end()); b.push_back(s);

    int mx = 0;
    for (int i = 1; i < b.size(); i ++){
        pos[b[i]] = i;
        par[i] = i, siz[i] = 1, val[i] = b[i] - b[i - 1];
        mx = max(mx, val[i]);
    }

    vector<int> ans; ans.push_back(mx);
    for (int i = n; i > 1; i --){
        Union(pos[a[i]], pos[a[i]] + 1);
        mx = max(mx, val[Find(pos[a[i]])]);
        ans.push_back(mx);
    }

    reverse(ans.begin(), ans.end());
    for (int i: ans) cout << i << " ";
}

