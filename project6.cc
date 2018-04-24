//Tennessee Bonner
//tcb150030@utdallas.edu
//

#include <iostream>
#include "cdk.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{

  WINDOW *window;
  CDKSCREEN *cdkscreen;
  CDKMATRIX *myMatrix;           // CDK Screen Matrix

  // Remember that matrix starts out at 1,1.
  // Since arrays start out at 0, the first entries
  // below ("R0", and "C0") are just placeholders
  // 
  // Finally... make sure your arrays have enough entries given the
  // values you choose to set for MATRIX_WIDTH and MATRIX_HEIGHT
  // above.

  const char *rowTitles[] = {"R0", "a", "b", "c", "d", "e"};
  const char *columnTitles[] = {"C0", "a", "b", "c"};
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

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

  setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
  drawCDKMatrix(myMatrix, true);    /* required  */

  unsigned char x;
  cin >> x;
  
  endCDK();
}
