// программа, которая считает интеграл
// 1.выбрать функцию (sin x, cos x, x, x^2) 2.выбрать метод интегриования 3.выбрать шаг инт-ия и диапазона 4.интегрировать (получить рез-т) 5.выход


#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

double sine (double x)
{	return sin(x);}

double cosine (double x)
{	return cos(x);}

double line (double x)
{	return x;}

double square (double x)
{	return x*x;}

double column (function<double(double)> &func, double start, double end, double h)
{
	double result = 0, k = start + h;
	while( k < end){
		result += func(k - 0.5*h) * h;
		k += h;	
	}
	result += func(0.5 * (end + k - h)) * (end - k + h);
	return result;
}

double trapeze (function<double(double)> &func, double start, double end, double h)
{
	double result = 0, k = start + h;
	while( k < end){
		result += 0.5*(func(k - h) + func(k)) * h;
		k += h;	
	}
	result += 0.5*(func(k - h) + func(end)) * (end - k + h);
	return result;
}

int main() {
	int ch1, ch2, method = 0;
	double start = std::nan(""), 
		   end = std::nan(""), 
		   h = 0;
	double result;
	function<double(double)> func;

	while(true){
		cout << "What will we do? \n Enter 1 if you want to choose a function,\n" \
		" 2 if you want  to choose an integration method,\n" \
		" 3-limits and integration step,\n" \
		" 4-integrate and view the result,\n" \
		" 5-exit.\n";
		cin >> ch1;
		
		switch (ch1) {
			case 1:
				//выбрать функцию
				cout << "Enter 1 if you want to integrate the sin x function,\n" \
				" 2 - cos x, 3 - x, 4 - x^2 \n";
				cin >> ch2;
				
				switch (ch2) {
				case 1:
					func = sine;
					break;
				case 2:
					func = cosine;
					break;
				case 3:
					func = line;
					break;
				case 4:
					func = square;
					break;
					
				default:
					cout << "invalid input";
					break;
				}
				break;
			case 2:
				//выбрать метод
				cout << " If you want to select the column integration method enter 1; \n" \
				"if you want to select the trapeze integration method enter 2,\n";
				cin >> method;
				
				if (method != 1 and method != 2){
					method = 0;
					cout << "invalid inpur";
				}
				break;
			case 3:
				//выбрать шаг и диапазон
				cout  << "Enter the beginning of the range, the end of the range, and the integration step.\n";
				cin >> start >> end >> h;
				break;
			case 4:
				//интегрировать
				if(! func){ // вы не выбрали функцию
					cout << "you didn't choose a function\n";
					break;
				}
				if( method == 0){ 
					cout << "you didn't choose a method\n";
					break;
				}
				if(h == 0){ 
					cout << "you didn't choose a step\n";
					break;
				}
				if(isnan(start) or isnan(end)){ 
					cout << "you didn't choose a range\n";
					break;
				}
				
				if (method == 1)
					result = column(func, start, end, h);
				else result = trapeze(func, start, end, h);
				cout << "Result: " << result << "\n";
				break;
			case 5:
				return 0;
				break;
				
			default:
				cout << "Choose correct number!";
				break;
		}
	}
    
}
