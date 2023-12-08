#include<iostream>
using namespace std;

void sundaram(int n){
    int N=(n-1)/2;
    bool arr[N+1];
    for(int i=1; i<=N; i++){
        for(int j=1; i+j+2*i*j<=N; j++){
            arr[i+j+2*i*j]=true;
        }
    }
    if(n>=2){
        cout<<"2 ";
    }
    for(int i=1; i<=N; i++){
        if(!arr[i]){
            cout<<2*i+1<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
    sundaram(n);
}