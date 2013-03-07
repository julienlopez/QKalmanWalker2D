#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "traits/parametertrait.hpp"

#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <sstream>

template<typename T, std::size_t N> class Array
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;

    Array()
    {}

    Array(typename ParameterTrait<T>::const_type t)
    {
        std::fill(begin(), end(), t);
    }

    size_t size() const
    {
        return N;
    }

    typename ParameterTrait<T>::const_type at(std::size_t i) throw(std::out_of_range)
    {
        if(i >= N)
        {
            std::ostringstream oss;
            oss << "index out of range: " << i << " >= " << N;
            throw std::out_of_range(oss.str());
        }
        return m_datas[i];
    }

    typename ParameterTrait<T>::const_type operator[](std::size_t i) const
    {
        return m_datas[i];
    }

    typename ParameterTrait<T>::type operator[](std::size_t i)
    {
        return m_datas[i];
    }

    iterator begin()
    {
        return m_datas;
    }

    const_iterator begin() const
    {
        return m_datas;
    }

    iterator end()
    {
        return m_datas + N;
    }

    const_iterator end() const
    {
        return m_datas + N;
    }

private:
    T m_datas[N];
};

#endif // ARRAY_HPP
