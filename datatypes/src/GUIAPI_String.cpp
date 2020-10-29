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
void GUIAPI_String::assign(char chr){
    char *backup = (char*)calloc(stringLength, sizeof(char));
    memcpy(backup, stringData, stringLength);

    free(stringData);
    stringLength = stringLength + 1;
    stringData = (char*)calloc(stringLength, sizeof(char));
    if(stringData != nullptr) memcpy(stringData, backup, stringLength-1);
    stringData[stringLength-1] = chr;
    free(backup);
}

/*****************************************************************************************/
void GUIAPI_String::empty(){
    free(stringData);
    stringData = 0;
    stringLength = 0;
}

/*****************************************************************************************/
void GUIAPI_String::clear(){
    free(stringData);
    stringData = 0;
    stringData = (char*)calloc(stringLength, sizeof(char));
}