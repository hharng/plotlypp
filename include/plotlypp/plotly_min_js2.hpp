#pragma once

namespace plotlypp {

// Note: constexpr string_view excessively bloats compile times due to length counts.
inline constexpr const char* const plotlyJS =
#include "../embedded_assets_raw_4096.txt"
    ;

} // namespace plotlypp
