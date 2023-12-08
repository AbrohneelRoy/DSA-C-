#include<bits/stdc++.h>
using namespace std;
int r,c,arr[100][100];

void maxf(){
    int dp[r][c]={0};
    int m=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 || j==0){
                dp[i][j]=arr[i][j];
            }
            else if(arr[i][j]==1){
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
            else{
                dp[i][j]=0;
            }
            if(m<dp[i][j]){
                m=dp[i][j];
            }
        }
    }
    cout<<m<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }
    maxf();
}


// 6 5
// 0 1 1 0 1
// 1 1 0 1 0
// 0 1 1 1 0
// 1 1 1 1 0
// 1 1 1 1 1
// 0 1 1 1 0