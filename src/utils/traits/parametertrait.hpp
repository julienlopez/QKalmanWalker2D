#ifndef __PARAMETERTRAIT_HPP__
#define __PARAMETERTRAIT_HPP__

#include "select.hpp"
#include "ispointer.hpp"

template<class T> class ParameterTrait
{
public:
    typedef typename Select<is_pointer<T>::value, T*, T&>::type type;
    typedef typename Select<is_pointer<T>::value, const T*, const T&>::type const_type;
};

#endif
