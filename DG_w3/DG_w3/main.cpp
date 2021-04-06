#include <iostream>
#include <cmath>
using namespace std;

class VECTOR3D {

public:
	VECTOR3D()
		: x(0.0f), y(0.0f), z(0.0f) {}

	VECTOR3D(float x, float y, float z)
		: x(x), y(y), z(z) {}

	float Magnitude();
	float InnerProduct(VECTOR3D v);
	VECTOR3D CrossPruduct(VECTOR3D v);
	void Normalize();

	VECTOR3D operator+(VECTOR3D v);
	VECTOR3D operator-(VECTOR3D v);
	VECTOR3D operator*(float val);

	float x;
	float y;
	float z;

};

VECTOR3D VECTOR3D::operator+(VECTOR3D v) {
	VECTOR3D result = (*this);
	result.x += v.x;
	result.y += v.y;
	result.z += v.z;

	return result;
}


VECTOR3D VECTOR3D::operator-(VECTOR3D v) {
	VECTOR3D result = (*this);
	result.x -= v.x;
	result.y -= v.y;
	result.z -= v.z;

	return result;
}


VECTOR3D VECTOR3D::operator*(float v) {
	VECTOR3D result = (*this);
	result.x *= v;
	result.y *= v;
	result.z *= v;

	return result;
}


float VECTOR3D::Magnitude() {
	return sqrt(x * x + y * y + z * z);  //#include CMath 안해줘도 되나?
}

float VECTOR3D::InnerProduct(VECTOR3D v) {
	return (x * v.x + y * v.y + z * v.z);
}

VECTOR3D VECTOR3D::CrossPruduct(VECTOR3D v) {

	VECTOR3D result = (*this);
	result.x = y * v.z - z * v.y;
	result.y = z * v.x - x * v.z;
	result.z = x * v.y - y * v.x;

	return result;
}

void VECTOR3D::Normalize() {

	float norm = this->Magnitude();
	this->x /= norm;
	this->y /= norm;
	this->z /= norm;

	return;
}

void printVector(VECTOR3D v);

int main() {

	float a_x, a_y, a_z;
	float b_x, b_y, b_z;

	cout << "Please enter 3 float value for 'Vector a' \n";
	cout << "  >> x : "; 
	cin >> a_x;
	cout << "  >> y : ";
	cin >> a_y;
	cout << "  >> z : ";
	cin >> a_z;

	cout << "Please enter 3 float value for 'Vector b' \n";
	cout << "  >> x : ";
	cin >> b_x;
	cout << "  >> y : ";
	cin >> b_y;
	cout << "  >> z : ";
	cin >> b_z;

	VECTOR3D a = VECTOR3D(a_x, a_y, a_z);
	VECTOR3D b = VECTOR3D(b_x, b_y, b_z);
	VECTOR3D temp = VECTOR3D();

	/* Addiction */
	cout << "\n[Addiction of a and b]\n";
	temp = a + b;
	printVector(temp);

	/* Subtraction */
	cout << "\n[Subtraction of a and b]\n";
	temp = a - b;
	printVector(temp);


	/* Scalar Multiplication */
	cout << "\n[Scalar Mulitplication : 5 * a]\n";
	float scalar = 5;
	temp = a * 5;
	printVector(temp);

	/* Normalization of Vector A */
	cout << "\n[Normalization of vector a]\n";
	a.Normalize();
	printVector(a);

	/* Magnitude of Vector A */
	cout << "\n[Magnitude of vector a]\n";
	cout << a.Magnitude() << endl;;


	/* Dot product of a and b*/
	cout << "\n[Inner/Dot product of a and b]\n";
	cout << a.InnerProduct(b) << endl;

	/* Cross product of a and b*/
	cout << "\n[Outer/Cross product of a and b]\n";
	temp = a.CrossPruduct(b);
	printVector(temp);


	return 0;

}

void printVector(VECTOR3D v) {
	cout << "x: " << v.x << ", y: " << v.y << ", z: " << v.z << endl;
	return;
}
