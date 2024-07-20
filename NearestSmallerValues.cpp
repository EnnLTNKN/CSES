#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n; 
    vector<int> a(n); for (int &i: a) cin >> i;
    stack<int> st; vector<int> ans(n, -1);

    for (int i = 0; i < n; i ++){
        while (st.size() && a[st.top()] >= a[i]) st.pop();
        if (st.size()) ans[i] = st.top(); st.push(i);
    }

    for (int i = 0; i < n; i ++) cout << ans[i] + 1 << " ";
}
