#include<iostream>
using namespace std;
int r,c,arr[100][100];

void cost(){
    for(int i=1; i<r; i++){
        arr[i][0]+=arr[i-1][0];
    }
    for(int i=1; i<c; i++){
        arr[0][i]+=arr[0][i-1];
    }
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            arr[i][j]+=min(arr[i-1][j],arr[i][j-1]);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<arr[r-1][c-1];
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }
    cost();
}

// 3 4
// 1 1 1 2
// 1 3 3 1
// 2 5 1 1