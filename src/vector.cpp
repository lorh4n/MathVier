#include <MathVier/vector.hpp>
#include <cmath>
#include <stdexcept>

namespace MathVier {
   float vec2_length(const vec2_t& v) {
      return std::sqrt(v.x * v.x + v.y * v.y);
  }
  
  vec2_t vec2_add(const vec2_t& a, const vec2_t& b) {
      vec2_t result = { a.x + b.x, a.y + b.y };
      return result;
  }
  
  vec2_t vec2_sub(const vec2_t& a, const vec2_t& b) {
      vec2_t result = { a.x - b.x, a.y - b.y };
      return result;
  }
  
  vec2_t vec2_mult(const vec2_t& a, float factor) {
      vec2_t result = { a.x * factor, a.y * factor };
      return result;
  }
  
  vec2_t vec2_div(const vec2_t& a, float factor) {
      if (factor == 0.0f) throw std::runtime_error("Divisão por zero!");
      vec2_t result = { a.x / factor, a.y / factor };
      return result;
  }
  
  float vec2_dot(const vec2_t& a, const vec2_t& b) {
      return a.x * b.x + a.y * b.y;
  }
  
  void vec2_normalize(vec2_t* v) {
      float len = vec2_length(*v);
      if (len == 0.0f) throw std::runtime_error("Não é possível normalizar vetor zero!");
      v->x /= len;
      v->y /= len;
  }
  
  float vec3_length(const vec3_t& v) {
      return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  }
  
  vec3_t vec3_add(const vec3_t& a, const vec3_t& b) {
      vec3_t result = { a.x + b.x, a.y + b.y, a.z + b.z };
      return result;
  }
  
  vec3_t vec3_sub(const vec3_t& a, const vec3_t& b) {
      vec3_t result = { a.x - b.x, a.y - b.y, a.z - b.z };
      return result;
  }
  
  vec3_t vec3_mult(const vec3_t& a, float factor) {
      vec3_t result = { a.x * factor, a.y * factor, a.z * factor };
      return result;
  }
  
  vec3_t vec3_div(const vec3_t& a, float factor) {
      if (factor == 0.0f) throw std::runtime_error("Divisão por zero!");
      vec3_t result = { a.x / factor, a.y / factor, a.z / factor };
      return result;
  }
  
  float vec3_dot(const vec3_t& a, const vec3_t& b) {
      return a.x * b.x + a.y * b.y + a.z * b.z;
  }
  
  void vec3_normalize(vec3_t* v) {
      float len = vec3_length(*v);
      if (len == 0.0f) throw std::runtime_error("Não é possível normalizar vetor zero!");
      v->x /= len;
      v->y /= len;
      v->z /= len;
  }
  
  vec3_t vec3_cross(const vec3_t& a, const vec3_t& b) {
      vec3_t result = {
          a.y * b.z - a.z * b.y,
          a.z * b.x - a.x * b.z,
          a.x * b.y - a.y * b.x
      };
      return result;
  }
  
  vec3_t vec3_rotate_x(const vec3_t& v, float angle) {
      float cos_a = std::cos(angle);
      float sin_a = std::sin(angle);
      vec3_t result = {
          v.x,
          v.y * cos_a - v.z * sin_a,
          v.y * sin_a + v.z * cos_a
      };
      return result;
  }
  
  vec3_t vec3_rotate_y(const vec3_t& v, float angle) {
      float cos_a = std::cos(angle);
      float sin_a = std::sin(angle);
      vec3_t result = {
          v.x * cos_a + v.z * sin_a,
          v.y,
          -v.x * sin_a + v.z * cos_a
      };
      return result;
  }
  
  vec3_t vec3_rotate_z(const vec3_t& v, float angle) {
      float cos_a = std::cos(angle);
      float sin_a = std::sin(angle);
      vec3_t result = {
          v.x * cos_a - v.y * sin_a,
          v.x * sin_a + v.y * cos_a,
          v.z
      };
      return result;
  }
  
  vec4_t vec4_from_vec3(const vec3_t& v) {
      vec4_t result = { v.x, v.y, v.z, 1.0f };
      return result;
  }
  
  vec3_t vec3_from_vec4(const vec4_t& v) {
      vec3_t result = { v.x, v.y, v.z };
      return result;
  }
}