#include <iostream>

using std::cout;

bool perfect_number_checker(int n){

 int sum = 1;
 for(int i = 2; i*i <= n; i++){
	if(n % i == 0){
	   if(i*i != n)
		sum+=(i + n/i);
	   else
		sum+=i;	
	}	
  }
  if(sum == n && n != 1)
	return true;

  return false;
}

int main(void){
 
 for(int i = 0; i < 1000; i++){
 	bool result = perfect_number_checker(i);
	if(result)
		cout << i <<  " is a perfect number\n";
  }
 
 return 0;
}
