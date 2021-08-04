//************************************************
// Function:		DecodeSignCoding
// Editor:			Shi Gang
// Creat at:		2021-08-02 16:08:20
// Last edit time:	2021-08-04 16:25:12
//************************************************

#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int BAND_WIDTH = 360;
const int BAND_LENGTH = 480;


/*
SignArray:	the dimension is the same with BAND.
DeS1:		the dimension is 4 * band_length.

*/

void DecodeSignCoding(int SignArray_out[BAND_WIDTH][BAND_LENGTH],int m, int n, int D, int CX, int SignArray_in[BAND_WIDTH][BAND_LENGTH], int DeS1[4][BAND_LENGTH]);




void DecodeSignCoding(int SignArray_out[BAND_WIDTH][BAND_LENGTH], int m, int n, int D, int CX, int SignArray_in[BAND_WIDTH][BAND_LENGTH], int DeS1[4][BAND_LENGTH]) {

	SignArray_out = SignArray_in;

	//extend DeS1 and SignArray, initial with 0.
	int S1_extendSC[CODEBLOCK_WIDTH + 2][CODEBLOCK_LENGTH + 2];
	memset(S1_extendSC, 0, sizeof(S1_extendSC));
	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extendSC[i + 1][j + 1] = DeS1[i][j];
		}
	}

	int S1_extendSA[CODEBLOCK_WIDTH + 2][CODEBLOCK_LENGTH + 2];
	memset(S1_extendSA, 0, sizeof(S1_extendSA));
	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extendSC[i + 1][j + 1] = SignArray_in[i][j];
		}
	}


	int H_max, H_min;
	int V_max, V_min;

	H_max = S1_extendSC[m + 1][n] * (1 - 2 * S1_extendSA[m + 1][n]) + S1_extendSC[m+1][n+2]*(1-2*S1_extendSA[m+1][n+2]);
	V_max = S1_extendSC[m][n + 1] * (1 - 2 * S1_extendSA[m][n + 1]) + S1_extendSC[m+2][n+1]*(1-2*S1_extendSA[m+2][n+1]);


	if (H_max < -1) {
		H_max = -1;
	}

	if (V_max < -1) {
		V_max = -1;
	}

	if (1 > H_max) {
		H_min = H_max;
	}
	else {
		H_min = 1;
	}

	if (1 > H_max) {
		H_min = H_max;
	}
	else {
		H_min = 1;
	}

	int H = H_min;
	int V = V_min;
	int SignPrime;

	if (H == 1 && V==1) {
		SignPrime = 0;
		if (CX != 13) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}

	if (H == 1 && V == 0) {
		SignPrime = 0;
		if (CX != 12) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}


	if (H == 1 && V == -1) {
		SignPrime = 0;
		if (CX != 11) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}

	if (H == 0 && V == 1) {
		SignPrime = 0;
		if (CX != 10) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}

	if (H == 0 && V == 0) {
		SignPrime = 0;
		if (CX != 9) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}


	if (H == 0 && V == -1) {
		SignPrime = 1;
		if (CX != 10) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}


	if (H == -1 && V == 1) {
		SignPrime = 1;
		if (CX != 11) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}

	if (H == -1 && V == 0) {
		SignPrime = 1;
		if (CX != 12) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}

	if (H == -1 && V == -1) {
		SignPrime = 1;
		if (CX != 13) {
			cout << "Some shit happens in decode SignCoding with wrong CX values " << endl;
		}
		SignArray_out[m][n] = D ^ SignPrime;
	}


}




