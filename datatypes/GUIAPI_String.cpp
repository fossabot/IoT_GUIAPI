#include "GUIAPI_String.h"

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(){
    stringLength = 64;
    stringData = (char*)calloc(stringLength, sizeof(char));
}

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(uint32_t stringLength){
    this->stringLength = stringLength;
    stringData = (char*)calloc(stringLength, sizeof(char));
}

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(const char* newString){
    stringLength = 64;
    stringData = (char*)calloc(stringLength, sizeof(char));
    if(stringData != nullptr) memcpy(stringData, newString, stringLength);
}

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(const char* newString, uint32_t stringLength){
    stringLength = stringLength;
    stringData = (char*)calloc(stringLength, sizeof(char));
    if(stringData != nullptr) memcpy(stringData, newString, stringLength);
}

/*****************************************************************************************/
GUIAPI_String::~GUIAPI_String(){
    free(stringData);
    stringData = 0;
}

/*****************************************************************************************/
void GUIAPI_String::setLength(uint32_t newLength){
    char backup[256] = {0};
    uint32_t oldLength = stringLength;
    memcpy(backup, stringData, stringLength);

    free(stringData);
    stringLength = newLength;
    stringData = (char*)calloc(stringLength, sizeof(char));

    if(stringData != nullptr) memcpy(stringData, backup, oldLength);
}