#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a=0;
void get(ll t,ll c, vector<vector<ll>> &ans,ll th,ll p ,ll h){

    // cout<<t<<" "<<c<<" "<<th<<" "<<p<<" "<<h<<"\n";
    if(t<0 || c<0)
        return;
    else if(c==0){
        ans.push_back({th,p,h});
        return;
    }

    get(t-5,c-(t-5)*1500,ans,th+1,p,h);
    get(t-4,c-(t-4)*1000,ans,th,p+1,h);
    get(t-10,c-(t-10)*3000,ans,th,p,h+1);

}

void answer(){
    ll t,c;
    cin>>t>>c;

    vector<vector<ll>> ans;

    get(t,c,ans,0,0,0);

    for(auto k : ans){
        cout<<"T : "<<k[0]<<" "<<"P : "<<k[1]<<" "<<"C : "<<k[2]<<" \n";
    }
    
}
int main() 
{

    ll cases=1;

    while(cases--)
        answer();

}
