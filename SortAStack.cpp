#include <bits/stdc++.h>

void insert(stack<int> &s, int temp){
	if (s.empty() || s.top()<=temp){
		s.push(temp);
		return;
	}
	else{
		int val = s.top();
		s.pop();
		insert(s, temp);
		s.push(val);
		return;
	}

}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if (stack.size()==1){
		return;
	}
	int temp = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,temp);
	return;
}
