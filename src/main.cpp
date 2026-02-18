#include <iostream>
#include "MathVier/MathVier.hpp"

void print_matrix(const MathVier::Mat4<float>& mat) {
    for (int i = 0; i < 4; ++i) {
       const auto& col = mat[i];
       std::cout << col.x << " " << col.y << " " << col.z << " " << col.w << "\n";
    }
 }

int main() {

    std::cout << "Hello WOlrd" << std::endl;
    // Testa construtor com valor único
    MathVier::Vec4<float> v(2.0f);
    std::cout << "Vec4: " << v.x << " " << v.y << " " << v.z << " " << v.w << "\n";
    // Saída esperada: Vec4: 2 2 2 2

    // Testa com outro tipo
    MathVier::Vec4<int> vi(5);
    std::cout << "Vec4<int>: " << vi.x << " " << vi.y << " " << vi.z << " " << vi.w << "\n";
    // Saída esperada: Vec4<int>: 5 5 5 5


    // Teste rotação (90° em torno do eixo Z)
    MathVier::Mat4<float> rot = MathVier::Mat4<float>().rotate(1.5708f, MathVier::Vec3<float>(0, 0, 1));
    std::cout << "Rotação (90° em Z):\n";
    print_matrix(rot);
    // Saída esperada (aproximada, devido a float):
    // 0  -1  0  0
    // 1   0  0  0
    // 0   0  1  0
    // 0   0  0  1
    std::cout << "========================================================================================================: ";
    MathVier::VectorGeneric<double> v1 = {1.0, 2.0, 3.0, 4.0};
    MathVier::VectorGeneric<double> v2 = {2.0, 3.0, 4.0, 5.0};

    std::cout << "v1: ";
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "v1 + v2: ";
    auto sum = v1 + v2;
    for (int i = 0; i < sum.size(); ++i) {
        std::cout << sum[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Dot product: " << v1.dot(v2) << std::endl;
    std::cout << "Sum of v1: " << v1.sum() << std::endl;
    std::cout << "v1 squared: ";
    auto squared = v1.pow(2);
    for (int i = 0; i < squared.size(); ++i) {
        std::cout << squared[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Length of v1: " << v1.length() << std::endl;
    std::cout << "Normalized v1: ";
    auto norm = v1.normalized();
    for (int i = 0; i < norm.size(); ++i) {
        std::cout << norm[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}