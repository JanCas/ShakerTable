#include "Vector/Vector.hpp"

template <typename T>
Vector<T>::Vector(){
    backing_array = malloc(INITIAL_VECTOR_SIZE * sizeof(T));
    size = 0;
}

template <typename T>
Vector<T>::~Vector(){
    delete []backing_array;
}

template <typename T>
void Vector<T>::add(T item){
    if (size+1 == ARRAY_SIZE(backing_array)) resize();

    backing_array[size] = item;
    size++;
}

template <typename T>
void Vector<T>::resize(){
    int newSize = size * 2;
    T   *newArr = malloc(newSize * sizeof(T));

    memcpy( newArr, backing_array, size * sizeof(T) );

    delete [] backing_array;
    backing_array = newArr;
}