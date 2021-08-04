//************************************************
// Function:		DecodeRunlengthCoding
// Editor:			Shi Gang
// Creat at:		2021-08-04 16:38:29
// Last edit time:	2021-08-04 16:53:28
//************************************************


#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int BAND_WIDTH = 360;
const int BAND_LENGTH = 480;

//function prototype
// VP: the Pth bitplane
// assume the length of the codeblock is 480
void DecodeRunlengthCoding(int EncodeLength, int VP[BAND_WIDTH][BAND_LENGTH], int m, int n, int D[2], int CX[], int N);



void DecodeRunlengthCoding(int EncodeLength, int VP[BAND_WIDTH][BAND_LENGTH], int m, int n, int D[2], int CX[], int N) {
	
	for (int i = 0; i < N - 1; i++) {
		if (CX[i] < 17 || CX[i]>18) {
			cout << "Wrong CX value input for RLC decoding" << endl;
		}
	}

	if (D[1] == 0) {
		EncodeLength = 4;
		VP[m][n] = 0;
		VP[m + 1][n] = 0;
		VP[m + 2][n] = 0;
		VP[m + 3][n] = 0;
	}
	else if (D[0]==1 && D[1]==0 && D[2]==1) {
		VP[m][n] = 0;
		VP[m + 1][n] = 1;
		EncodeLength = 2;
	}
	else if (D[0] == 1 && D[1] == 1 && D[2] == 0) {
		VP[m][n] = 0;
		VP[m + 1][n] = 0;
		VP[m + 2][n] = 1;
		EncodeLength = 3;
	}
	else if (D[0] == 1 && D[1] == 1 && D[2] == 1) {
		VP[m][n] = 0;
		VP[m + 1][n] = 0;
		VP[m + 2][n] = 0;
		VP[m + 3][n] = 1;
		EncodeLength = 4;
	}
	else if (D[0] == 1 && D[1] == 0 && D[2] == 0) {
		VP[m][n] = 1;
		EncodeLength = 1;
	}
	else 
		cout << "ERROR:Wrong D value in RLC Decoding!" << endl;


}