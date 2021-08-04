//************************************************
// Function:		DecodeZeroCoding
// Editor:			Shi Gang
// Creat at:		2021-08-04 16:33:14
// Last edit time:	2021-08-04 16:36:13
//************************************************

#include <iostream>
using namespace std;


const int CODEBLOCK_WIDTH = 4;
const int CODEBLOCK_LENGTH = 480;
const int BAND_WIDTH = 360;
const int BAND_LENGTH = 480;


/*


*/

void DecodeZeroCoding(int VP[BAND_WIDTH][BAND_LENGTH], int m, int n, int D, int CX);




void DecodeZeroCoding(int VP[BAND_WIDTH][BAND_LENGTH], int m, int n, int D, int CX) {
	if (CX > 8)
		cout << "Wrong decoding for ZeroCoding" << endl;

	VP[m][n] = D;
}