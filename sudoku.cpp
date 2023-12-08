#include<iostream>
using namespace std;
const int n=9;
int grid[n][n];

bool safe(int r,int c,int s){
    for(int i=0; i<n; i++){
        if(grid[r][i]==s){
            return false;
        }
        if(grid[i][c]==s){
        	return false;
		}
    }

    int sr=r-r%3;
    int sc=c-c%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[sr+i][sc+j]==s){
                return false;
            }
        }
    }
    return true;
}

void printsol(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool salg(){
    int r,c;
    bool f=false;
    for(r=0; r<n; r++){
        for(c=0; c<n; c++){
            if(grid[r][c]==0){
                f=true;
                break;
            }
        }
        if(f){
            break;
        }
    }
    if(!f){
        return true;
    }
    for(int i=1; i<=n; i++){
        if(safe(r,c,i)){
            grid[r][c]=i;
            if(salg()){
                return true;
            }
            grid[r][c]=0;
        }
    }
    return false;
}

int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    if(salg()){
        printsol();
    }
    else{
        cout<<"Not possible";
    }
}

// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0 
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0
