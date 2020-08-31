#include<bits/stdc++.h>

using namespace std;

//Logic : Finding the number of prime numbers (num_p) which are less than or equal to input n
// because any two prime numbers are co-prime and should be assigned unique numbers
// if either of a,b in (a,b) is composite then it will have a prime factor p and since it
// is not coprime with p it can take p's Ci value (so as to minimise the sum) and since
// a,b are coprime they dont have any common prime factors and hence they wont be assigned the 
// same colour value
//Sieve of eratosthenes logic is used to find num_p (number of prime numbers less than or equal to input n)

int sieve_of_eratosthenes(int n){
	bool is_prime[n+1];
	fill_n(is_prime, n+1, true);
	int prime_count = 0;
	for(int i=2; i*i<=n; i++)
		if(is_prime[i])
			for(int j=i*i; j<=n; j+=i)
			   is_prime[j]=false;
	for(int i=2; i<=n; i++)
	   if(is_prime[i])
	      prime_count++;
	return prime_count;
}


// If number of prime numbers num_p is known then we can assign each of them a distinct number 
// starting from 1 to num_p. So sum of all such distinct values = num_p*(num_p+1)/2

long sum_of_distinct_ci(int n){
	
	int num = sieve_of_eratosthenes(n);
	return num*(num+1)/2;
}

main(){
	int n;
	cin>>n;
	cout<<sum_of_distinct_ci(n);
}
