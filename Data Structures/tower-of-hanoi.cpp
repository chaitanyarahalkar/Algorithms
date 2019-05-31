#include <iostream>

using std::cout;

void tower_of_hanoi(int n,char x,char y,char z){

	if(n > 0){
		tower_of_hanoi(n-1,x,z,y);
		cout << x << "->" << y << "\n";
		tower_of_hanoi(n-1,z,y,x);
	}

}
int main(void){

	int n = 5;
	
	tower_of_hanoi(5,'a','b','c');


	return 0;
}