
## 📅 22 de Abril de 2025

Hoje decidi implementar **matrizes** e **vetores**. Comecei usando meu código do projeto `Learning3D` (curso de SDL),  
mas resolvi fazer algo mais complexo e fui ver como a biblioteca **GLM** trabalha.  
Com a ajuda de uma LLM, descobri que ela usa **template**, e resolvi seguir esse caminho.

---

## 📅 23 de Abril de 2025

Finalizei a **implementação base** dos vetores e das matrizes.

- Criei as funções `make_scale` e `make_translate`.
- Parei na função `rotate`, pois quero entender melhor a lógica por trás das **rotações de Euler** e a **fórmula de Rodrigues**.

### 🧠 Reflexões

> **Não estou gostando muito da implementação das funções**, estou achando tudo muito **mecânico** e pouco **inteligente**...  
> Por outro lado, a estrutura com `struct` e `template` me agradou bastante!

🧪 Vetores (`Vec2`, `Vec3`, ...)

- Uso de **template** (`Type`).
- Construtor que inicializa com zeros.
- Sobrecarga:
  - `Vec2(a, b)` → define manualmente.
  - `Vec2(1.0f)` → todos os valores iguais.

🧱 Matrizes (`Matrix4x4`)

- Já implementei:
  - `translate`
  - `scale`
  - `identity()` como **função estática**
- Todas as funções estão marcadas como `const` (não modificam o objeto).  
  Preciso **melhorar o entendimento do uso de `const`** em métodos.

---

## ✅ Tarefas Pendentes

- [x] Operador `*` para matrizes e `matriz * vetor`
- [x] Operadores `+` / `-` para matrizes
- [x] Terminar função `rotate` (Euler ou Rodrigues)
- [?] Generalizar tipos de matrizes ou tornar a função flexível 
- [x] Funções para vetores:
  - `normalize`
  - `length`
  - `dot`
  - `cross`
- [X] Projeções:
  - `LookAt`
  - `Perspective`

---

## 📅 24 de Abril de 2025

O compilador deu erros em relação a `array.hpp` alegando que era `delete[] data;` e não `delete[] = data`. Preciso descobrir o motivo.

Implementei o `length` e `normalized`. Decidi fazer o `dot` e `cross` separadamente em outra função depois.

## 📅 27 de Abril de 2025
Implementei as funções para Vetores e operadores de + e - e matrizes tbm
- [x] Operador `*` para matrizes e `matriz * vetor`
- [x] Operadores `+` / `-` para matrizes
- [x] Terminar função `rotate` (Euler ou Rodrigues)
- [?] Generalizar tipos de matrizes ou tornar a função flexível 
- [x] Funções para vetores:
  - `normalize`
  - `length`
  - `dot`
  - `cross`
- [x] Projeções:
  - `LookAt`
  - `Perspective`

### 🌀 **Quaternion Criado**

Hoje implementei o **Quaternion**!  
- Decidi usar a **primeira letra maiúscula** no nome (ex.: `Quaternion`).  
  - Ainda preciso me decidir sobre o padrão de nomenclatura.  
- Dentro do cabeçalho, utilizei **template** com `typename type_t`.  
  - Vou manter assim por enquanto e ajustar o padrão posteriormente.
- As funções básicas e seus operadores também foram implementados (`length`, `conjugate`, `normalize`, `+`/`-`, `*` fator).

---

## ✅ Tarefas Pendentes

- [ ] Implementar transformações e rotações do Quaternion.
- [ ] Implementar multiplicação de Quaternions.

---

## 📅 04 de Maio de 2025

Hoje implementei um **vetor genérico** no arquivo `VectorGeneric.hpp`, para uso em cálculos de **regressão linear**.

---

## 📅 25 de Fevereiro de 2026

Faz tempo que não mexo aqui, mas hoje retomei o projeto com força total!

### 🚀 **Novidades nas Matrizes e Integração**

- **Multiplicação de Matrizes:** Finalmente implementei o `operator*` para `Mat4 * Mat4` e `Mat4 * Vec4`. Agora a biblioteca está ficando realmente útil para transformações complexas.
- **Refatoração:** Limpei e formatei melhor o código em `matrix.hpp` e `vector.hpp`, garantindo que tudo siga o padrão de templates.
- **Utilidades Matemáticas:** Comecei o arquivo `Math.hpp` para funções auxiliares, como o `almost_equal` para comparações de ponto flutuante (preciso revisar a implementação depois).
- **Uso Prático:** Comecei a integrar a `MathVier` no meu outro projeto de geometria (`geom`). Usei o `Vec2` para implementar a função `closestPointOnSegment` em `primitives2d.cpp`. Está funcionando muito bem!

### 🛠️ **O que foi feito hoje:**
- [x] Operador `*` para `Mat4 * Mat4`
- [x] Operador `*` para `Mat4 * Vec4`
- [x] Criação do `Math.hpp` (em progresso)
- [x] Refatoração de estilo e organização do código

---

## ✅ Tarefas Pendentes

- [ ] Corrigir e testar a função `almost_equal` no `Math.hpp`.
- [ ] Implementar `transpose` e `inverse` para matrizes.
- [ ] Finalizar as transformações e multiplicação de Quaternions (que deixei parado ano passado).
- [ ] Adicionar mais primitivas 2D no projeto `geom` usando a `MathVier`.