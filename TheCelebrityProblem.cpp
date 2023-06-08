#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	// approach using stack 
	stack<int> stack;
	// push all the elements in the stack 
	for (int i=0;i<n;i++){
		stack.push(i);
	} 
	// now pop 2 elements and check if they know each other 
	// we will keep the potential candidate in the stack and remove all 
	while (stack.size()!=1){
		int a = stack.top();
		stack.pop();
		int b = stack.top();
		stack.pop();
		if (knows(a,b)){ // it means a knows b so b can be the celeb
			stack.push(b);
		}
		else{
			stack.push(a);
		}

	}
	// now the stackl has the potential candidate 
	int ans = stack.top();
	// check if he does not know any one 
	for (int i=0;i<n;i++){
		if (i!=ans){
			if (knows(ans,i)){
				return -1;
			}
		}
	}
	// check if all know him 
	for (int i=0;i<n;i++){
		if (i!=ans){
			if (!knows(i,ans)){
				return -1;
			}
		}
	}
	return ans;
}
