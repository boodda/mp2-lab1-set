#include<iostream>
#include "tbitfield.h"
using namespace std;
int main(){
    TBitField bf1(35),bf2(35);
	  bf1.SetBit(1);
	  bf2.SetBit(1);
	  bf1.SetBit(33);
	  bf2.SetBit(34);
	cout<<(bf1!=bf2)<<endl;
    return 0;
}
