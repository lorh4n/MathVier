#ifndef MATHVIER_VECTORGENERIC_HPP
#define MATHVIER_VECTORGENERIC_HPP

#include <stdexcept>
#include <cmath>
#include <initializer_list>

namespace MathVier {
   template<typename Type>
   // Pq não usar Struct? Eu tenho que responder isso depois
   class alignas(16) VectorGeneric {
   private:
      Type* data;
      int capacity;
      int size_;

      void resize(Type new_capacity) {
         if (new_capacity <= capacity) return;

         Type* new_data = new Type[new_capacity];
         for (int i = 0; i < size_ ; i++){
            new_data[i] = data[i];
         }

         delete[] data;
         data = new_data;
         capacity = new_capacity;
      }
   public:
      VectorGeneric() : data(nullptr), capacity(0), size_(0) {};

      explicit VectorGeneric(int size): capacity(size), size_(size) {
         data = new Type[size];
         for (int i = 0; i < size_; i++){
            data[i] = Type(0);
         }
      }; 

      VectorGeneric(std::initializer_list<Type> init) : capacity(init.size()), size_(init.size()) {
         data = new Type[capacity];
         int i = 0;
         for (const Type& value : init) {
             data[i++] = value;
         }
      };

      ~VectorGeneric() {
         delete[] data;
      };

      Type& operator[](int i) {
         if (i<0 || i>= size_) {
            throw std::out_of_range("Indice Invalido");
         }
         return data[i];
      };

      const Type& operator[](int i) const {
         if (i<0 || i>= size_) {
            throw std::out_of_range("Indice Invalido");
         }
         return data[i];
      };

      int size() const { return size_;}

      void push(Type value) {
         if (size_ >= capacity) {
            resize(capacity == 0 ? 4 : capacity * 2);
         }
         data[size_++] = value;
      };
// ==================================================================================
      // Operações Matematicas

      VectorGeneric<Type> operator+(const VectorGeneric<Type>& other) const {
         if (size_ != other.size()) {
            throw std::invalid_argument("Vetores devem ter o mesmo tamanho");
         }
         VectorGeneric<Type> result(size_);
         for (int i = 0; i < size_; ++i){
            result[i] = data[i] + other[i];
         }
         return result;
      }
      VectorGeneric<Type> operator-(const VectorGeneric<Type>& other) const {
         if (size_ != other.size()) {
            throw std::invalid_argument("Vetores devem ter o mesmo tamanho");
         }
         VectorGeneric<Type> result(size_);
         for (int i = 0; i < size_; ++i){
            result[i] = data[i] - other[i];
         }
         return result;
      }
      VectorGeneric<Type> operator*(Type scalar) const {
         VectorGeneric<Type> result(size_); 
         for (int i = 0; i < size_; ++i) {
            result[i] = data[i] * scalar;
         }
         return result;
      }

      Type dot(const VectorGeneric<Type>& other) const {
         if (size_ != other.size()) {
            throw std::invalid_argument("Vetores devem ter o mesmo tamanho");
         }
         Type result = Type(0);
         for (int i = 0; i < size_; ++i) {
            result += data[i] * other[i];
        }
        return result;
      }

      Type sum() const {
         Type result = Type(0);
         for (int i = 0; i < size_; ++i) {
             result += data[i];
         }
         return result;
     }
 
     VectorGeneric<Type> pow(Type exponent) const {
         VectorGeneric<Type> result(size_);
         for (int i = 0; i < size_; ++i) {
             result[i] = std::pow(data[i], exponent);
         }
         return result;
     }
 
     // Comprimento (norma)
     Type length() const {
         return std::sqrt(dot(*this));
     }
 
     // Normalização
     VectorGeneric<Type> normalized() const {
         Type norm = length();
         if (norm == Type(0)) {
             return VectorGeneric<Type>(size_);
         }
         return (*this) * (Type(1) / norm);
     }
      
   };
}



#endif