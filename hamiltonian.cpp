#include<iostream>
using namespace std;
int graph[100][100],n,path[100];

bool safe(int x,int p){
    if(graph[path[p-1]][x]==0){
        return false;
    }
    for(int i=0; i<p; i++){
        if(path[i]==x){
            return false;
        }
    }
    return true;
}

void printsol(){
     for(int i=0; i<n; i++){
        cout<<path[i]<<" ";
     }
     cout<<path[0];
}

bool halg(int p){
    if(p==n){
        if(graph[path[p-1]][path[0]]==1){
            return true;
        }
        return false;
    }
    for(int i=1; i<n; i++){
        if(safe(i,p)){
            path[p]=i;
            if(halg(p+1)){
                return true;
            }
            path[p]=-1;
        }
    }
    return false;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        path[i]=-1;
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    path[0]=0;
    if(halg(1)){
        printsol();
    }
    else{
        cout<<"no";
    }
}

// 5
// 0 1 0 1 0
// 1 0 1 1 1
// 0 1 0 0 1
// 1 1 0 0 1
// 0 1 1 1 0
