#include<iostream>
#include "tset.h"
#include<cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand(time(0));
    TSet set1(10);
    TSet set2(10);
    cin>>set1>>set2;
    cout<<"set1: "<<set1<<endl;
  	cout<<"set2: "<<set2<<endl;
  	cout<<"set1+set2: "<<(set1+set2)<<endl;
 	cout<<"set1*set2: "<<(set1*set2)<<endl;
 	cout<<"set1+4: "<<(set1+4)<<endl;
	cout<<"~(set2-4): "<<~(set2-4)<<endl;

    return 0;
}
