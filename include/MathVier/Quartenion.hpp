#ifndef MATHVIER_QUATERNION_HPP
#define MATHVIER_QUATERNION_HPP

#include <MathVier/vector.hpp>


namespace MathVier {
template<typename type_t>
struct alignas(16) Quaternion{
   type_t w, x, y, z;

   Quaternion() : w(1), x(0), y(0), z(0) {} // Quaternion em Identidade {1, 0, 0, 0}
   Quaternion(type_t _w, type_t _x, type_t _y, type_t _z) : w(_w), x(_x), y(_y), z(_z) {} 
   Quaternion(type_t _w, const Vec3<type_t>& v) : w(_w), x(v.x), y(v.y), z(v.z) {}

   // Acesso por Indice
   type_t& operator[](int i) {
      if (i < 0 || i >= 4) {
         throw out_of_range("Indice Invalido");
      }
      return i == 0 ? w : (i == 1 ? x : (i == 2 ? y : z));
   }
   // Acesso por Indice (Leitura)
   const type_t& operator[](int i) const {
      if (i < 0 || i >= 4) {
         throw out_of_range("Indice Invalido");
      }
      return i == 0 ? w : (i == 1 ? x : (i == 2 ? y : z));
   }
   // Norma (length)
   Type length() const {
      return std::sqrt(w * w + x * x + y * y + z * z);
  }

   // Conjugado
   Quaternion conjugate() const {
      return Quaternion(w, -x, -y, -z);
   }

   // Normalização
   Quaternion normalized() const {
      Type len = length();
      if (len == 0) {
            return Quaternion(0, 0, 0, 0);
      }
      return Quaternion(w / len, x / len, y / len, z / len);
   }

   // Operador de soma
   Quaternion operator+(const Quaternion& other) const {
      return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
   }

   // Operador de subtração
   Quaternion operator-(const Quaternion& other) const {
      return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
   }

   // Multiplicação por escalar
   Quaternion operator*(Type factor) const {
      return Quaternion(w * factor, x * factor, y * factor, z * factor);
   }

};

// Multiplicação por escalar (escalar * quatérnio)
template <typename Type>
Quaternion<Type> operator*(Type factor, const Quaternion<Type>& q) {
    return q * factor;
}

};
#endif