#include <bits/stdc++.h>

// int subarraysXor(vector<int> &arr, int x)
// {
//     //    Write your code here.
// Iterate the elements in the array, store the xor value from the beginning to the ith iteration, and store a counter to count the sub arrays with xor value as x.

// If the xorvalue is x increment the counter (0th element to ith element), store an unordered map with xor value as key and has vector to store the position (ith) i.e. it represents those elements having xorvalue as the key which subarray as from the first element to the ith element. if x^y=xorvalue,

// x^y^x=xorvalue^x

// y=xorvalue^x;

// hence we need to find those subarrays who have xorvalue as xorvalue^x.
// }
int subarraysXor(vector<int> &arr, int x)

{

unordered_map<int, vector<int>> valuesofxor;

int xorvalue = 0;

int temp=0;

int counter=0;

for(int i=0; i<arr.size(); i++){

xorvalue = xorvalue ^ arr[i];

if(xorvalue==x){

counter++;

}

temp = xorvalue ^ x;

if (valuesofxor.find(temp) != valuesofxor.end()) {

counter += valuesofxor[temp].size();

}

valuesofxor[xorvalue].push_back(i);

}

return counter;

}

 
