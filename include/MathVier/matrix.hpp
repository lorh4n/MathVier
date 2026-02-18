#ifndef MATHVIER_MATRIX_H
#define MATHVIER_MATRIX_H

#include <cmath>
#include "vector.hpp"

namespace MathVier {



   template<typename Type>
   struct alignas(16) Mat4{
      Vec4<Type> columns[4];

      // Construtor padrão
      Mat4() : columns{Vec4<Type>{}, Vec4<Type>{}, Vec4<Type>{}, Vec4<Type>{}} {}

      // Acesso por colunas
      Vec4<Type>& operator[](int i) { return columns[i]; }
      const Vec4<Type>& operator[](int i) const { return columns[i]; }

      static Mat4 identity() {
         Mat4 result;
         result.columns[0].x = 1; // Elemento (0,0)
         result.columns[1].y = 1; // Elemento (1,1)
         result.columns[2].z = 1; // Elemento (2,2)
         result.columns[3].w = 1; // Elemento (3,3)
         return result;
      }

      Mat4 scale(Type sx, Type sy, Type sz) const {
         // | sx  0  0  0 |
         // |  0 sy  0  0 |
         // |  0  0 sz  0 |
         // |  0  0  0  1 |
         Mat4 result;
         result.columns[0].x = sx; // (0,0)
         result.columns[1].y = sy; // (1,1)
         result.columns[2].z = sz; // (2,2)
         result.columns[3].w = 1;  // (3,3)
         return result;
      }

      Mat4 translate(Type tx, Type ty, Type tz) const {
         // | 1  0  0  tx |
         // | 0  1  0  ty |
         // | 0  0  1  tz |
         // | 0  0  0  1  |
         Mat4 result = identity();
         result.columns[3].x = tx; // (0,3)
         result.columns[3].y = ty; // (1,3)
         result.columns[3].z = tz; // (2,3)
         return result;
      }

      Mat4 rotate(Type angle, Vec3<Type> axis) const {
         // ==== Eixo X ===== ======= Eixo Y =====  ====== Eixo Z ====
         // | 1  0  0  0 |    // |  c  0  s  0 |    // | c -s  0  0 |
         // | 0  c -s  0 |    // |  0  1  0  0 |    // | s  c  0  0 |
         // | 0  s  c  0 |    // | -s  0  c  0 |    // | 0  0  1  0 |
         // | 0  0  0  1 |    // |  0  0  0  1 |    // | 0  0  0  1 |
         // fórmula de rotação de Rodrigues
         
      // Rotação por ângulo (radianos) em torno de um eixo
      // Diagrama: [ m00 m01 m02 0 ]
      //           [ m10 m11 m12 0 ]
      //           [ m20 m21 m22 0 ]
      //           [  0   0   0  1 ]
 
         Mat4 result = identity();
         Type c = std::cos(angle);
         Type s = std::sin(angle);
         Type t = 1 - c;

         // Normaliza o eixo
         Type x = axis.x, y = axis.y, z = axis.z;
         Type len = std::sqrt(x * x + y * y + z * z);
         if (len > 0) { x /= len; y /= len; z /= len; }

         // Primeira coluna
         result.columns[0].x = t * x * x + c;      // (0,0)
         result.columns[0].y = t * x * y + s * z;  // (1,0)
         result.columns[0].z = t * x * z - s * y;  // (2,0)

         // Segunda coluna
         result.columns[1].x = t * x * y - s * z;  // (0,1)
         result.columns[1].y = t * y * y + c;      // (1,1)
         result.columns[1].z = t * y * z + s * x;  // (2,1)

         // Terceira coluna
         result.columns[2].x = t * x * z + s * y;  // (0,2)
         result.columns[2].y = t * y * z - s * x;  // (1,2)
         result.columns[2].z = t * z * z + c;      // (2,2)

         // Última coluna já é (0, 0, 0, 1) pela identity()
         return result;
      }; 
      // Novo: Operador de soma
      Mat4<Type> operator+(const Mat4<Type>& other) const {
          Mat4<Type> result;
          for (int i = 0; i < 4; ++i) {
              result.columns[i] = columns[i] + other.columns[i];
          }
          return result;
      }
  
      // Novo: Operador de subtração
      Mat4<Type> operator-(const Mat4<Type>& other) const {
          Mat4<Type> result;
          for (int i = 0; i < 4; ++i) {
              result.columns[i] = columns[i] - other.columns[i];
          }
          return result;
      }

      //Novo: Operador multiplicação por Escalar
      Mat4<Type> operator*(Type factor) const {
         Mat4<Type> result;
         for (int i = 0; i < 4; ++i) {
             result.columns[i] = columns[i] * factor; // Usa operator* de Vec4
         }
         return result;
     }
     static Mat4 perspective(Type fov, Type aspect, Type near, Type far) {
      Mat4 result;
      Type tanHalfFov = std::tan(fov / 2);
      result.columns[0].x = 1 / (aspect * tanHalfFov);
      result.columns[1].y = 1 / tanHalfFov;
      result.columns[2].z = -(far + near) / (far - near);
      result.columns[2].w = -1;
      result.columns[3].z = -(2 * far * near) / (far - near);
      return result;
  }

  static Mat4 lookAt(const Vec3<Type>& eye, const Vec3<Type>& center, const Vec3<Type>& up) {
      Mat4 result = identity();
      Vec3<Type> front = (eye - center).normalized();
      Vec3<Type> right = up.cross(front).normalized();
      Vec3<Type> newUp = front.cross(right);

      result.columns[0].x = right.x;
      result.columns[0].y = right.y;
      result.columns[0].z = right.z;

      result.columns[1].x = newUp.x;
      result.columns[1].y = newUp.y;
      result.columns[1].z = newUp.z;

      result.columns[2].x = -front.x;
      result.columns[2].y = -front.y;
      result.columns[2].z = -front.z;

      result.columns[3].x = -right.dot(eye);
      result.columns[3].y = -newUp.dot(eye);
      result.columns[3].z = front.dot(eye);
      result.columns[3].w = 1;

      return result;
  }
   };

      template <typename Type>
   Mat4<Type> operator*(Type factor, const Mat4<Type>& mat) {
      return mat * factor; // Reutiliza o operator* da matriz
   }


// ======================= ADAPATAÇÃO ANTIGA ======================== 
// ========== Vou manter por uma questão nostalgica =================
   struct mat4_t {
      float m[16];
   };
   
   mat4_t mat4_identity(void);
   mat4_t mat4_make_scale(float sx, float sy, float sz);
} // namespace MathVier



#endif