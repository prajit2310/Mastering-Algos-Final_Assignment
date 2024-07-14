#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long mod = 1e9+7;

void mul(vector<vector<long long>>& res , vector<vector<long long>>& v){
    
    int n = v.size();
    vector<vector<long long>>temp(n,vector<long long>(n,0));
    long long t = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t = 0;
            for(int k=0;k<n;k++){
                t = (t + (res[i][k] * v[k][j])%mod)%mod;
            }
            temp[i][j] = t;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j] = temp[i][j];
        }
    }

}

int main(){

    long long n,k;
    cin>>n>>k;

    vector<vector<long long>> v(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    vector<vector<long long>> res(n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        res[i][i]=1;
    }

    while(k){
        if(k&1){
            mul(res,v);
        }

        mul(v,v);
        k/=2;
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = (ans+res[i][j])%mod ;
        }
    }

    cout<<ans<<endl;

    return 0;

}