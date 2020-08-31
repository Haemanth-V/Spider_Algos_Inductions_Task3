#include<bits/stdc++.h>

using namespace std;

//String is traversed and sum of all digits is computed
// Then this sum is converted into another string and the function 
// is recursively called to compute the sum of digits until 
// length of string representing the number is 1 (single digit number)
// The number of times this function is recursively called is returned as 
// the number of times a number can be replaced by the sum of its digits until it contains only 1 digit

int single_digit_sum(string num){
	
	if(num.size()==1)
	  return 0;
	long digit_sum=0;
	for(int i=0; i<num.size();i++)
	    digit_sum += num[i]-'0';
	string num2 = to_string(digit_sum); //Converting sum to a string for recursive call to the recursive_digit_sum() fn
	return 1+single_digit_sum(num2);
}

main(){
	string number; //String to store the very large number
	getline(cin,number);
	cout<<single_digit_sum(number);
}
