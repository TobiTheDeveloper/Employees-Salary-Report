/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

/*****************************************************************************
                        Workshop 2 - Part 1
Full Name  : Yusuff Oyediran
Student ID#: 142813203
Email      : yooyediran@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include <cstring>
using namespace std;
namespace sdds {
    FILE* fptr; 
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }


    bool read(char*& empName) {
        char getStr[128] = "\0";
        bool success = false;

        if (fscanf(fptr, "%127[^\n]\n", getStr)) {
            size_t nameLen = strlen(getStr) + 1;
            empName = new char[nameLen];
            strncpy(empName, getStr, nameLen - 1);
            empName[nameLen - 1] = '\0';
            success = true;
        }
        return success;
    }


    bool read(int& empNo) {
        return fscanf(fptr, "%d,", &empNo);
    }

    bool read(double& empSalary) {
        return fscanf(fptr, "%lf,", &empSalary) == 1;
    }


}