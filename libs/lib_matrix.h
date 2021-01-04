#pragma once

#include <map>
#include <tuple>
#include <iostream>

using aIndex = std::tuple<int,int>;

template <typename T>
class Matrix;

template <typename T>
class Warper
{
    public:
        Warper( T& var,  Matrix<T>& Matrix, bool f ) : Variable{var}, m_Matrix{Matrix}, Fake{f} {};
        Warper( T& var,  Matrix<T>& Matrix, bool f,  aIndex _key) : Variable{var}, m_Matrix{Matrix}, key{_key}, Fake{f} {};
        
        T& operator = (const T& value){ 
            if (value == m_Matrix.m_default){
                auto toDel =  m_Matrix.m_array.find(key);
                if (toDel != m_Matrix.m_array.end())
                    m_Matrix.m_array.erase(toDel);
                return m_Matrix.m_default;
            }
                
            m_Matrix.m_array.insert({key,m_Matrix.m_default});   
            auto found =  m_Matrix.m_array.find(key);
            found->second = value;
            return found->second;
        }
        
        bool operator == (const T& value){ 
            return value == Variable;
        }

        bool operator == (const Warper<T>& value){ 
            return value.Variable == Variable;     
        }

        template<typename T1>
        friend std::ostream& operator<< (std::ostream &, const Warper<T1>&);
   
    private:
        T& Variable;
        Matrix<T>& m_Matrix;
        aIndex key;
        bool Fake;

};

template <typename T>
std::ostream& operator<< (std::ostream &out, const Warper<T>& Warp)
{
    out << Warp.Variable;
    return out;    
}

template <typename T>
class Row
{
    public:
    Row(int p1, Matrix<T>& Matrix): pos{p1}, m_Matrix{Matrix}{};
    Warper<T> operator [] (int p1)
        {
            auto key = std::make_tuple(pos, p1); 
            auto found =  m_Matrix.m_array.find(key);
                
            if (found != m_Matrix.m_array.end())
                return Warper<T>(found->second, m_Matrix, false);

            return Warper<T>(m_Matrix.m_default, m_Matrix, true, key);                
        }
    private:
        int pos;
        Matrix<T>& m_Matrix;
};

template <typename T>
class Matrix
{
    friend class Row<T>;
    friend class Warper<T>;

    public:
        Matrix( T value): m_default{value}, i{0}, j{0} {};
        int capacity(){return m_array.size();};

    void show(aIndex& from, aIndex& to ){   
    for (auto i=std::get<0>(from); i<=std::get<0>(to); ++i){
        for (auto j=std::get<1>(from); j<=std::get<1>(to); ++j)
            std::cout << this->operator[](i)[j] << " ";
        std::cout << std::endl;
        }
    }

    void print()
    {
        for (auto const& i : m_array)
        {
            std::cout << "array[ " << std::get<0>(i.first)  // string (key)
                    << "][" <<  std::get<1>(i.first)  
                    << "]="  << i.second << std::endl ;
        }
    }

        Row<T> operator [] (int p1){  
            return Row<T>(p1, *this);};   
    private:
        T m_default;
        std::map<aIndex, T> m_array;
        int i, j;
}; 


