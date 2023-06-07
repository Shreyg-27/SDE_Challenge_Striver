// #include<stack>
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     // Write your code here.
//     stack<int> st;
//     st.push(-1);
//     vector<int> ans;
//     for (int i=n-1;i>=0;i--){
//         if (st.top()<arr[i]){
//             ans[i] = st.top();
//             st.push(arr[i]);
//         }
//         else{
//             while (st.top()>=arr[i]){
//                 st.pop();
//             }
//             // after removing all the greater elements 
//             // nect smaller element obtained. 
//             ans[i] = st.top();
//             st.push(arr[i]);
//         }
//     }
//     return ans;
// }

#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Approach Using Stack
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        if(stack.top() < arr[i]){
            ans[i] = stack.top();
            stack.push(arr[i]);
        }
        else{
            while(stack.top() >= arr[i]){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(arr[i]);
        }
    }
    return ans;
}
