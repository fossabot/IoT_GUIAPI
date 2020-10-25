#include "GUIAPI_String.h"
#include "GUIAPI_Vector.h"
#include "stdio.h"

int main(){
    //String array creation test
    GUIAPI_Vector<GUIAPI_String> stringArray;
    if(stringArray.capacity() == 0){
        printf("Array initialisation test failed.");
        return -1;
    }

    //Appending string test
    stringArray.append(GUIAPI_String("Hello world!"));
    if(stringArray.length() == 0){
        printf("Single object appending test is failed.");
        return -2;
    }

    //Multiple objects appending test
    for(uint32_t i = 0; i < stringArray.capacity() - 1; i++){
        char buffer[64] = {0};
        sprintf(buffer, "%luHello world!", i);
        stringArray.append(GUIAPI_String(reinterpret_cast<const char*>(buffer), (uint32_t)strlen(buffer)));
    }
    for(uint32_t i = 0; i < stringArray.length(); i++) printf("%s ", stringArray[i].c_str());
    printf("\r\n");
    if(stringArray.length() != stringArray.capacity()){
        printf("Multiple objects appending test failed.");
        return -3;
    }

    //Testing operator=
    GUIAPI_Vector<GUIAPI_String> stringArray_n;
    stringArray_n = stringArray;
    if(stringArray_n[5] != stringArray[5]){
        printf("Testing operator= failed.");
        return -4;
    }
    
    return 0;
}