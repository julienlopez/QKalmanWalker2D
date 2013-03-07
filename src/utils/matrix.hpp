#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

#include <boost/static_assert.hpp>

/**
  * \brief Static matrix class.
  *
  *
  * M being the height of the matrix
  * N being the width of the matrix
  */
template<std::size_t M, std::size_t N> class Matrix
{
public:
    Matrix(): m_datas()
    {}

    Matrix(double d): m_datas(d)
    {}

    double operator()(std::size_t i, std::size_t j) const
    {
        return m_datas[i*N+j];
    }

    double& operator()(std::size_t i, std::size_t j)
    {
        return m_datas[i*N+j];
    }

    std::size_t height() const
    {
        return M;
    }

    std::size_t width() const
    {
        return N;
    }

    Matrix<N, M> transpose() const
    {
        Matrix<N, M> res;
        for(size_t i = 0; i < N; i++)
            for(size_t j = 0; j < M; j++)
                res(i,j) = (*this)(j,i);
        return res;
    }

    void swapLines(std::size_t i, std::size_t j)
    {
        for(std::size_t k = 0; k < N; k++)
            std::swap((*this)(i, k), (*this)(j, k));
    }

    Matrix<M, N> operator+(const Matrix<M, N>& m) const
    {
        Matrix<M, N> res;
        for(size_t i = 0; i < M*N; i++)
            res.m_datas[i] = m_datas[i] + m.m_datas[i];
        return res;
    }

    Matrix<M, N> operator-(const Matrix<M, N>& m) const
    {
        Matrix<M, N> res;
        for(size_t i = 0; i < M*N; i++)
            res.m_datas[i] = m_datas[i] - m.m_datas[i];
        return res;
    }

    template<std::size_t O> Matrix<M, O> operator*(const Matrix<N, O>& m) const
    {
        Matrix<M, O> res;
        for(size_t i = 0; i < M; i++)
            for(size_t j = 0; i < O; i++)
            {
                double sum = 0;
                for(size_t k = 0; k < N; k++)
                    sum += (*this)(i, k) * m(k, j);
                res(i, j) = sum;
            }
        return res;
    }

private:
    Array<double, M*N> m_datas;
};

template<std::size_t M> Matrix<M, M> identity()
{
    Matrix<M, M> res(0);
    for(std::size_t i = 0; i < M; i++)
        res(i, i) = 1;
    return res;
}

#endif // MATRIX_HPP
