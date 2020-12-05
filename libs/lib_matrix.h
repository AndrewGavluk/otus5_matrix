#include <map>
#include <tuple>
#include <iostream>

template <typename T>
class Row;

template <typename T>
class Warper;

template <typename T>
class Matrix
{
    public:
        Matrix( T value): m_default{value} {};
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
    public:
    Row(int p1, Matrix<T>* Matrix): pos{p1}, m_Matrix{Matrix}{}
    T& operator [] (int p1)
        {
            auto key = std::make_tuple(pos, p1);  
            auto found =  m_Matrix->m_array.find(key);
                
            if (found != m_Matrix->m_array.end()){
                T& foundElem = found->second;
                return foundElem;
            }
            
            T& foundElem = m_Matrix->m_default;
            return foundElem;

            /*m_Matrix->m_array.insert({key,m_Matrix->m_default});
            
            auto found =  m_Matrix->m_array.find(key);
            T& foundElem = found->second;
            return foundElem*/;             
        }
    private:
        int pos;
        Matrix<T>* m_Matrix;
};

template <typename T>
class Warper
{
    public:
        Warper( T& var,  Matrix<T>* Matrix ) : Variable{var}, m_Matrix{Matrix} {};
        T& operator = (const T&){
            //hw2Array<T, Alloc> temp(cr);
            //temp.swap(*this);
            return *this;}
   
   
    private:
        T& Variable;
        Matrix<T>* m_Matrix;

};