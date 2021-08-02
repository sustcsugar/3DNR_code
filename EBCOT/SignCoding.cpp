//************************************************
// Function:		SignCoding_V1
// Editor:			Shi Gang
// Last edit time:	2021-07-27 15:29:15
//************************************************

#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int SIGNARRAY_WIDTH = 4;
const int SIGNARRAY_LENGTH = 480;

//function prototype
// VP: the Pth bitplane
// assume the length of the codeblock is 480
void SignCoding(int D, int CX, int N, int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int m, int n, int sign_array[SIGNARRAY_WIDTH][SIGNARRAY_LENGTH]);



//function declaraation: MagnitudeRefinementCoding
void SignCoding(int D, int CX, int N, int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int m, int n, int sign_array[SIGNARRAY_WIDTH][SIGNARRAY_LENGTH]) {

	N = 1;

	int S1_extendSC[CODEBLOCK_WIDTH+2][CODEBLOCK_LENGTH+2];
	memset(S1_extendSC, 0, sizeof(S1_extendSC));
	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extendSC[i + 1][j + 1] = S1[i][j];
		}
	}



	int S1_extendSA[SIGNARRAY_WIDTH + 2][SIGNARRAY_LENGTH + 2];
	memset(S1_extendSA, 0, sizeof(S1_extendSA));
	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extendSA[i + 1][j + 1] = sign_array[i][j];
		}
	}


	int H, V, H_temp,V_temp, H_max, V_max;

	H_temp = S1_extendSC[m + 1][n] * (1 - 2 * S1_extendSA[m + 1][n]) + S1_extendSC[m + 1][n + 2] * (1 - 2 * S1_extendSA[m + 1][n + 2]);
	V_temp = S1_extendSC[m][n + 1] * (1 - 2 * S1_extendSA[m][n + 1]) + S1_extendSC[m + 2][n + 1] * (1 - 2 * S1_extendSA[m + 2][n + 1]);

	if (-1 > H_temp) {
		H_max = -1;
	}
	else {
		H_max = H_temp;
	}

	if (1 < H_max) {
		H = 1;
	}
	else {
		H = H_max;
	}


	if (-1 > V_temp) {
		V_max = -1;
	}
	else {
		V_max = V_temp;
	}

	if (1 < V_max) {
		V = 1;
	}
	else {
		V = V_max;
	}
	
	int sign_prime;

	if (H == 1 && V == 1) {
		sign_prime = 0;
		CX = 13;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == 1 && V == 0) {
		sign_prime = 0;
		CX = 12;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == 1 && V == -1) {
		sign_prime = 0;
		CX = 11;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == 0 && V == 1) {
		sign_prime = 0;
		CX = 10;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == 0 && V == 0) {
		sign_prime = 0;
		CX = 9;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == 0 && V == -1) {
		sign_prime = 1;
		CX = 10;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == -1 && V == 1) {
		sign_prime = 1;
		CX = 11;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == -1 && V == 0) {
		sign_prime = 1;
		CX = 12;
		D = sign_prime ^ sign_array[m][n];
	}
	else if (H == -1 && V == -1) {
		sign_prime = 1;
		CX = 13;
		D = sign_prime ^ sign_array[m][n];
	}
	else {
		cout << "Some shit happens in function SignCoding with wrong H,V values" << endl;
	}



}
