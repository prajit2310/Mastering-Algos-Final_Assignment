#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
 
    int n,m;
    cin>>n>>m;
 
    vector<vector<pair<int,long long>>>v(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        long long c;
        cin>>x>>y>>c;
        v[x].push_back({y,c});
    }
 
    vector<bool> chk(n+1,false);
    vector<long long> ans(n+1,1e18+7);
    ans[1]=0;
    priority_queue<pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
 
    pq.push({0,1});
    while(!pq.empty()){
        auto [wt,ver] = pq.top();
        pq.pop();
 
        if(chk[ver])continue;
        chk[ver]=true;
 
        for(auto it : v[ver]){
            if(wt+it.second < ans[it.first]){
                ans[it.first] = wt+it.second;
                pq.push({wt+it.second,it.first});
            }
        }
    }
 
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
 
    return 0;
}