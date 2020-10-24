#include "GUIAPI_Array.h"

/*****************************************************************************************/
template<class T>
GUIAPI_Array<T>::GUIAPI_Array(){
    this->arraySizeMax = 10;
    items = (T*)calloc(arraySizeMax, sizeof(T));
}

/*****************************************************************************************/
template<class T>
GUIAPI_Array<T>::GUIAPI_Array(uint32_t arraySize){
    this->arraySizeMax = arraySizeMax;
    items = (T*)calloc(arraySizeMax, sizeof(T));
}

/*****************************************************************************************/
template<class T>
GUIAPI_Array<T>::~GUIAPI_Array(){
    free(items);
}

/*****************************************************************************************/
template<class T>
void GUIAPI_Array<T>::append(T item){
    if(arraySize < arraySizeMax){
        items[arraySize++] = item;
    }else{
        GUIAPI_Array<T> backup = *this;
        *this = backup;
        items[arraySize++] = item;
        this->arraySize++;
    }
}