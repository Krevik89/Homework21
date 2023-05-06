#include <iostream>
#include<iostream>
#include<fstream>

using namespace std;

/*Создать абстрактный базовый класс с виртуальной функцией — корни уравнения. Создать производные классы:
класс линейных уравнений и класс квадратных уравнений.
Определить функцию вычисления корней уравнений.*/
class Root
{
public:
    virtual void getroot() = 0;
};
class Linear : public Root
{
private:
    double first;
    double second;
public:
    Linear(double f, double s) : first(f), second(s)
    {
    }
    void getroot()
    {
        double x3;
        x3 = (first && second) ? -second / first : 0;
        cout << x3 << endl;
    }

};
class Square : public Root
{
private:
    double a;
    double b;
    double c;
public:
    Square(double A, double B, double C) : a(A), b(B), c(C)
    {
    }
    void getroot()
    {
        double x1, x2, d;
        if (a == 0.0) {
            cout << "Not root equation !\n";
        }

        d = b * b - 4 * a * c;
        cout << "d=" << d << "\n";
        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << x1 << x2 << endl;
        }
        else if (d == 0.0) {
            x1 = (-b / (2 * a)); x2 = x1;
            cout << x1;
        }
        else {
            cout << "equation roots not found\n";
        }
    }
};

//--------------------------------------------------------------\\

class Point
{
public:
	int X;
	int Y;
	Point(int x, int y) : X{ x }, Y{ y } {};
};
class Shape
{
protected:
	Point p;
	int straight;
public:
	Shape(int str, int x, int y) :straight{ str }, p{ x,y } {  };
	virtual void Save(std::string file = "h.txt")
	{
		std::ofstream out;
		out.open(file);
		if (!out.is_open())
		{
			std::cout << "\nERROR\n";
		}
		else
		{
			out << p.X << " " << p.Y << " " << straight << std::endl;
		}
		out.close();
	};
	virtual void Show() { std::cout << "Point X : " << p.X << "\n      Y : " << p.Y << std::endl; };
	virtual void Load(std::string file = "h.txt")
	{
		std::ifstream in;
		in.open(file);
		if (!in.is_open())
		{
			std::cout << "\nERROR\n";
			p.X = p.Y = straight = 0;
		}
		else
		{
			in >> p.X >> p.Y >> straight;
		}
		in.close();
	};
	virtual ~Shape() = 0;
};
Shape:: ~Shape() {};
class Square : public Shape
{
	int& length = straight;
public:
	Square(int size = 0, int x = 0, int y = 0) :Shape(size, x, y) {};
	virtual void Show()override
	{
		std::cout << "Left point\n";
		Shape::Show();
		std::cout << "length  = " << length << std::endl;

	}
	virtual void Save(std::string file = "Square.txt")override
	{
		if (file == "h.txt")
		{
			file = "Square.txt";
		}
		Shape::Save(file);
	}
	virtual void Load(std::string file = "Square.txt")override
	{
		if (file == "h.txt")
		{
			file = "Square.txt";
		}
		Shape::Load(file);
	}
};
class Circle : public Shape
{
	int& radius = straight;
public:
	Circle(int size = 0, int x = 0, int y = 0) :Shape(size, x, y) {};
	virtual void Show()override
	{
		std::cout << "Center point\n";
		Shape::Show();
		std::cout << "Circle radius  = " << radius << std::endl;
	}
	virtual void Save(std::string file = "Circle.txt")override
	{
		if (file == "h.txt")
		{
			file = "Circle.txt";
		}
		Shape::Save(file);
	}
	virtual void Load(std::string file = "Circle.txt")override
	{
		if (file == "h.txt")
		{
			file = "Circle.txt";
		}
		Shape::Load(file);
	}
};
class Rectangle : public Shape
{
	int& wall1 = straight;
	int wall2;
public:
	Rectangle(int s2, int size = 0, int x = 0, int y = 0) :Shape(size, x, y), wall2{ s2 } {};
	virtual void Load(std::string file = "Rectangle.txt") override
	{
		if (file == "h.txt")
		{
			file = "Rectangle.txt";
		}
		std::ifstream in;
		in.open(file);
		if (!in.is_open())
		{
			std::cout << "\nERROR\n";
			p.X = p.Y = wall1 = wall2 = 0;
		}
		else
		{
			in >> p.X >> p.Y >> wall1 >> wall2;
		}
		in.close();
	}
	virtual void Show()override
	{
		std::cout << "Center point\n";
		Shape::Show();
		std::cout << "wall 1 = " << wall1 << "\nwall 2 = " << wall2 << std::endl;
	}
	virtual void Save(std::string hfile = "Rectangle.txt") override
	{
		if (hfile == "h.txt")
		{
			hfile = "Rectangle.txt";
		}
		std::ofstream out;
		out.open(hfile);
		if (!out.is_open())
		{
			std::cout << "\nERROR\n";
		}
		else
		{
			out << p.X << " " << p.Y << " " << wall1 << " " << wall2 << std::endl;
		}
		out.close();
	}
};

int main()
{
    /* Linear line(5, -5);
    Square squa(2, -2, -4);
    line.getroot();
    squa.getroot();
    system("pause");*/
	Shape* arr[4];
	arr[0] = new Square(1);
	arr[1] = new Circle(2);
	arr[2] = new Rectangle(2);
	for (int i = 0; i < 3; ++i)
	{
		arr[i]->Load();
		arr[i]->Show();
	}
	for (int i = 0; i < 3; ++i)
	{
		arr[i]->Save();
	}
}


