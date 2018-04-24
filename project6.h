#ifndef PROGRAM6_H_
#define PROGRAM6_H_

//Tennessee Bonner
//tcb150030@utdallas.edu
//Project 6
//CS3377.501
//This is the header file which contains the classes which access the binary file 
//and stores the values appropriately for later use
#include <stdint.h>

class BinaryFileHeader
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

const int maxRecordStringLength = 25;

class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

#endif
