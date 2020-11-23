#include <map>
#include <tuple>

template <size_t N, typename Head, typename... T>
struct magic {
    using tuple_type = typename magic<N - 1, Head, Head, T...>::tuple_type;
};

template <typename Head, typename... T>
struct magic<1, Head, T...> {
    using tuple_type = std::tuple<T...>;
};

template <typename T>
class Matrix
{
    public:
        Matrix(const T&);
        void setValue(const T&, std::tuple<int, int>);
        int capacity();
        T getValue(std::tuple<int, int>);
    private:
        T m_default;
        std::map<std::tuple<int, int>, T> m_array;
}; 