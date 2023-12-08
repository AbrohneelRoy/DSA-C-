//Prime p after Sum S
#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<int> res;

bool isprime(int n){
    int c=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            c++;
        }
    }
    if(c==2){
        return true;
    }
    else{
        return false;
    }
}

void printsol(){
    int l=res.size();
    for(int i=0; i<l; i++){
        cout<<res[i]<<"\t";
    }
    cout<<endl;
}

void psum(int t,int s,int n,int ind){
    if(t==s && n==res.size()){
        printsol();
        return;
    }
    if(t>s || prime.size()==ind){
        return;
    }
    res.push_back(prime[ind]);
    psum(t+prime[ind],s,n,ind+1);
    res.pop_back();
    psum(t,s,n,ind+1);
}

void allprime(int s,int n,int p){
    for(int i=p+1; i<=s; i++){
        if(isprime(i)){
            prime.push_back(i);
        }
    }
    if(prime.size()<n){
        return;
    }
    psum(0,s,n,0);
}

int main(){
    int s,n,p;
    cin>>s>>n>>p;
    allprime(s,n,p);
}
