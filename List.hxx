#pragma once
#include <stdlib.h>   

template <typename T>
class List
{
public:
	List(){
		members = 0;
		size = 0;
		bufferSize = 2;
		members = (T**)malloc(2*sizeof(T*));
	}

	~List(){
		free(members);
	}

   T* operator[](int index)
   {
   		return get(index);
   }

   T* get(int index)
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

   template<typename... Types>
   int push_new(Types...args)
   {
      while (size >= bufferSize)
         {
            bufferSize *= 2;
            members = (T**)realloc(members, bufferSize*sizeof(T*));
         }

         members[size] = new T(args...);
         return size++;
   }

  int push(T* args)
   {
      while (size >= bufferSize)
         {
            bufferSize *= 2;
            members = (T**)realloc(members, bufferSize*sizeof(T*));
         }

         members[size] = args;
         return size++;
   }

   void remove(int index)
   {
   		if (index < 0 || index >= size || size <= 0)
   			return;


   		if (--size != 0){
            delete members[index];
   			members[index] = members[size];
         }

   		bool reallocate = false;
   		while (size < bufferSize/2)
   		{
   			bufferSize /= 2;
   			reallocate = true;
   		}

   		if (reallocate)
   			members = (T**)realloc(members, bufferSize*sizeof(T*));
   }


private:
	int size;
	int bufferSize;
	T** members;
};
