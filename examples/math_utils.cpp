#include <math_utils.hpp>

#include <utility>
#include <vector>

namespace math_utils {

std::vector<double> linspace(double start, double stop, int points) {
    auto step = (stop + 1 - start) / points;
    std::vector<double> out(points);
    for (int i = 0; i < points; ++i) {
        out[i] = start + step * i;
    }
    return out;
}

// Eigen would probably simplify this a lot.
std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> meshgrid(const std::vector<double>& x,
                                                                                       const std::vector<double>& y) {
    std::vector<std::vector<double>> xgrid(y.size(), std::vector<double>(x.size()));
    std::vector<std::vector<double>> ygrid(y.size(), std::vector<double>(x.size()));

    for (size_t i = 0; i < y.size(); ++i) {
        for (size_t j = 0; j < x.size(); ++j) {
            xgrid[i][j] = x[j];
            ygrid[i][j] = y[i];
        }
    }
    return {std::move(xgrid), std::move(ygrid)};
}

} // namespace math_utils
