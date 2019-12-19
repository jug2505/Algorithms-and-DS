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
      // Copy constructor
      Vector(const Vector&);
      // Copy assignment
      Vector<T>& operator=(const Vector<T>&);
      // Destructor
      ~Vector() {delete[] data};
      // Iterators
      iterator begin(){return data};
      const iterator begin() const {return data};
      iterator end(){return data + size};
      const iterator end() const {return data + size};
    
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
NoSTD::Vector<T>::Vector(std::size_t elems):size(elems){
  capacity = size > defaultCapacity ? elems * 2 : defaultCapacity;
  for(size_t i = 0; i < size; ++i)
    data[i] = T();
}

template<class T>
NoSTD::Vector<T>::Vector(const Vector& arg):size(arg.size), capacity(arg.capacity), data(new T[capacity]){
  for(size_t i = 0; i < arg.size; ++i)
    data[i] = arg.data[i];
}  

template<class T>
NoSTD::Vector<T>::Vector<T>& operator=(const Vector<T>& arg){
  if (this == &arg) return *this; // Self assignment
  if (capacity < arg.size){
    delete[] data;
    capacity = arg.capacity;
    data = new T[capacity];
  }
  size = arg.size;
  for(size_t i = 0; i < arg.size; ++i)
      data[i] = arg.data[i];
  return *this;
}

#endif
