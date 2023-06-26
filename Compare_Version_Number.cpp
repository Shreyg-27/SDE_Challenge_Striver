#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    // brute force
    // int n = a.size();
    // int m = b.size();

    // if (n>m){
    //     while (n!=m){
    //         b.push_back('0');
    //     }
    // }
    // else if (m>n){
    //     while (n!=m){
    //         a.push_back('0');
    //     }
    // }
    // for (int i=0;i<n;i++){
    //     if (int(a[i])>int(b[i])){
    //         return 1;
    //         break;
    //     }
    //     else if (int(a[i])<int(b[i])){
    //         return -1;
    //         break;
    //     }
    // }
    // return 0;
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while(i < n or j < m) {
        if(a[i] == '0') 
            while(i < n and a[i] == '0') i++;

        if(b[j] == '0')
            while(j < m and b[j] == '0') j++;

        long long num1 = 0, num2 = 0;

        while(i < n and a[i] != '.') 
            num1 = (num1 * 10) + (a[i++] - '0');

        while(j < m and b[j] != '.')  
            num2 = (num2 * 10) + (b[j++] - '0');

        if(num1 > num2) return 1;
        else if(num1 < num2) return -1;

        i++, j++;
    }

    return 0;
}
