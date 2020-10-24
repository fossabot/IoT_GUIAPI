#ifndef __GUIAPI_STRING__
#define __GUIAPI_STRING__

#include "string.h"
#include "stdint.h"
#include "stdlib.h"

class GUIAPI_String{
public:
    GUIAPI_String();
    GUIAPI_String(uint32_t stringLength);
    GUIAPI_String(const char* newString);
    GUIAPI_String(const char* newString, uint32_t stringLength);
    ~GUIAPI_String();

    const char* toC_str() { return stringData; }

    void setLength(uint32_t newLength);
    uint32_t length() { return stringLength; }

    GUIAPI_String& operator=(const GUIAPI_String& nString){
        char backup[256] = {0};
        memcpy(backup, this->stringData, this->stringLength);
        this->stringLength = nString.stringLength;
        free(stringData);
        stringData = (char*)calloc(this->stringLength, sizeof(char));
        memcpy(this->stringData, backup, this->stringLength);
        return *this;
    }

    GUIAPI_String& operator=(const char* constCharData){
        memcpy(this->stringData, constCharData, this->stringLength);
        return *this;
    }

    char& operator[](int index){
        if(index > 0 && index < stringLength){
            return stringData[index];
        }
    }

private:
    char* stringData;
    uint32_t stringLength;
};

#endif