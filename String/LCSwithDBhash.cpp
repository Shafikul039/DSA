#include<bits/stdc++.h>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>pr;
const ll mod=1e9+7,N=1e5+7;
const ll base1=31,base2=37;
ll po1[N],po2[N],hs1[N],hs2[N],ht1[N],ht2[N];

pr getS(ll i, ll len) {
    ll ans = hs1[i], ans1 = hs2[i];
    if (i - len >= 0) {
        ans = (ans - (hs1[i - len] * po1[len]) % mod + mod) % mod;
        ans1 = (ans1 - (hs2[i - len] * po2[len]) % mod + mod) % mod;
    }
    return {ans, ans1};
}

pr getT(ll i, ll len) {
    ll ans = ht1[i], ans1 = ht2[i];
    if (i - len >= 0) {
        ans = (ans - (ht1[i - len] * po1[len]) % mod + mod) % mod;
        ans1 = (ans1 - (ht2[i - len] * po2[len]) % mod + mod) % mod;
    }
    return {ans, ans1};
}


int main()
{
    fast;
    po1[0]=1;po2[0]=1;
    for(int i=1;i<N;i++){
        po1[i]=(po1[i-1]*base1)%mod;
        po2[i]=(po2[i-1]*base2)%mod;
    }
    ll n;cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        if(i==0){
            hs1[i]=(s[i]-'A'+1);
            hs2[i]=(s[i]-'A'+1);
            ht1[i]=(t[i]-'A'+1);
            ht2[i]=(t[i]-'A'+1);
        }
        else{
            hs1[i]=((hs1[i-1]*base1)+(s[i]-'A'+1))%mod;
            hs2[i]=((hs2[i-1]*base2)+(s[i]-'A'+1))%mod;
            ht1[i]=((ht1[i-1]*base1)+(t[i]-'A'+1))%mod;
            ht2[i]=((ht2[i-1]*base2)+(t[i]-'A'+1))%mod;
        }
    }
    ll l=0,r=n,len=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        vector<pr>tmp;
        for(int i=mid-1;i<n;i++){
            tmp.pb(getS(i,mid));
        }
        sort(all(tmp));
        ll exist=0,e;
        for(int i=mid-1;i<n;i++){
            pr com=getT(i,mid);
            auto it=lower_bound(all(tmp),com);
            if(it!=tmp.end() && *it==com){
                exist=1;
                break;
            }
        }
        if(exist){
            l=mid+1;
            len=mid;
        }
        else r=mid-1;
    }
    vector<pr>v;
    for(int i=len-1;i<n;i++)v.pb(getS(i,len));
    sort(all(v));
    string ans;
    for(int i=len-1;i<n;i++){
        pr com=getT(i,len);
        auto it=lower_bound(all(v),com);
        if(it!=v.end() && *it==com){
            ans=t.substr(i-len+1,len);
            break;
        }
    }
    cout<<ans<<endl;
}
