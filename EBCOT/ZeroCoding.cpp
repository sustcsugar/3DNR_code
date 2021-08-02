//************************************************
// Function:		ZeroCoding_V1
// Editor:			Shi Gang
// Last edit time:	2021-07-27 15:29:39
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
void ZeroCoding(int D, int CX, int N, int VP[BAND_WIDTH][BAND_LENGTH], int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int m, int n, char Band_Mark);



//function declaraation: MagnitudeRefinementCoding
void ZeroCoding(int D, int CX, int N, int VP[BAND_WIDTH][BAND_LENGTH], int S1[CODEBLOCK_WIDTH][CODEBLOCK_LENGTH], int m, int n, char Band_Mark)
{
	D = VP[m][n];
	N = 1;
	
	int S1_extendZC[CODEBLOCK_WIDTH + 4][CODEBLOCK_LENGTH + 2];
	memset(S1_extendZC, 0, sizeof(S1_extendZC));

	for (int i = 0; i < CODEBLOCK_WIDTH; i++) {
		for (int j = 0; j < CODEBLOCK_LENGTH; j++) {
			S1_extendZC[i + 1][j + 1] = S1[i][j];
		}
	}

	int sumH = S1_extendZC[m + 1][n] + S1_extendZC[m + 1][n + 2];
	int sumV = S1_extendZC[m][n + 1] + S1_extendZC[m + 2][n + 1];
	int sumD = S1_extendZC[m][n] + S1_extendZC[m][n + 2] + S1_extendZC[m + 2][n] + S1_extendZC[m + 2][n + 2];


	//LL and LH band
	if (Band_Mark == 'LL' || Band_Mark == 'LH') {
		if (sumH == 2) {
			CX = 8;
		}
		else if (sumH == 1 && sumV >= 1) {
			CX = 7;
		}
		else if (sumH == 1 && sumV >= 0 && sumD >= 1)
		{
			CX = 6;
		}
		else if (sumH == 1 && sumV == 0 && sumD == 0)
		{
			CX = 5;
		}
		else  if (sumH == 0 && sumV == 2) 
		{
			CX = 4;
		}
		else if (sumH == 0 && sumV == 1)
		{
			CX = 3;
		}
		else if (sumH == 0 && sumV == 0 && sumD >= 2)
		{
			CX = 2;
		}
		else if (sumH == 0 && sumV == 0 && sumD == 1)
		{
			CX = 1;
		}
		else if (sumH == 0 && sumV == 0 && sumD == 0)
		{
			CX = 0;
		}
		else
		{
			cout << "Some shit happens in ZeroCoding process with wrong sumH, sumV or sumD values in LL / LH" << endl;
		}
	}


	//HL band
	if (Band_Mark == 'HL') {

		if (sumV == 2){
			CX = 8;
		}else if( sumH >= 1 && sumV == 1) {
			CX = 7;
		}else if( sumH == 0 && sumV == 1 && sumD >= 1) {
			CX = 6;
		}else if( sumH == 0 && sumV == 1 && sumD == 0) {
			CX = 5;
		}else if( sumH == 2 && sumV == 0) {
			CX = 4;
		}else if( sumH == 1 && sumV == 0) {
			CX = 3;
		}else if( sumH == 0 && sumV == 0 && sumD >= 2) {
			CX = 2;
		}else if( sumH == 0 && sumV == 0 && sumD == 1) {
			CX = 1;
		}
		else if (sumH == 0 && sumV == 0 && sumD == 0) {
			CX = 0;
		}
		else {
			cout << "Some shit happens in ZeroCoding process with wrong sumH, sumV or sumD values in HL!" << endl;
		}
	}


	//HH band

	if (BAND_LENGTH == 'HH') {
		if (sumD >= 3){
				CX = 8;
		}else if( sumH + sumV >= 1 && sumD == 2){
			CX = 7;
		}else if( sumH + sumV == 0 && sumD == 2){
			CX = 6;
		}else if( sumH + sumV >= 2 && sumD == 1){
			CX = 5;
		}else if( sumH + sumV == 1 && sumD == 1){
			CX = 4;
		}else if( sumH + sumV == 0 && sumD == 1){
			CX = 3;
		}else if( sumH + sumV >= 2 && sumD == 0){
			CX = 2;
		}else if( sumH + sumV == 1 && sumD == 0){
			CX = 1;
		}else if (sumH + sumV == 0 && sumD == 0) {
			CX = 0;
		}
		else {
			cout << "Some shit happens in ZeroCoding process with wrong sumH, sumV or sumD values in HH!" << endl;
		}
	}

}