//Tennessee Bonner
//tcb150030@utdallas.edu
//Project 6
//CS3377.501
//This program creates a CDK GUI for the user by reading the data from a binary file and then
//writing it to the CDK

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "cdk.h"
#include "project6.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{
  WINDOW *window;
  CDKSCREEN *cdkscreen;
  CDKMATRIX *myMatrix;

  const char *rowTitles[] = {"R0", "a", "b", "c", "d", "e"};
  const char *columnTitles[] = {"C0", "a", "b", "c"};
 
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};


  //Uses an ifstream to open "cs3377.bin" 
  ifstream binaryFile;
  binaryFile.open("cs3377.bin", ios::in | ios::binary);

  //Just incase the ifstream fails
  if (!binaryFile)
  {
    return -1;
  }
  
  //Stores the binary values in the header and records
  BinaryFileHeader *header = new BinaryFileHeader();
  binaryFile.read((char*) header, sizeof(BinaryFileHeader));

  BinaryFileRecord *record1 = new BinaryFileRecord();
  binaryFile.read((char*) record1, sizeof(BinaryFileRecord));
  
  BinaryFileRecord *record2 = new BinaryFileRecord();
  binaryFile.read((char*) record2, sizeof(BinaryFileRecord));

  BinaryFileRecord *record3 = new BinaryFileRecord();
  binaryFile.read((char*) record3, sizeof(BinaryFileRecord));

  BinaryFileRecord *record4 = new BinaryFileRecord();
  binaryFile.read((char*) record4, sizeof(BinaryFileRecord));
  
  binaryFile.close();


  //Initalizes the CDK screen, creates the Matrix and then displays it
  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,    boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  drawCDKMatrix(myMatrix, true);
  

  //Setting the individual cells of the Matrix
  //begins by converting the input into a stringstream of the hexidecimal number
  stringstream hexStringStream;
  hexStringStream << "0x" << std::hex << header->magicNumber;
  //This is then converted into a string
  string hexnumber(hexStringStream.str());
  string magic = "Magic: " + hexnumber;
  //This is AGAIN converted (this time to a c_string)
  setCDKMatrixCell(myMatrix, 1, 1, magic.c_str());

  string version = "Version: " + to_string(header->versionNumber);
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());

  string records = "NumRecords: " + to_string(header->numRecords);
  setCDKMatrixCell(myMatrix, 1, 3, records.c_str());

  
  //The following are for the records
  string record1Len = "strlen: " + to_string(record1->strLength);
  setCDKMatrixCell(myMatrix, 2, 1, record1Len.c_str());
  setCDKMatrixCell(myMatrix, 2, 2, record1->stringBuffer);

  string record2Len = "strlen: " + to_string(record2->strLength);
  setCDKMatrixCell(myMatrix, 3, 1, record2Len.c_str());
  setCDKMatrixCell(myMatrix, 3, 2, record2->stringBuffer);
  
  string record3Len = "strlen: " + to_string(record3->strLength);
  setCDKMatrixCell(myMatrix, 4, 1, record3Len.c_str());
  setCDKMatrixCell(myMatrix, 4, 2, record3->stringBuffer);

  string record4Len = "strlen: " + to_string(record4->strLength);
  setCDKMatrixCell(myMatrix, 5, 1, record4Len.c_str());
  setCDKMatrixCell(myMatrix, 5, 2, record4->stringBuffer);

  drawCDKMatrix(myMatrix, true);

  
  //Waits until a button is pressed then closes the matrix
  unsigned char x;
  cin >> x;
  
  endCDK();
}
