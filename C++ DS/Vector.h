#ifndef NOSTD_VECTOR_IMPL
#define NOSTD_VECTOR_IMPL

#include <cstddef>

namespace NoSTD{
  using std::size_t;

  template<class T>
  class Vector{
    public:
      // Vector's iterator behave as pointer
      typedef T* iterator;
      // Default constructor
      Vector();
      explicit Vector(std::size_t elems);

    private:
      // Pointer to the first element of data array
      T* data;
      // Amount of "real" elements of vector
      size_t size;
      // Amount of available elements
      size_t capacity;
      // Change if needs anower amount of elements
      static constexpr size_t defaultCapacity = 8;
  };
}

template<class T> 
NoSTD::Vector<T>::Vector(){
  capacity = defaultCapacity;
  size = 0;
  data = new T[capacity];
}

template<class T> 
NoSTD::Vector<T>::Vector(std::size_t elems){
  if(size = elems; size > defaultCapacity)
    capacity = elems * 2;
  else
    capacity = defaultCapacity;
  for(size_t i = 0; i < size; ++i)
    data[i] = T();
}
#endif
