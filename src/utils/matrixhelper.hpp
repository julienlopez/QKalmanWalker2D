#ifndef MATRIXHELPER_HPP
#define MATRIXHELPER_HPP

#include "matrix.hpp"

class MatrixHelper
{
public:
    /**
      * invert a square matrix using Gauss-Jordan elimination
      */
    template<size_t N> static Matrix<N, N> invert(Matrix<N, N> m)
    {
        Matrix<N, N> res = identity<N>();

        //going down
        for(size_t i = 0; i < N; i++)
        {
            std::size_t idPivot = choixPivot(m, i);
            if(idPivot != i)
            {
                m.swapLines(i, idPivot);
            }
            for(std::size_t j = i+1; j < N; j++)
            {

            }
        }

        return res;
    }

private:
    template<size_t N> static std::size_t choixPivot(const Matrix<N,N>& m, std::size_t i)
    {
        std::size_t res = i;
        double base = m(i, i);
        for(std::size_t j = i+1; j < N; j++)
        {
            if(m(j, i) > base)
            {
                base = m(j, i);
                res = j;
            }
        }
        return res;
    }
};

#endif // MATRIXHELPER_HPP
