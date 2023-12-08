#include<bits/stdc++.h>
using namespace std;
int graph[100][100],n;

int minkey(int key[],bool set[]){
    int min=INT_MAX,mind;
    for(int i=0; i<n; i++){
        if(set[i]==false && key[i]<min){
            min=key[i];
            mind=i;
        }
    }
    return mind;
}

void printsol(int par[]){
     for(int i=1; i<n; i++){
        cout<<par[i]<<" - "<<i<<" = "<<graph[i][par[i]]<<endl;
     }
}

void pmst(){
    int par[n],key[n];
    bool set[n];
    for(int i=0; i<n; i++){
        key[i]=INT_MAX;
        set[i]=false;
    }
    key[0]=0;
    par[0]=-1;
    for(int i=0; i<n-1; i++){
        int u=minkey(key,set);
        set[u]=true;
        for(int i=0; i<n; i++){
            if(graph[u][i] && set[i]==false && graph[u][i]<key[i]){
                par[i]=u;
                key[i]=graph[u][i];
            }
        }
    }
    printsol(par);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    pmst();
}

// 5
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0