#include <map>
#include <tuple>
#include <iostream>

template <typename T>
class Row;

template <typename T>
class Matrix
{
    public:
        Matrix(){};
        Matrix(const T&);
        void setValue(const T&, std::tuple<int, int>);
        int capacity();

        Row<T> operator [] (int p1)
        {
            return Row<T>(p1, this);

        }

        T getValue(std::tuple<int, int>);
    
    //private:
        T m_default;
        std::map<std::tuple<int,int>, T> m_array;
}; 

template <typename T>
class Row
{
    Row(int p1, Matrix<T>* Matrix): pos{p1}, m_Matrix{Matrix}{}
    T& operator [] (int p1)
        {
            auto key = std::make_tuple(pos, p1);
            auto found =  m_Matrix->m_array.find(key);
            
            if (found != m_Matrix->m_array.end())
                return found;
            
            auto [newFound, success] = m_Matrix->m_array.insert({key,m_Matrix->m_default});
            if (success)
                return newFound; 
            throw std::abort();               
        }
    private:
        int pos;
        Matrix<T>* m_Matrix;
};
