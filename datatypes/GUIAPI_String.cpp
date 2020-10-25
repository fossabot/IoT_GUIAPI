#include "GUIAPI_String.h"

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(){
    stringLength = 10;
    stringData = (char*)calloc(stringLength, sizeof(char));
}

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(const char* newString){
    this->stringLength = strlen(newString);
    this->stringData = (char*)calloc(this->stringLength, sizeof(char));
    if(this->stringData != nullptr) memcpy(this->stringData, newString, this->stringLength);
}

/*****************************************************************************************/
GUIAPI_String::GUIAPI_String(const char* newString, uint32_t stringLength){
    this->stringLength = stringLength;
    this->stringData = (char*)calloc(this->stringLength, sizeof(char));
    if(this->stringData != nullptr) memcpy(this->stringData, newString, this->stringLength);
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