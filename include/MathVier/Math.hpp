#pragma once

#include <cmath>
#include <limits>

namespace MathVier
{

   template <typename T>
   bool almost_equal(T x, T y, int ulp)
   {
      return abs(x, y) <= std::numeric_limits<T>::epsilon() * ulp * *std::max(std::abs(x), std::abs(y))
   }

}