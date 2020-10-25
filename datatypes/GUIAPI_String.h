#ifndef __GUIAPI_STRING__
#define __GUIAPI_STRING__

#include "string.h"
#include "stdint.h"
#include "stdlib.h"

class GUIAPI_String{
public:
    GUIAPI_String();
    GUIAPI_String(const char* newString);
    GUIAPI_String(const char* newString, uint32_t stringLength);
    ~GUIAPI_String();

    const char* c_str() { return stringData; }
    void assign(char chr);
    void empty();
    void clear();

    uint32_t length() { return stringLength; }

    GUIAPI_String& operator=(const GUIAPI_String& nString){
        free(this->stringData);
        this->stringData = (char*)calloc(nString.stringLength, sizeof(char));
        memcpy(this->stringData, nString.stringData, nString.stringLength);
        this->stringLength = nString.stringLength;
        return *this;
    }

    GUIAPI_String& operator=(const char* constCharData){
        this->stringLength = strlen(constCharData);
        free(stringData);
        stringData = (char*)calloc(stringLength, sizeof(char));
        memcpy(this->stringData, constCharData, this->stringLength);
        return *this;
    }

    GUIAPI_String& operator+=(const char chr){
        assign(chr);
        return *this;
    }

    bool operator==(const GUIAPI_String& nString){
        return strcmp(this->stringData, nString.stringData) == 0;
    }

    bool operator!=(const GUIAPI_String& nString){
        return strcmp(this->stringData, nString.stringData) != 0;
    }

    char& operator[](uint32_t index){
        if(index > 0 && index < stringLength){
            return stringData[index];
        }
    }

private:
    char* stringData;
    uint32_t stringLength;
};

#endif