#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int parent(vector<int>& root, int x){
    if(root[x]==x) return x;
 
    return root[x] = parent(root,root[x]);
}
 
int main(){
 
    int n,m;
    cin>>n>>m;
 
    vector<int>root(n+1);
    for(int i=0;i<=n;i++){
        root[i] = i;
    }
 
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
 
        int r1 = parent(root,x);
        int r2 = parent(root,y);
 
        root[r1]=r2;
    }
 
    vector<int> connect;
    for(int i=1;i<=n;i++){
        if(root[i]==i){
            connect.push_back(i);
        }
    }
 
    cout<<connect.size()-1<<endl;
    for(int i=0;i<connect.size()-1;i++){
        cout<<connect[i]<<" "<<connect[i+1]<<endl;
    }
 
    return 0;
}