/*
===============================================================================

  FILE:  laspointwriter1raw.h
  
  CONTENTS:
  
    Writes a point of type 1 (with gps_time) in standard LAS format 1.1

  PROGRAMMERS:
  
    martin isenburg@cs.unc.edu
  
  COPYRIGHT:
  
    copyright (C) 2007  martin isenburg@cs.unc.edu
    
    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    7 September 2008 -- updated to support LAS format 1.2 
    21 February 2007 -- created after having the longest talk ever with my aunt
  
===============================================================================
*/
#ifndef LAS_POINT_WRITER_1RAW_H
#define LAS_POINT_WRITER_1RAW_H

#include "laspointwriter.h"

#include <stdio.h>

#ifdef _WIN32
#include "ifile.h"

#define myFILE IFILE
#define fopen ifopen
#define fread ifread
#define fwrite ifwrite
#define fseek ifseek

#else

#define myFILE FILE

#endif

class LASpointWriter1raw : public LASpointWriter
{
public:
  inline bool write_point(LASpoint* point, double gps_time = 0, unsigned short* rgb = 0)
  {
    fwrite(point, sizeof(LASpoint), 1, file);
    return (fwrite(&(gps_time), sizeof(double), 1, file) == 1);
  }
  LASpointWriter1raw(myFILE* file){this->file = file;};
  ~LASpointWriter1raw(){};
private:
  myFILE* file;
};

#endif
