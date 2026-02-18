#include <MathVier/matrix.hpp>
#include <cmath>
#include <stdexcept>

namespace MathVier {
   // Apesar que eu fiz isso bontinho eu vou fazer algo mais parecido ao glm e usar template, isso aqui vai ficar no codigo 
   mat4_t mat4_identity(void) {
      mat4_t result = {0}; 
// =     0     1     2     3
//       4     5     6     7
//       8     9     10    11
//       12    13    14    15
//   Formula [4 * linha + coluna - 5] ela funciona para matrizes 4x4
      for (int i = 0; i < 4; ++i){
         result.m[5*i] = 1;
      }
      return result;
   }
}