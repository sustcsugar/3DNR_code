//************************************************
// Function:		RunLengthCoding
// Editor:			Shi Gang
// Creat time:		2021-07-23 17:47:38
// Last edit time:	2021-07-27 15:30:22
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


void RunLengthCoding(int D[2], int CX[2], int N, int VP[BAND_WIDTH][BAND_LENGTH], int m, int n);



//function declaraation: MagnitudeRefinementCoding
void RunLengthCoding(int D[2], int CX[2], int N, int VP[BAND_WIDTH][BAND_LENGTH], int m, int n)
{

	if (VP[m][n] == 0 && VP[m + 1][n] == 0 && VP[m + 2][n] == 0 && VP[m + 3][n] == 0) {
		N = 4;
		D[0] =0;
		D[1] =0;
		D[2] =0;
		CX[0] = 17;
		CX[1] = 17;
		CX[2] = 17;
	}

	if (VP[m][n] == 1) {
		N = 1;
		D[0] = 1;
		D[1] = 0;
		D[2] = 0;
		CX[0] = 17;
		CX[1] = 18;
		CX[2] = 18;
	}

	if (VP[m][n] == 0 && VP[m+1][n] == 1) {
		N = 2;
		D[0] = 1;
		D[1] = 0;
		D[2] = 1;
		CX[0] = 17;
		CX[1] = 18;
		CX[2] = 18;
	}

	if (VP[m][n] == 0 && VP[m + 1][n] == 0 && VP[m + 2][n]==1) {
		N = 3;
		D[0] = 1;
		D[1] = 1;
		D[2] = 0;
		CX[0] = 17;
		CX[1] = 18;
		CX[2] = 18;
	}


	if (VP[m][n] == 0 && VP[m + 1][n] == 0 && VP[m + 2][n] == 0 && VP[m + 3][n] == 1) {
		N = 4;
		D[0] = 1;
		D[1] = 1;
		D[2] = 1;
		CX[0] = 17;
		CX[1] = 18;
		CX[2] = 18;
	}

	
}