#ifndef PROGRAM6_H_
#define PROGRAM6_H_

//Tennessee Bonner
//tcb150030@utdallas.edu
//Project 6
//CS3377.501
//
#include <stdint.h>

class BinaryFileHeader
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

#endif
