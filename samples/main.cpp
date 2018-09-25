#include<iostream>
#include "tbitfield.h"
#include<cstdlib>
#include <ctime>
using namespace std;
TBitField genRand(){
	int n = rand()%10000;
	TBitField res(n);
	for(int i=0;i<n;i++){
		if(rand()%3==0){
			res.SetBit(i);
		}
	}
	return res;
}
#define kolvo 100000
int main(){
	srand(time(0));
    TBitField bf[kolvo];
    for(int i=0;i<kolvo;i++){
    	bf[i] = genRand();
    }
  	int start = clock();
    for(int i=0;i<kolvo/2;i++){
    	bf[2*i] & bf[2*i+1];
    }
    int end = clock();
    cout << (end - start)<<endl;
    return 0;
}
