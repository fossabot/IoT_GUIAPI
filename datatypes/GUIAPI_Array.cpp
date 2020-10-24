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
        T *backup = (T*)calloc(arraySize, sizeof(T));
        move(items, backup, arraySize);
        free(items);

        arraySizeMax += 3;
        items = (T*)calloc(arraySizeMax, sizeof(T));
        move(backup, items, arraySize);
        items[arraySize++] = item;
        this->arraySize++;
        free(backup);
    }
}

template<class T>
void GUIAPI_Array<T>::move(T* from, T* to, uint32_t mSize){
    for(uint32_t i = 0; i < mSize; i++)
        to[i] = from[i];
}