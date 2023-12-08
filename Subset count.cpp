#include<iostream>
using namespace std;
int subsum=0;

void sums(int list[],int n,int sum,int si,int tsum){
    if(sum==tsum){
        subsum++;
        if(si<n){
            sums(list,n,sum-list[si-1],si,tsum);
        }
    }
    else{
        for(int i=si; i<n; i++){
            sums(list,n,sum+list[i],i+1,tsum);
        }
    }
}

int main(){
    int n,sum;
    cin>>n;
    int list[n];
    for(int i=0; i<n; i++){
        cin>>list[i];
    }
    cin>>sum;
    sums(list,n,0,0,sum);
    cout<<subsum;
}

// 5 
// 1 2 3 4 5
// 9