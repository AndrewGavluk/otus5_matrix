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

        Row<T> operator [] (int p1) {   return Row<T>(p1, this);}

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
    Warper<T> operator [] (int p1)
        {
            auto key = std::make_tuple(pos, p1); 
            auto found =  m_Matrix->m_array.find(key);
                
            if (found != m_Matrix->m_array.end())
                return Warper<T>(found->second, m_Matrix, false);

            return Warper<T>(m_Matrix->m_default, m_Matrix, true, key);                
        }
    //private:
        int pos;
        Matrix<T>* m_Matrix;
};

template <typename T>
class Warper
{
    public:
        Warper( T& var,  Matrix<T>* Matrix, bool f ) : Variable{var}, m_Matrix{Matrix}, Fake{f} {};
        Warper( T& var,  Matrix<T>* Matrix, bool f,  std::tuple<int,int> _key) : Variable{var}, m_Matrix{Matrix}, key{_key}, Fake{f} {};
        
        T& operator = (const T& value){    
            m_Matrix->m_array.insert({key,m_Matrix->m_default});   
            auto found =  m_Matrix->m_array.find(key);
            found->second = value;
            return found->second;
        }
        
        template<typename T1>
        friend std::ostream& operator<< (std::ostream &, const Warper<T1>&);
    
   
    private:
        T& Variable;
        Matrix<T>* m_Matrix;
        std::tuple<int,int> key;
        bool Fake;

};

template <typename T>
std::ostream& operator<< (std::ostream &out, const Warper<T>& Warp)
{
    out << Warp.Variable;
    return out;    
}