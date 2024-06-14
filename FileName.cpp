#include<iostream>
using namespace std;

class Point
{
	int x;
	int y;

public:
	Point() {}
	Point(int a, int b);
	void Print();
	
	Point operator+ (Point& b)
	{
		Point c;
		c.x = (this->x * b.y) + (this->y * b.x);
		c.y = this->y * b.y;
		return c;
	}
	
	Point operator- (Point& b)
	{
		Point c;
		c.x = (this->x * b.y) - (this->y * b.x);
		c.y = this->y * b.y;
		return c;
	}
	Point operator* (Point& b)
	{
		Point c;
		c.x = this->x * b.x;
		c.y = this->y * b.y;
		return c;
	}
	Point operator/ (Point& b)
	{
		Point c;
		c.x = this->x * b.y;
		c.y = this->y * b.x;
		return c;
	}


	Point operator+ (int b)
	{
		Point c;
		c.x = this->x + (this->y * b);
		c.y = this->y;
		return c;
	}

	Point operator- (int b)
	{
		Point c;
		c.x = this->x - (this->y * b);
		c.y = this->y;
		return c;
	}
	Point operator* (int b)
	{
		Point c;
		c.x = this->x * b;
		c.y = this->y;
		return c;
	}
	Point operator/ (int b)
	{
		Point c;
		c.x = this->x;
		c.y = this->y * b;
		return c;
	}
};

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::Print()
{
	cout << "X: " << x << "\tY: " << y << endl;
}


int main()
{
	Point a(3, 4), b(1, 5);

	/*Point c = a + b;
	c.Print(); */

	/*Point c = a - b;
	c.Print();*/

	Point c = a + ;
	c.Print();
}

