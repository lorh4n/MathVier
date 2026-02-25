#ifndef MATHVIER_VECTOR_H
#define MATHVIER_VECTOR_H

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Pra quem ta vendo o codigo, tem um versão dele comentada bonitinha na pasta /Falatorio
// -------------------------------------------------------------------------------------------

#include <iostream>
#include <stdexcept>
#include <cmath> 

namespace MathVier
{

   // Eu fiz primeiro o Vec4, olhe os comentarios dele primeiro

   template <typename Type>
   struct alignas(16) Vec2
   {
      Type x, y;

      // Construtores
      Vec2() : x(0), y(0) {}
      Vec2(Type _x, Type _y) : x(_x), y(_y) {}
      explicit Vec2(Type single) : x(single), y(single) {}

      // Acesso por índice
      Type &operator[](int i)
      {
         if (i < 0 || i >= 2)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : y;
      }

      const Type &operator[](int i) const
      {
         if (i < 0 || i >= 2)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : y;
      }

      // Comprimento (norma)
      Type length() const
      {
         return sqrt(x * x + y * y);
      }

      // Normalização
      Vec2<Type> normalized() const
      {
         Type norm = length();
         if (norm == 0)
         {
            return Vec2<Type>(0, 0);
         }
         return Vec2<Type>(x / norm, y / norm);
      }

      // Produto escalar
      Type dot(const Vec2<Type> &other) const
      {
         return x * other.x + y * other.y;
      }

      // Produto vetorial (escalar em 2D)
      Type cross(const Vec2<Type> &other) const
      {
         return x * other.y - y * other.x;
      }
      // Novo: Operador de soma
      Vec2<Type> operator+(const Vec2<Type> &other) const
      {
         return Vec2<Type>(x + other.x, y + other.y);
      };

      // Novo: Operador de subtração
      Vec2<Type> operator-(const Vec2<Type> &other) const
      {
         return Vec2<Type>(x - other.x, y - other.y);
      };

      // Operador de Multiplicação por fator
      Vec2<Type> operator*(Type factor) const
      {
         return Vec2<Type>(x * factor, y * factor);
      }
   };

   template <typename Type>
   struct alignas(16) Vec3
   {
      Type x, y, z;

      Vec3() : x(0), y(0), z(0) {}

      Vec3(Type _x, Type _y, Type _z) : x(_x), y(_y), z(_z) {}

      explicit Vec3(Type single) : x(single), y(single), z(single) {}

      // Acesso por índice
      Type &operator[](int i)
      {
         if (i < 0 || i >= 3)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : (i == 1 ? y : z);
      }

      const Type &operator[](int i) const
      {
         if (i < 0 || i >= 3)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : (i == 1 ? y : z);
      }
      Type length() const
      {
         return std::sqrt(x * x + y * y + z * z);
      }
      Vec3<Type> normalized() const
      {
         Type norm = length();
         if (norm == 0)
         {
            return Vec3<Type>(0, 0, 0);
         }
         return Vec3<Type>(x / norm, y / norm, z / norm);
      };
      // Produto escalar (dot product)
      Type dot(const Vec3<Type> &other) const
      {
         return x * other.x + y * other.y + z * other.z;
      }

      // Produto vetorial (cross product)
      Vec3<Type> cross(const Vec3<Type> &other) const
      {
         return Vec3<Type>(
             y * other.z - z * other.y,
             z * other.x - x * other.z,
             x * other.y - y * other.x);
      };

      // Novo: Operador de soma
      Vec3<Type> operator+(const Vec3<Type> &other) const
      {
         return Vec3<Type>(x + other.x, y + other.y, z + other.z);
      };

      // Novo: Operador de subtração
      Vec3<Type> operator-(const Vec3<Type> &other) const
      {
         return Vec3<Type>(x - other.x, y - other.y, z - other.z);
      };
   };

   template <typename Type>
   struct alignas(16) Vec4
   {
      Type x, y, z, w;

      // Construtores
      Vec4() : x(0), y(0), z(0), w(0) {}
      Vec4(Type _x, Type _y, Type _z, Type _w) : x(_x), y(_y), z(_z), w(_w) {}
      explicit Vec4(Type single) : x(single), y(single), z(single), w(single) {}

      // Acesso por índice
      Type &operator[](int i)
      {
         if (i < 0 || i >= 4)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
      }

      const Type &operator[](int i) const
      {
         if (i < 0 || i >= 4)
         {
            throw std::out_of_range("Índice inválido");
         }
         return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
      }

      // Comprimento (norma)
      Type length() const
      {
         return sqrt(x * x + y * y + z * z + w * w);
      }

      // Normalização
      Vec4<Type> normalized() const
      {
         Type norm = length();
         if (norm == 0)
         {
            return Vec4<Type>(0, 0, 0, 0);
         }
         return Vec4<Type>(x / norm, y / norm, z / norm, w / norm);
      }

      // Produto escalar
      Type dot(const Vec4<Type> &other) const
      {
         return x * other.x + y * other.y + z * other.z + w * other.w;
      }

      // Novo: Operador de soma
      Vec4<Type> operator+(const Vec4<Type> &other) const
      {
         return Vec4<Type>(x + other.x, y + other.y, z + other.z, w + other.w);
      };

      // Novo: Operador de subtração
      Vec4<Type> operator-(const Vec4<Type> &other) const
      {
         return Vec4<Type>(x - other.x, y - other.y, z - other.z, w - other.w);
      };

      // Operador de Multiplicação
      Vec4<Type> operator*(Type factor) const
      {
         return Vec4<Type>(x * factor, y * factor, z * factor, w * factor);
      }
   };

   // ======================= ADAPATAÇÃO ANTIGA ========================
   // ========== Vou manter por uma questão nostalgica =================

   struct vec2_t
   {
      float x, y;
      vec2_t(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
      vec2_t(float value) : x(value), y(value) {}
   };

   struct vec3_t
   {
      float x, y, z;
      vec3_t(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}
      vec3_t(float value) : x(value), y(value), z(value) {}
   };

   struct vec4_t
   {
      float x, y, z, w;
      vec4_t(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f) : x(x), y(y), z(z), w(w) {}
      vec4_t(float value) : x(value), y(value), z(value), w(value) {}
   };

   // Funções para vec2_t
   float vec2_lenght(vec2_t v);
   vec2_t vec2_add(vec2_t a, vec2_t b);
   vec2_t vec2_sub(vec2_t a, vec2_t b);
   vec2_t vec2_mult(vec2_t a, float factor);
   vec2_t vec2_div(vec2_t a, float factor);
   float vec2_dot(vec2_t a, vec2_t b);
   void vec2_normalize(vec2_t *v);

   // Funções para vec3_t
   float vec3_lenght(vec3_t v);
   vec3_t vec3_add(vec3_t a, vec3_t b);
   vec3_t vec3_sub(vec3_t a, vec3_t b);
   vec3_t vec3_mult(vec3_t a, float factor);
   vec3_t vec3_div(vec3_t a, float factor);
   float vec3_dot(vec3_t a, vec3_t b);
   void vec3_normalize(vec3_t *v);
   vec3_t vec3_cross(vec3_t a, vec3_t b);

   vec3_t vec3_rotate_x(vec3_t v, float angle);
   vec3_t vec3_rotate_y(vec3_t v, float angle);
   vec3_t vec3_rotate_z(vec3_t v, float angle);

   // conversões
   vec4_t vec4_from_vec3(vec3_t v);
   vec3_t vec3_from_vec4(vec4_t v);
}
#endif