//************************************************
// Function:		DecodeMagnitudeRefinementCoding
// Editor:			Shi Gang
// Creat at:		2021-08-04 16:38:29
// Last edit time:	2021-08-04 16:57:08
//************************************************


#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int BAND_WIDTH = 360;
const int BAND_LENGTH = 480;


void DecodeMagnitudeRefinementCoding(int VP[BAND_WIDTH][BAND_LENGTH], int m,int  n,int D,int CX);


void DecodeMagnitudeRefinementCoding(int VP[BAND_WIDTH][BAND_LENGTH], int m, int  n, int D, int CX) {

	if (CX > 16 || CX < 14) {
		cout << "Wrong use of Magnitude Refinement Coding, wrong CX!" << endl;
	}
	VP[m][n] = D;

}
