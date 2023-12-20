#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer 
{
  private:
    Serializer();
    Serializer(const Serializer &source);
    Serializer &operator=(const Serializer &rhs);

  public:
    ~Serializer();
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
