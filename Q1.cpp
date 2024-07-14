#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 1e9+7;

int main(){

    int n,x;
    cin>>n>>x;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    for(int i=n-1; i>=0;i--){
        for(int j = 1; j<=x;j++){
            int cnt = 0;
            cnt = (cnt + dp[i+1][j])%mod;

            if(v[i]<=j)cnt = (cnt + dp[i][j-v[i]])%mod;

            dp[i][j] = cnt;
        }
    }
    
    cout<<dp[0][x]<<endl;

    return 0;

}