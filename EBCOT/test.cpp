#include <iostream>
using namespace std;


void test(int a[], int w, int h);

int main()
{


}


void test(int a[], int w, int h) {

	// int b[w][h];

	int** b = new int *[w];
	for (int i = 0; i < w; i++) {
		b[i] = new int[h];
	}



	b[1][2] = 5;


	delete * b;
}

