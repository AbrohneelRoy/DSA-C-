#include<bits/stdc++.h>
using namespace std;
int v,w,ar[100][100];
const int INF=999;

void func(){
    int i,j,k;
    for(k=0; k<v; k++){
        for(i=0; i<v; i++){
            for(j=0; j<v; j++){
                if(ar[i][j]>ar[i][k]+ar[k][j]){
                    ar[i][j]=ar[i][k]+ar[k][j];
                }
            }
        }
    }
    if(w>v){
        cout<<"Unknown Vertex";
    }
    else{
        cout<<"Minimum distance to reach "<<w<<" from 1 is "<<ar[0][w-1];
    }
}

int main(){
    cin>>v;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cin>>ar[i][j];
        }
    }
    cin>>w;
    func();
}
