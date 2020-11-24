#pragma once
#include <vector>
#include <functional>

// Оформление здесь довольно экспериментальное. Заранее извините

typedef std::pair<double, double> dpair;

template <typename function1, typename function2>
double rk4vec1(function1 func1, function2 func2, double x, double u1, double u2, double h) {
	return h * func1(x + h / 2, u1 + h / 2 * func1(x, u1, u2), u2 + h / 2 * func2(x, u1, u2));
}

template <typename function1, typename function2>
double rk4vec2(function1 func1, function2 func2, double x, double u1, double u2, double h) {
	return h * func2(x + h / 2, u1 + h / 2 * func1(x, u1, u2), u2 + h / 2 * func2(x, u1, u2));
}

//std::function<double(double, double, double)> f2_t = f2; //НЕЛЬЗЯ СКАСТОВАТЬ. А ЗНАЧИТ ПРИДЕТСЯ ГДЕ-ТО ХРАНИТЬ ПАРАМЕТРЫ ИЛИ ПЕРЕПИСЫВАТЬ ЗАГОТОВКУ...

struct TResults {
	std::vector<std::pair<double, double> > res_vec;
	std::vector<double> local_mistake_vec;
	std::vector<double> h_vec;
	uint64_t ND = 0;
	uint64_t NH = 0;
	//double max_local_mistake;
};


std::pair<double, double> RK4_new_point(
	std::function<double(double, double)> f, //Функция dy/dx
	double x, double y,
	double h
) {
	double k1 = f(x, y);
	double k2 = f(x + (h / 2), y + (h / 2) * k1);
	double k3 = f(x + (h / 2), y + (h / 2) * k2);
	double k4 = f(x + h, y + h * k3);
	x += h; y += h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	return std::make_pair(x, y);
}



struct vec3 {
	double x;
	double y;
	double v2; //v2=y'
	vec3(double _x, double _y, double _v2) { x = _x; y = _y; v2 = _v2; }
};

struct TResultsSS {
	std::vector<vec3 > res_vec;
	std::vector<double> local_mistake_vec;
	std::vector<double> h_vec;
	uint64_t ND = 0;
	uint64_t NH = 0;
	//double max_local_mistake;
};

vec3 RK4SS_new_point(
	std::function<double(double, double,double)> f1,
	std::function<double(double, double, double)> f2, //Функция dv2/dx
	double x, double v1, double v2,
	double h
) {
	double k1_1 = f1(x, v1,v2);
	double k1_2 = f2(x, v1, v2);
	double k2_1 = f1(x + h / 2, v1 + h / 2 * k1_1, v2 + h / 2 * k1_2);
	double k2_2 = f2(x + h / 2, v1 + h / 2 * k1_1, v2 + h / 2 * k1_2);
	double k3_1 = f1(x + h / 2, v1 + h / 2 * k2_1, v2 + h / 2 * k2_2);
	double k3_2 = f2(x + h / 2, v1 + h / 2 * k2_1, v2 + h / 2 * k2_2);
	double k4_1 = f1(x + h, v1 + h * k3_1, v2 + h * k3_2);
	double k4_2 = f2(x + h, v1 + h * k3_1, v2 + h * k3_2);
	x += h; 
	v1 += h * (k1_1 + 2 * k2_1 + 2 * k3_1 + k4_1) / 6.0;
	v2 += h * (k1_2 + 2 * k2_2 + 2 * k3_2 + k4_2) / 6.0;
	return vec3(x, v1, v2);
}



TResultsSS RungeKutta4SS //Метод РГ 4 порядка для ОДУ 2-го порядка. Можно заставить решать систему если добавить y'= V(x,y,v2).
(
	double xmin, double xmax, //Начало и конец отрезка интегрирования
	double y0, double v20, //Начальные условия, где v2
	double h = 0.001, //Шаг интегрирования 
	bool control = false, //Контроль погрешности
	double eps = 0.000001, //Точность контроля погрешности
	unsigned int NMax = 500 //Максимальное число итераций. Только для версии с переменным шагом.
)
{
	TResultsSS Res;
	std::vector<vec3>& ans=Res.res_vec;
	Res.local_mistake_vec.push_back(0.0);
	Res.h_vec.push_back(0.0);
	double x = xmin, y = y0, v2=v20;
	ans.push_back(vec3(x, y, v2));
	unsigned int i = 0;

	auto func1 = [](double x, double v1, double v2) {
		return 2 - 2 * x;
	};

	auto func2 = [](double x, double v1, double v2) {
		return v1;
	};

	for (; x < xmax - h; ) { //Если до границы осталось меньше h, то b не используется. FIXED (А надо ли?)
		if (!control) {
			auto tmp = RK4SS_new_point(func1, func2, x, y, v2, h);
			x = tmp.x; 
			y = tmp.y;
			v2 = tmp.v2;
			ans.push_back(tmp);
		}
		else {
			if (i++ >= NMax) return Res; //Контроль итераций
			auto p1 = RK4SS_new_point(func1, func2, x, y, v2, h);
			auto p12 = RK4SS_new_point(func1, func2, x, y, v2, h / 2);
			auto p2 = RK4SS_new_point(func1, func2, p12.x, p12.y, p12.v2, h / 2);
  			double etmp = sqrt((p2.v2 - p1.v2)* (p2.v2 - p1.v2) + (p2.y - p1.y) * (p2.y - p1.y));
			double s = etmp / 15; // КОНТРОЛЬ ДЛЯ СИСТЕМЫ. ЧЕМУ ЖЕ РАВНО S?
			if (s > eps) { h = h / 2; ++Res.NH; }
			else {
				Res.local_mistake_vec.push_back(etmp); 
				Res.h_vec.push_back(h);
				x = p1.x; y = p1.y; v2 = p1.v2;
				if (s < (eps / 32)) {
					h = h * 2; ++Res.ND;
				}
				ans.push_back(p1);
			}
		}

	}

	return Res;

}