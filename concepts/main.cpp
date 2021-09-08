#include <string>
#include <cstddef>
#include <numeric>
#include <iostream>
#include <vector>
#include <concepts>




// test if concepts available:
// #ifdef cpp_concepts

//template < class T >
//concept integral = std::is_integral_v<T>;

template <class T>
	requires std::is_integral_v<T> || std::is_floating_point_v<T>
constexpr double Average(std::vector<T> const &vec)
{
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}


template< class F, class... Args >
concept invocable =
  requires(F&& f, Args&&... args) {
    std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
      /* not required to be equality preserving */
  };

template <typename F>
requires invocable<F&, int>
void PrintVec(const std::vector<int>& vec, F fn)
{
    for (auto &elem : vec)
    {
        std::cout << fn(elem) << '\n';
    }
}

using namespace std;

int main()
{
	cout << "_LIBCPP_STD_VER=" << _LIBCPP_STD_VER << endl;
	cout << "__cpp_concepts=" << __cpp_concepts << endl;

	std::vector ints { 1, 2, 3, 4, 5};
    std::cout << Average(ints) << '\n';

	return 0;
}