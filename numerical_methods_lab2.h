#pragma once
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iostream>



/*********** Лабораторная работа #2 **********/

/*                                         Вариант №7                                       */
    //   ksi =  pi/4                                                                                    
   //   mu1 = 1                                                                                    
   //   mu2 =  1                                                                                 
   //   k1(x) = sqrt(2)*cos(x)                                                           
   //   k2(x) = 2                                                                                  
   //   q1(x) = x 
   //   q2(x) = x*x
   //   f1(x) = sin(2x)
   //   f2(x) = sin(x)

   /*****************************************/




const  double  PI_4 = atan(1);
const double PI = PI_4 * 4;
// Функции для тестовой задачи
double  q1Test(double x) {
    return PI_4 ;
}
double q2Test(double x) {
    return PI_4 * PI_4;
}
double  k1Test(double x) {
    return 1;
}
double k2Test(double x) {
    return 2;
}
double  f1Test(double x) {
    return 1;
}
double f2Test(double x) {
    return sqrt(2)/2;
}



// Функции для основной задачи
double q1(double x) {
    return x;
}
double q2(double x) {
    return x * x;
}
double k1(double x) {
    return sqrt(2) / 2 * cos(x);
}
double k2(double x) {
    return 2;
}
double f1(double x) {
    return sin(2 * x);
}
double f2(double x) {
    return sin(x);
}
// Функции аналитического решения
double u1(double x) {
    return (-0.081647581300341) * exp(sqrt(PI)*x/2 ) + (-0.191591963434822) * exp(-sqrt(PI) * x / 2) + (4/PI);
}
double u2(double x) {
    return (-0.077992823107226) * exp(PI/(4*sqrt(2))*x) + (-0.01814096667774) * exp(-PI / (4 * sqrt(2)) * x) + (8*sqrt(2)/(PI*PI));
}
   
TResults analyticalRes(std::function<double(double)> u1, std::function<double(double)> u2, double ksi,int n) {
    double h = 1.0 / n;
    TResults res;
    double x = 0;
    res.res_vec.push_back({ 0,1 });
    for (int i = 0; i < n; i++) {
        x += h;
        if (x <= ksi)
            res.res_vec.push_back({ x,u1(x) });
        else
            res.res_vec.push_back({ x,u2(x) });
    }
    return res;
}

void straightRun(const  std::vector <double>& longDiag, const  std::vector <double>& shortDiagUp, const  std::vector <double>& shortDiagDown, const  std::vector<double>& answer, std::vector<double>& alphas, std::vector <double>& betas) {
    alphas.push_back(-shortDiagUp.at(0) / longDiag.at(0));
    betas.push_back(answer.at(0) / longDiag.at(0));
    for (size_t i = 1; i < longDiag.size() - 1; i++) {
        alphas.push_back(-shortDiagUp.at(i) / (longDiag.at(i) + shortDiagDown.at(i - 1) * alphas.at(i - 1)));
        betas.push_back((answer.at(i) - shortDiagDown.at(i - 1) * betas.at(i - 1)) / (longDiag.at(i) + shortDiagDown.at(i - 1) * alphas.at(i - 1)));
    }
    betas.push_back((answer.back() - shortDiagDown.back() * betas.back()) / (longDiag.back() + shortDiagDown.back() * alphas.back()));
    alphas.push_back(double(0));
}
void backRun(double an, double cn, double answern, const  std::vector <double>& alphas, const  std::vector <double>& betas, TResults &res) {
    res.res_vec[res.res_vec.size() - 1].second = betas.back();
    size_t sz = alphas.size();
    for (size_t i = 1; i < sz; i++) {
        res.res_vec[res.res_vec.size() - 1 - i].second = alphas.at(sz - i - 1) * res.res_vec[res.res_vec.size()-i].second + betas.at(sz - i - 1);
    }
}
void  tridiagonalMatrixAlg(const  std::vector <double>& longDiag, const  std::vector <double>& shortDiagUp, const  std::vector <double>& shortDiagDown, const  std::vector <double>& answer,TResults &res) {
    if (shortDiagUp.size() != shortDiagDown.size() || longDiag.size() == shortDiagDown.size()) {
        throw 1;
    }
    else {
        std::vector <double> alphas;
        std::vector <double> betas;
        straightRun(longDiag, shortDiagUp, shortDiagDown, answer, alphas, betas); // Прямой ход 
        std::vector<double> x;
        backRun(shortDiagDown.back(), longDiag.back(), answer.back(), alphas, betas, res); // Обратный ход
    }

}

TResults tfunc(double start,double b,int n,double ksi,std::function<double(double)> k1, std::function<double(double)> k2, std::function<double(double)> q1, std::function<double(double)> q2, std::function<double(double)> f1, std::function<double(double)> f2) {
    std::vector<double> a;
    std::vector<double> d;
    std::vector<double> phi;
    TResults result;
    result.res_vec.push_back({start,0});
    double h = (double)1 / n;
    bool isChangedStep = false;
    bool isChangedHalfStep = false;
    double x = start;
    for (int i = 1;i<=n; i++) {
       x += h;
       result.res_vec.push_back({ x,0 });
        if (x <= ksi) {
            a.push_back(1/((1/k1(x)+1/k1(x-h))/2));
        }
        else {
            if (isChangedStep) {
                a.push_back(1 / ((1 / k2(x) + 1 / k2(x - h)) / 2));
            }
            else {
                if (x - h != ksi) {
                    a.push_back(1/((((1 / k1(x-h) + 1 / k1(ksi)) / 2)*(ksi-x+h)+ ((1 / k2(ksi) + 1 / k2(x))*(x-ksi) / 2))/h));
                }
                else {
                    a.push_back(1 / ((1 / k2(x) + 1 / k2(x - h)) / 2));
                }
                isChangedStep = true;
            }
        }
        if (i < n) {
            if (x + h / 2 <= ksi) {
                d.push_back((q1(x + h / 2) + q1(x - h / 2) )/2);
                phi.push_back((f1(x + h / 2) + f1(x - h / 2) )/2);
            }
            else if (x - h / 2 >= ksi) {
                d.push_back((q2(x + h / 2) + q2(x - h / 2) )/2);
                phi.push_back((f2(x + h / 2) + f2(x - h / 2) )/2);
            }
            else {
                d.push_back(((q1(x-h/2)+q1(ksi))*(ksi-x+h/2)/2+ (q2(x + h / 2) + q2(ksi)) * (x+h/2-ksi) / 2)/h);
                phi.push_back(((f1(x - h / 2) + f1(ksi)) * (ksi - x + h / 2) / 2 + (f2(x + h / 2) + f2(ksi)) * (x+h/2 - ksi) / 2) / h);
            }
        }
       
    }
    std::vector<double> longDiag;
    std::vector<double> shortUP;
    std::vector<double> shortDown;
    std::vector<double> answer;
    answer.push_back(1);
    longDiag.push_back(1);
    shortUP.push_back(0);

    for (int i = 0; i < n-1 ; i++) {
       double db =  -a.at(i) - a.at(i + 1);
        longDiag.push_back((-a.at(i) - a.at(i + 1)) / (h * h) - d.at(i));
        shortUP.push_back(a.at(i + 1)/(h*h));
        shortDown.push_back(a.at(i)  / (h * h));
        answer.push_back(-phi.at(i));
    }
    answer.push_back(1);
    longDiag.push_back(1);
    shortDown.push_back(0);
    tridiagonalMatrixAlg(longDiag, shortUP, shortDown, answer,result);
    return result;
}


