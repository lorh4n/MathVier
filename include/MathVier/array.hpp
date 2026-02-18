#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class DynamicArray {
   private:
      T* data;       // Ponteiro para os dados
      int capacity;  // Capacidade Total do array
      int occupied;  // Numero de elementos ocupados
   public:
      DynamicArray(): data(nullptr), capacity(0), occupied(0) {}
      

      // Regra do RAII, por isso nao nao chamei free() direto aqui
      ~DynamicArray() {
         if (data != nullptr) {
            delete[] data;
         }
      }

      T* hold(int count) {
         if (data == nullptr) {
            capacity = count;
            occupied = count;
            data = new T[capacity];
            return data;
         } else if (occupied + count <= capacity) {
            occupied += count;
            return data;
         } else {
            int new_capacity = (occupied + count) > (capacity * 2 ) ? (occupied + count) : (capacity * 2);

            T* new_data = new T[new_capacity];


            for (int i = 0; i < occupied; ++i) {
               new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
            capacity = new_capacity;
            occupied += count;

            return data;
         }
      }

      void push(T value) {
         hold(1);
         data[occupied - 1] = value;
      }
      int lenght() const {
         return occupied;
      }
      void free() {
         if(data != nullptr) {
            delete[] data;
            data = nullptr;
            capacity = 0;
            occupied = 0;
         };
      }


};

#endif