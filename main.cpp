#include <iostream>
#include "random_numbers.h"

using namespace std;

int main()
{

    cout << "Случайное целое равномерно в [1, 100]: " << random_int(1, 100) << endl;
    cout << "Равномерный закон. Случайное число в интервале [-2, 5]: " << random_uniform(-2, 5) << endl;
    cout << "Нормальный закон. Случайное число N(10, 2): " << random_normal(10, 2) << endl;
    cout << "Распределение Коши. Случайное число Cauchy(0.5, 0.1): " << random_cauchy(0.5, 0.1) << endl;
    cout << "Распределение Лапласа. Случайное число Laplace(0.1, 0.3): " << random_laplace(0.1, 0.3) << endl;
    cout << "Распределение Стьюдента. Случайное число T(0, 1, df=5): " << random_student(0, 1, 5) << endl;
    cout << "Распределение Логистическое. Случайное число Logistic(1, 2): " << random_logistic(1, 2) << endl;

    return 0;
}
