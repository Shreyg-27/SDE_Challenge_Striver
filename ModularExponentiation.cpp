#include <bits/stdc++.h>

long long int solve(int x,int n,int m){

    if(n==0) return 1;

 

        long long int ans = solve(x,n/2,m);

        if(n<0){

            //went inside

            cout<<"went inside"<<endl;

            if(n&1){

                return ((ans * ans) /x)%m;

            } else {

                return (ans * ans)%m;

            }

        } else {

            if(n&1){ //odd

                return (((ans * ans)%m) * x)%m;

            } else {

                return (ans * ans)%m;

            }

        }

}

int modularExponentiation(int x, int n, int m) {

    // Write your code here.

    return solve(x,n,m)%m;

}
