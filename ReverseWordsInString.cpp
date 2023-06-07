// #include<bits/stdc++.h>
// string reverseString(string &str){
// 	// Write your code here.	
// 	// stack approach 
// 	str+=" ";
// 	stack<string> st;
// 	string ans = "";
// 	for (int i=0;i<str.length();i++){
// 		if (str[i]==' '){
// 			st.push(ans);
// 			ans = "";
// 		}
// 		else{
// 			ans+=str[i];
// 		}
// 	}
// 	string final_ans = "";
// 	while (st.size()!=1){
// 		final_ans += st.top()+" ";
// 		st.pop();
// 	}
// 	final_ans += st.top(); // last word should not have a space
// 	return final_ans;

// }

#include <bits/stdc++.h>
string reverseString(string &str){
	// Write your code here.
	stack<string>st;
	for(int i=0;i<str.size();i++){
		string word="";
		while(str[i]!=' ' && i<str.size()){
			word+=str[i];
			i++;
		}
		if(!word.empty()){
			st.push(word);
		}
	}
	string ans="";
	while(!st.empty()){
		ans+=st.top();
		ans.push_back(' ');
		st.pop();
	}
	return ans;
}

/// the O(1) space complexity w/o using stack. 
// string reverseString(string &str){
// 	// Write your code here.
// 	int left = 0;
// 	int right = str.length()-1;
// 	string temp = "";
// 	string ans = "";
// 	// add a word in temp 
// 	while (left<=right){
// 		char ch = str[left];
// 		if (ch != ' '){
// 			temp+=ch;
// 		}
// 		else if (ch == ' '){
// 			// if ans != empty , then add a spece else not 
// 			if (ans!=""){
// 				ans = temp + " " + ans; // reverse order word 
// 			}
// 			else{
// 				ans = temp; // start word only then we have to add words infornt of this word
// 			}
// 			temp = "";
// 		}
// 		left++;
// 	}
// 	 if (temp!="") {
//         if (ans!="") ans = temp + " " + ans;
//         else ans = temp;
//     }

// 	return ans;

	
// }





