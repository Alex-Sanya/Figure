#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Figure
{
public:
	void centre(double x, double y)
	{
		cout << "Centre: ("<<x/2<<","<<y<<")"<<endl;
	}
};

class Trapezium : public Figure 
{
private:
	double top_base, bottom_base, side;
public:
	void set_top_base(double value)
	{
		top_base = value;
	}
	void set_bottom_base(double value)
	{
		bottom_base = value;
	}
	void set_side(double value)
	{
		side = value;
	}

	double get_top_base()
	{
		return top_base;
	}
	double get_bottom_base()
	{
		return bottom_base;
	}
	double get_side()
	{
		return side;
	}
	
	double square()
	{
		return (sqrt(side * side - (bottom_base - top_base) * (bottom_base - top_base) / 4)) *
			((bottom_base + top_base) / 2);
	}
	double coord_X()
	{
		return get_bottom_base();
	}
	double coord_Y()
	{
		return sqrt(side * side - (bottom_base - top_base) * (bottom_base - top_base) / 4);
	}
};

class Rhombus : public Figure
{
private:
	double side;
public:
	void set_side(double value)
	{
		side = value;
	}
	double get_side()
	{
		return side;
	}
	double square()
	{
		return side * side * sin(3.141592653589 / 6);
	}
	double coord_X()
	{
		return sqrt(side * side - side * sin(3.141592653589 / 6) * side * sin(3.141592653589 / 6)) + side; //ffffffffffffffffffffff
	}
	double coord_Y()
	{
		return side * sin(3.141592653589 / 6);
	}
};

class Pentagon : public Figure
{
private:
	double side;
public:
	void set_side(double value)
	{
		side = value;
	}
	double get_side()
	{
		return side;
	}
	double square()
	{
		return 5/2* sqrt((side / (2 * sin(3.141592653589 / 5))) * (side / (2 * sin(3.141592653589 / 5))) - (side * side / 4)) *side;
	}
	double coord_X()
	{
		return get_side();
	}
	double coord_Y()
	{
		return square()*2/(5*side);
	}
};

double input_positive(double* x)
{
	int check;
	
	while (1)
	{
		cin >> check;
		if (check <= 0) cout << "Enter a positive number!";
		else return check;
	}
}

void input_trapezium(Trapezium *trapezium)
{
	double top_base, bottom_base, side;
	cout << "Enter the length of the top base: ";
	trapezium->set_top_base(input_positive(&top_base));
	cout << "\nEnter the length of the bottom base: ";
	trapezium->set_bottom_base(input_positive(&bottom_base));
	cout << "\nEnter the length of the side: ";
	trapezium->set_side(input_positive(&side));
}

void input_rhombus(Rhombus *rhombus)
{
	double side;
	cout << "\nEnter the length of the side: ";
	rhombus->set_side(input_positive(&side));
}

void input_pentagon(Pentagon *pentagon)
{
	double side;
	cout << "\nEnter the length of the side: ";
	pentagon->set_side(input_positive(&side));
}

void out_trapezuim(Trapezium *trapezium)
{
	double top_base=trapezium->get_top_base(),
		bottom_base=trapezium->get_bottom_base(),
		side=trapezium->get_side(),
		height;
	height = sqrt(side * side - (bottom_base - top_base) * (bottom_base - top_base) / 4);
	cout << "Trapezium:"<<endl;
	cout << "Verticals: [(0,0), (" << height << "," << (bottom_base - top_base) / 2 << "), (" <<
		(bottom_base - top_base) / 2 + top_base << ","<<height<<"), (" <<
		bottom_base<<",0)]"<<endl;
	trapezium->centre(trapezium->coord_X(), trapezium->coord_Y());
	cout << "Square: " << trapezium->square() << endl << endl;
}

void out_rhombus(Rhombus *rhombus)
{
	double side = rhombus->get_side(), height;
	height= side * sin(3.141592653589 / 6);
	cout << "Rhombus: " << endl;
	cout << "Verticals: [(0,0), (" << sqrt(side * side - height * height) << "," << height << "), ("<<
		sqrt(side * side - height * height)+side << "," << height << "), (0," << side<<")]"<<endl;
	rhombus->centre(rhombus->coord_X(), rhombus->coord_Y());
	cout << "Square: " << rhombus->square() << endl << endl;
}

void out_pentagon(Pentagon *pentagon)
{
	double side = pentagon->get_side(), tmp1, tmp2;
	tmp1 = side * cos(3.141592653589 / 5);
	tmp2 = side * sin(3.141592653589 / 5);
	cout << "Pentagon: " << endl;
	cout << "Verticals: [(0,0), (" << -tmp1 << "," << tmp2 << "), (" <<
		side / 2 << "," << sqrt((side / (2 * sin(3.141592653589 / 5))) * (side / (2 * sin(3.141592653589 / 5))) - (side * side / 4)) << "), (" <<
		tmp1 + side << "," << tmp2 << "), (" <<
		side << ",0)]" << endl;
	pentagon->centre(pentagon->coord_X(), pentagon->coord_Y());
	cout << "Square: " << pentagon->square() << endl << endl;
}

void main()
{
	float total_square;
	Trapezium trapezium;
	Rhombus rhombus;
	Pentagon pentagon;
	input_trapezium(&trapezium);
	input_rhombus(&rhombus);
	input_pentagon(&pentagon);
	vector<Figure> vec = {trapezium, rhombus, pentagon};
	out_trapezuim(&trapezium);
	out_rhombus(&rhombus);
	out_pentagon(&pentagon);
	total_square = trapezium.square()+rhombus.square()+pentagon.square();
	cout << "Total sqare: " << total_square;
}