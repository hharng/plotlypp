#include <utility>
#include <vector>

namespace math_utils {

std::vector<double> linspace(double start, double stop, int points);

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> meshgrid(const std::vector<double>& x,
                                                                                       const std::vector<double>& y);

} // namespace math_utils
