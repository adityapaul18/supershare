#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a=0;
void get(ll t, ll c, vector<vector<ll>> &ans,ll th,ll p ,ll h){

    // cout<<t<<" "<<c<<" "<<th<<" "<<p<<" "<<h<<"\n";
    a=max(a,c);
    if(t<0)
        return;
    else if(t==0){
        // ans[c].push_back({th,p,h});
        return;
    }

    if(t>=5)
        get(t-5,c+(t-5)*1500,ans,th+1,p,h);
    if(t>=4)
        get(t-4,c+(t-4)*1000,ans,th,p+1,h);
    if(t>=10)
        get(t-10,c+(t-10)*3000,ans,th,p,h+1);

}

void soln(ll t, ll c, vector<vector<ll>> &ans,ll th,ll p ,ll h){
    
    // cout<<t<<" "<<c<<" "<<th<<" "<<p<<" "<<h<<"\n";
    if(t<0)
        return;

    if(c==a){
        ans.push_back({th,p,h});
        return;
    }

    if(t>=5)
        soln(t-5,c+(t-5)*1500,ans,th+1,p,h);
    if(t>=4)
        soln(t-4,c+(t-4)*1000,ans,th,p+1,h);
    if(t>=10)
        soln(t-10,c+(t-10)*3000,ans,th,p,h+1);

}

void answer(){
    ll t,c=0,tn=0;
    cin>>t;

    vector<vector<ll>> ans;

    while(t>10){
        c+=(t-5)*1500;
        t-=5;
        tn++;
    }

    get(t,0,ans,0,0,0);
    soln(t,0,ans,0,0,0);

    cout<<"Earnings : "<<a+c<<" \n";
    for(auto k : ans){
        cout<<"T : "<<k[0]+tn<<" "<<"P : "<<k[1]<<" "<<"C : "<<k[2]<<" \n";
    }
    
}
int main() 
{

    ll cases=1;

    while(cases--)
        answer();

}
