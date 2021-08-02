//************************************************
// Function:		MagnitudeRefinementCoding_V1
// Editor:			Shi Gang
// Last edit time:	2021-07-27 15:31:25
//************************************************


#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int BAND_WIDTH= 360;
const int BAND_LENGTH = 480;


//function prototype
// VP: the Pth bitplane
// assume the length of the codeblock is 480
void MagnitudeRefinementCoding(int D, int CX, int N, int VP[BAND_WIDTH][BAND_LENGTH], int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int S2[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int m, int n);



//function declaraation: MagnitudeRefinementCoding
void MagnitudeRefinementCoding(int D, int CX, int N, int VP[BAND_WIDTH][BAND_LENGTH], int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int S2[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH],  int m, int n)
{
	D = VP[m][n];
	N = 1;

	int S1_extend[CODEBLOCK_WIDTH + 4][CODEBLOCK_LENGTH + 2];
	memset(S1_extend, 0, sizeof(S1_extend));

	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extend[i + 1][j + 1] = S1_extend[i][j];
		}
	}

	int temp = S1_extend[m][n+1] + S1_extend[m+2][n+1] + S1_extend[m+1][n+2] + S1_extend[m+1][n];

	if (S2[m][n] == 1) {
		CX = 16;
	}
	else if (S2[m][n] == 0 && temp == 0) {
		CX = 14;
	}
	else {
		CX = 15;
	}

	cout << "Thee result of MagnitudeRefinementCoding:" << endl;
	cout << "D:" << D << endl;
	cout << "N:" << N << endl;
	cout << "CX:" << CX << endl;

}




