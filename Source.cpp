#include <iostream>
using namespace std;

class Complex //создаем класс
{
private:
	double real; //действительная часть
	double imaginary; //мнимая часть 
public:
	//конструктор 
	Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {} 

	//сложение(передаем ссылку на объект класса)
	Complex add(const Complex& num) const
	{
		return Complex(real + num.real, imaginary + num.imaginary);
	}
	//вычитание
	Complex subtract(const Complex& num) const
	{
		return Complex(real - num.real, imaginary - num.imaginary);
	}
	//умножение
	Complex multiply(const Complex& num) const
	{
		return Complex(real * num.real - imaginary * num.imaginary,real * num.imaginary + imaginary * num.real);
	}
	//деление
	Complex divide(const Complex& num) const
	{
		double denominator = num.real * num.real + num.imaginary * num.imaginary; //знаменатель
		if (denominator == 0)
		{
			throw runtime_error("\nThe denominator = 0!"); //сообщение об ошибке
		}
		return Complex((real * num.real + imaginary * num.imaginary) / denominator, (imaginary * num.real - real * num.imaginary) / denominator);
	}
	//print
	void print()
	{
		cout << "The complex number: ";
		cout << real;
		if (imaginary >= 0) //если мнимая часть неотрицательная
		{
			cout << "+" << imaginary << "i"; 
		}
		else 
		{
			cout << imaginary << "i";
		}
		cout << "\n";
	}
};
	


int main()
{
	double r1, r2, i1, i2;
	cout << "Enter the real part of first number" << endl; //действительная часть числа1
	cin >> r1;
	cout << "Enter the imaginary part of first number" << endl; //мнимая часть числа1
	cin >> i1;
	cout << "Enter the real part of second number" << endl; //действительная часть числа2
	cin >> r2;
	cout << "Enter the imaginary part of second number" << endl; //мнимая часть числа2
	cin >> i2;
	Complex n1(r1, i1); //число1
	Complex n2(r2, i2); //число2
	Complex sum, sub, mul, div; //результаты операций
	int q;
	cout << endl << "what you want to do?" << endl;
	cout << "1 - add, 2 - subtract, 3 - multiply, 4 - divide" << endl;
	cin >> q;
	switch (q)
	{
	case 1:
		sum = n1.add(n2);
		cout << endl << "\n~ The result ~\n" << endl;
		sum.print();
		break;
	case 2:
		sub = n1.subtract(n2);
		cout << "\n~ The result ~\n" << endl;
		sub.print();
		break;
	case 3:
		mul = n1.multiply(n2);
		cout << "\n~ The result ~\n" << endl;
		mul.print();
		break;
	case 4:
		try
		{
			div = n1.divide(n2);
		}
		catch (const runtime_error& e)
		{
			cerr << "Error" << e.what() << endl;
			exit(0);
		}
		cout << "\n~ The result ~\n" << endl;
		div.print();
		break;
	}
	return 0;
}