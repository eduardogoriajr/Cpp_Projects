#include <iostream>
using namespace std;
class Rectangle
{
	private:
float Length, Width;
	public:
void setLength();
void setWidth();
float computePerimeter();
float computeArea();
void displayDimensions();
};

void Rectangle::setLength() {
	cout << "Enter length: ";
	cin >> Length;
}
void Rectangle::setWidth() {
	cout << "Enter width: ";
	cin >> Width;
}
float Rectangle::computePerimeter() {
	return 2 * (Length + Width);
}
float Rectangle::computeArea() {
	return Length * Width;
}
void Rectangle::displayDimensions() {
	cout << "Rectangle Details: " << endl << "Length: " << Length << " units"<< endl << "Width: " << Width << " units" << endl;
}

int main() {
	Rectangle r1;
	r1.setLength();
	r1.setWidth();
	r1.displayDimensions();
	cout<<"Area: " << r1.computeArea() << " square units" <<endl;
	cout<<"Perimeter: " << r1.computePerimeter() << " units" <<endl;

	
	return 0;
}

