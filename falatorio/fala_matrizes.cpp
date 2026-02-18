#pragma once

#include "vector.hpp"

namespace MathVier {
   // Matriz 4x4, representada como 4 colunas de Vec4<T>
   // Layout column-major (padrão OpenGL):
   // - Cada Vec4<T> é uma coluna com 4 elementos (x, y, z, w)
   // - columns[0] = primeira coluna, columns[1] = segunda coluna, etc.
   //
   // Diagrama numérico (índices dos elementos na matriz):
   //  [ 0  4  8  12 ]  <- columns[0].x, columns[1].x, columns[2].x, columns[3].x
   //  [ 1  5  9  13 ]  <- columns[0].y, columns[1].y, columns[2].y, columns[3].y
   //  [ 2  6 10  14 ]  <- columns[0].z, columns[1].z, columns[2].z, columns[3].z
   //  [ 3  7 11  15 ]  <- columns[0].w, columns[1].w, columns[2].w, columns[3].w
   //
   // Exemplo: Matriz identidade
   //  [ 1  0  0  0 ]  <- columns[0] = {1, 0, 0, 0}
   //  [ 0  1  0  0 ]  <- columns[1] = {0, 1, 0, 0}
   //  [ 0  0  1  0 ]  <- columns[2] = {0, 0, 1, 0}
   //  [ 0  0  0  1 ]  <- columns[3] = {0, 0, 0, 1}

   template<typename T>
   struct alignas(16) Mat4 {
      // Array de 4 colunas, cada uma um Vec4<T>
      // Alinhado em 16 bytes para performance SIMD (SSE, AVX)
      Vec4<T> columns[4];

      // Construtor padrão: inicializa todas as colunas com zeros
      // - Cada Vec4<T> é inicializado com {0, 0, 0, 0}
      Mat4() : columns{{Vec4<T>{}, Vec4<T>{}, Vec4<T>{}, Vec4<T>{}}} {}

      // Acesso por colunas: retorna uma referência à coluna i
      // - Exemplo: mat[0] retorna columns[0] (primeira coluna como Vec4<T>)
      // - Permite modificar a coluna (ex.: mat[0].x = 1)
      Vec4<T>& operator[](int i) { return columns[i]; }

      // Versão const: para leitura de colunas em objetos const
      // - Exemplo: const Mat4<float> mat; mat[0] retorna coluna sem modificação
      const Vec4<T>& operator[](int i) const { return columns[i]; }

      // Método estático: cria uma matriz identidade
      // - Matriz identidade: diagonal principal = 1, outros = 0
      // - Diagrama:
      //    [ 1  0  0  0 ]
      //    [ 0  1  0  0 ]
      //    [ 0  0  1  0 ]
      //    [ 0  0  0  1 ]
      static Mat4 identity() {
         Mat4 result;
         result.columns[0].x = 1; // Elemento (0,0)
         result.columns[1].y = 1; // Elemento (1,1)
         result.columns[2].z = 1; // Elemento (2,2)
         result.columns[3].w = 1; // Elemento (3,3)
         return result;
      }
   };
}