#ifndef __GUIAPI_Vector__
#define __GUIAPI_Vector__

#include "stdint.h"
#include "stdlib.h"

template<class T>
class GUIAPI_Vector{

public:
    /*****************************************************************************************/
    GUIAPI_Vector(){
        this->arrayCapacity = 10;
        this->arrayLength = 0;
        items = (T*)calloc(arrayCapacity, sizeof(T));
    }
    /*****************************************************************************************/
    GUIAPI_Vector(uint32_t arrayCapacity){
        this->arrayCapacity = arrayCapacity;
        this->arrayLength = 0;
        items = (T*)calloc(arrayCapacity, sizeof(T));
    }

    /*****************************************************************************************/
    ~GUIAPI_Vector(){
        free(items);
    }

    /*****************************************************************************************/
    void append(T item){
        if(arrayLength < arrayCapacity){
            items[arrayLength++] = item;
        }else{
            T *backup = (T*)calloc(arrayLength, sizeof(T));
            move(items, backup, arrayLength);
            free(items);

            arrayCapacity += 10;
            items = (T*)calloc(arrayCapacity, sizeof(T));
            move(backup, items, arrayLength);
            items[arrayLength++] = item;
            free(backup);
        }
    }

    /*****************************************************************************************/
    T& front(){
        return items[0];
    }

    /*****************************************************************************************/
    T& back(){
        return items[arrayLength-1];
    }

    /*****************************************************************************************/
    void empty(){
        free(items);
        this->arrayLength = 0;
        items = (T*)calloc(this->arrayCapacity, sizeof(T));
    }

    /*****************************************************************************************/
    void fill(T item){
        for(uint32_t i = 0; i < arrayCapacity; i++)
            append(item);
    }

    T* data(){ return items; }

    bool isEmpty() { return arrayLength == 0; }

    /*Returning number of elements*/
    uint32_t length() { return arrayLength; }
    /*Returning number of cells in array*/
    uint32_t capacity() { return arrayCapacity; }

    /*****************************************************************************************/
    GUIAPI_Vector& operator=(const GUIAPI_Vector& nArray){
        empty();
        this->arrayCapacity = nArray.arrayCapacity;
        this->arrayLength = nArray.arrayLength;
        items = (T*)calloc(this->arrayCapacity, sizeof(T));
        move(nArray.items, this->items, nArray.arrayLength);
        return *this;
    }

    /*****************************************************************************************/
    GUIAPI_Vector& operator=(const T& items){
        empty();
        for(T item : items)
            append(item);
        return *this;
    }

    /*****************************************************************************************/
    T& operator[](int index){
        return items[index];
    }

private:
    /*****************************************************************************************/
    void move(T* from, T* to, uint32_t mSize){
        for(uint32_t i = 0; i < mSize; i++)
            to[i] = from[i];
    }

    uint32_t arrayLength;
    uint32_t arrayCapacity;

    T *items;
};


#endif