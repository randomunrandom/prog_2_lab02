//#include <cstdlib>
#include <iostream>
#include <cmath>
#include "vect.h"
#include "matr.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int s;
    double e[9] = {1,0,0,0,1,0,0,0,1};
    double *aa = new double [s*s];
    double *ab = new double [s];

    cout << "введите размерность матрицы: ";
    cin >> s;
    cout << "введите матрицу коэфициентов: " << endl << "(";
    for(int i = 0; i < s*s; i++) cin >> aa[i];
    cout << ")" << endl;
    matr mp(s, aa);
    cout << "введённая матрица: " << endl << mp << endl;
    cout << "введите вектор ответов: " << endl << "(";
    for(int i = 0; i < s; i++)  cin >> ab[i];
    cout << ")" << endl;
    vect va(s, ab);
    cout << "введённый вектор: " << endl << va << endl;
    vect a(s);
    const double eps = 0.001; //желаемая точность
    double* TempX = new double[s];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
    do {
        for (int i = 0; i < s; i++) {
            TempX[i] = va.getVi(i);
            for (int g = 0; g < s; g++) if (i != g) TempX[i] -= mp.getMcord(i, g) * a.getVi(g);
            TempX[i] /= mp.getMcord(i, i);
        }
        norm = fabs(a.getVi(0) - TempX[0]);
        for (int h = 0; h < s; h++) {
            if (fabs(a.getVi(h) - TempX[h]) > norm) norm = fabs(a.getVi(h) - TempX[h]);
            a.setVi(h, TempX[h]);
        }
    } while (norm > eps);
    delete[] TempX;
    cout << "ответ:" << a;


}