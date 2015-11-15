#pragma once
#include <stdlib.h>   

template <typename T>
class List
{
public:
	List(){
		members = 0;
		size = 0;
		bufferSize = 1;
		members = (T*)malloc(16*sizeof(T));
	}

	~List(){
		delete [] members;
	}

   T& operator[](int index)
   {
   		return get(index);
   }

   T& get(int index)
   {
   		if (index >= size)
   			throw "Out of boundaries";
		return members[index];
   }

   int getsize()
   {
   		return size;
   }

   int getbufsize()
   {
   		return bufferSize;
   }


   List<T>& operator<<(const T &value)
   {
   		this->push(value);
   		return *this;
   }

   int push(const T& value)
   {
		while (size >= bufferSize)
   		{
   			bufferSize *= 2;
   			members = (T*)realloc(members, bufferSize*sizeof(T));
   		}

   		members[size] = value;
   		return size++;
   }

   void remove(int index)
   {
   		if (index < 0 || index >= size || size <= 0)
   			return;


   		if (--size != 0)
   			members[index] = members[size];

   		bool reallocate = false;
   		while (size < bufferSize/2)
   		{
   			bufferSize /= 2;
   			reallocate = true;
   		}

   		if (reallocate)
   			members = (T*)realloc(members, bufferSize*sizeof(T));
   }


private:
	int size;
	int bufferSize;
	T* members;
};