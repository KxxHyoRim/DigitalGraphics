#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class VECTOR3D {

public:
	VECTOR3D()
		: x(0.0f), y(0.0f), z(0.0f) {}

	VECTOR3D(float x, float y, float z)
		: x(x), y(y), z(z) {}

	/* Uncomment : ctrl + k + u */

	//float Magnitude();
	//float InnerProduct(VECTOR3D v);
	//VECTOR3D CrossPruduct(VECTOR3D v);
	//void Normalize();

	//VECTOR3D operator+(VECTOR3D v);
	//VECTOR3D operator-(VECTOR3D v);
	//VECTOR3D operator*(float val);

	float x;
	float y;
	float z;

};

class VECTOR2D {

public:
	VECTOR2D()
		: x(0.0f), y(0.0f) {}

	VECTOR2D(float x, float y)
		: x(x), y(y) {}


	float x;
	float y;

};

class MATRIX {
public:

	MATRIX()
		:ele{ 0 } {}

	MATRIX Transpose();
	MATRIX Inverse();
	float Determinant();

	MATRIX operator+(MATRIX m);
	MATRIX operator-(MATRIX m);
	MATRIX operator*(MATRIX m);
	MATRIX operator*(float m);

	VECTOR2D operator*(VECTOR2D v);
	VECTOR3D operator*(VECTOR3D v);

	float ele[3][3];
};

/* Implementation */
MATRIX MATRIX::operator+(MATRIX m) {
	MATRIX result;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.ele[i][j] = ele[i][j] + m.ele[i][j];

	return result;
}

MATRIX MATRIX::operator-(MATRIX m) {
	MATRIX result;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.ele[i][j] = ele[i][j] - m.ele[i][j];

	return result;
}

MATRIX MATRIX::operator*(MATRIX m) {
	MATRIX result;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.ele[i][j] = 0.0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				result.ele[i][j] += ele[i][k] * m.ele[k][j];

	return result;
}

MATRIX MATRIX::operator*(float m) {
	MATRIX result;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.ele[i][j] = ele[i][j] * m;

	return result;
}

VECTOR2D MATRIX::operator*(VECTOR2D v) {
	VECTOR2D result;

	result.x = ele[0][0] * v.x + ele[0][1] * v.y;
	result.y = ele[1][0] * v.x + ele[1][1] * v.y;

	return result;
}

VECTOR3D MATRIX::operator*(VECTOR3D v) {
	VECTOR3D result;

	result.x = ele[0][0] * v.x + ele[0][1] * v.y + ele[0][2] * v.z;
	result.y = ele[1][0] * v.x + ele[1][1] * v.y + ele[1][2] * v.z;
	result.z = ele[2][0] * v.x + ele[2][1] * v.y + ele[2][2] * v.z;

	return result;
}
MATRIX MATRIX::Transpose() {
	MATRIX result;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.ele[i][j] = ele[j][i];

	return result;
}
MATRIX MATRIX::Inverse() {

	MATRIX	result;
	float	det = this->Determinant();

	if (det == 0) {
		cout << "This matrix is not INVERTABLE(det==0)\n";
		return result;
	}

	result.ele[0][0] = (ele[1][1] * ele[2][2] - ele[2][1] * ele[1][2]);
	result.ele[0][1] = (ele[0][2] * ele[2][1] - ele[0][1] * ele[2][2]);
	result.ele[0][2] = (ele[0][1] * ele[1][2] - ele[0][2] * ele[1][1]);
	result.ele[1][0] = (ele[1][2] * ele[2][0] - ele[1][0] * ele[2][2]);
	result.ele[1][1] = (ele[0][0] * ele[2][2] - ele[0][2] * ele[2][0]);
	result.ele[1][2] = (ele[1][0] * ele[0][2] - ele[0][0] * ele[1][2]);
	result.ele[2][0] = (ele[1][0] * ele[2][1] - ele[2][0] * ele[1][1]);
	result.ele[2][1] = (ele[2][0] * ele[0][1] - ele[0][0] * ele[2][1]);
	result.ele[2][2] = (ele[0][0] * ele[1][1] - ele[1][0] * ele[0][1]);

	result = result * (1 / det);

	return result;
}
float MATRIX::Determinant() {
	float tmp1 = ele[0][0] * (ele[1][1] * ele[2][2] - ele[1][2] * ele[2][1]);
	float tmp2 = ele[0][1] * (ele[1][0] * ele[2][2] - ele[1][2] * ele[2][0]);
	float tmp3 = ele[0][2] * (ele[1][0] * ele[2][1] - ele[1][1] * ele[2][0]);

	return tmp1 - tmp2 + tmp3;
}

/* Function Declaration for Main() */
void printVector(VECTOR2D v);
void printVector(VECTOR3D v);
void printMATRIX(MATRIX m);

int main() {


	MATRIX a, b, c, matrix;
	VECTOR3D v;
	float t;

	ifstream readData;
	readData.open("input.txt");
	if (readData.is_open()) {

		while (!readData.eof()) {
			string tmp;
			int idx1, idx2;

			/* Matrix a */
			for (int i = 0; i < 3; i++) {
				// txt 한줄 읽기
				getline(readData, tmp);
				
				// " " 인덱스 알아내기
				idx1 = tmp.find(" ");
				idx2 = tmp.find(" ", idx1 + 1);

				// 문자(숫자)추출 후 Matrix 배열에 저장
				a.ele[i][0] = stof(tmp.substr(0, idx1));
				a.ele[i][1] = stof(tmp.substr(idx1 + 1, idx2 - idx1 - 1));
				a.ele[i][2] = stof(tmp.substr(idx2 + 1, tmp.length() - idx2));

			}
			getline(readData, tmp);

			/* Matrix b */
			for (int i = 0; i < 3; i++) {
				// txt 한줄 읽기
				getline(readData, tmp);

				// " " 인덱스 알아내기
				idx1 = tmp.find(" ");
				idx2 = tmp.find(" ", idx1 + 1);
				// 문자(숫자)추출 후 Matrix 배열에 저장
				b.ele[i][0] = stof(tmp.substr(0, idx1));
				b.ele[i][1] = stof(tmp.substr(idx1 + 1, idx2 - idx1 - 1));
				b.ele[i][2] = stof(tmp.substr(idx2 + 1, tmp.length() - idx2));

			}
			getline(readData, tmp);


			/* Scalar t */
			getline(readData, tmp);
			t = stof(tmp);
			getline(readData, tmp);


			/* Vector v */
			getline(readData, tmp);
			idx1 = tmp.find(" ");
			idx2 = tmp.find(" ", idx1 + 1);
			v.x = stof(tmp.substr(0, idx1));
			v.y = stof(tmp.substr(idx1 + 1, idx2 - idx1 - 1));
			v.z = stof(tmp.substr(idx2 + 1, tmp.length() - idx2));

		} 
		readData.close();
	}

	
	/* Addiction */
	//a.ele[0][0] = 1.0f;	a.ele[0][1] = 0.0f; a.ele[0][2] = 0.0f;
	//a.ele[1][0] = 0.0f;	a.ele[1][1] = 1.0f; a.ele[1][2] = 0.0f;
	//a.ele[2][0] = 0.0f;	a.ele[2][1] = 0.0f; a.ele[2][2] = 1.0f;

	//b.ele[0][0] = 1.0f;	b.ele[0][1] = 0.0f; b.ele[0][2] = 0.0f;
	//b.ele[1][0] = 0.0f;	b.ele[1][1] = 1.0f; b.ele[1][2] = 0.0f;
	//b.ele[2][0] = 0.0f;	b.ele[2][1] = 0.0f; b.ele[2][2] = 1.0f;
	c = a + b;
	cout << "c = a + b\n";
	printMATRIX(c);



	/* Subtraction */
	c = a - b;
	cout << "c = a - b\n";
	printMATRIX(c);



	/* Multiplication */
	c = a * t;
	cout << "c = a * t\n";
	printMATRIX(c);



	/* Matrix * 2DVector */
	matrix.ele[0][0] = 1.0f;	matrix.ele[0][1] = 2.0f;
	matrix.ele[1][0] = -2.0f;	matrix.ele[1][1] = 1.0f;
	VECTOR2D P = VECTOR2D(2.0f, -1.0f);
	VECTOR2D d = matrix * P; // call overloading
	cout << "MATRIX * VECTOR2D\n";
	printVector(d);



	/* Transpose */
	//a.ele[0][0] = 1.0f;	a.ele[0][1] = 0.0f; a.ele[0][2] = 1.0f;
	//a.ele[1][0] = 0.0f;	a.ele[1][1] = 1.0f; a.ele[1][2] = 0.0f;
	//a.ele[2][0] = 0.0f;	a.ele[2][1] = 0.0f; a.ele[2][2] = 1.0f;
	c = a.Transpose();
	cout << "a.Transpose()\n";
	printMATRIX(c);



	/* Inverse */
	//a.ele[0][0] = 5.0f;	a.ele[0][1] = 1.0f; a.ele[0][2] = 1.0f;
	//a.ele[1][0] = 1.0f;	a.ele[1][1] = 5.0f; a.ele[1][2] = 1.0f;
	//a.ele[2][0] = 1.0f;	a.ele[2][1] = 1.0f; a.ele[2][2] = 5.0f;
	cout << "a.Inverse()\n";
	c = a.Inverse();
	printMATRIX(c);



	/* Determinant */
	//a.ele[0][0] = 1.0f;	a.ele[0][1] = 0.0f; a.ele[0][2] = 1.0f;
	//a.ele[1][0] = 0.0f;	a.ele[1][1] = 3.0f; a.ele[1][2] = 2.0f;
	//a.ele[2][0] = 0.0f;	a.ele[2][1] = 4.0f; a.ele[2][2] = 1.0f;
	float det = a.Determinant();
	cout << "a.Determinant() : " << det << endl;

	return 0;
}

void printVector(VECTOR2D v) {
	cout << "x: " << v.x << ", y: " << v.y << endl << endl;
	return;
}

void printVector(VECTOR3D v) {
	cout << "x: " << v.x << ", y: " << v.y << ", z: " << v.z << endl << endl;
	return;
}

void printMATRIX(MATRIX m) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout.precision(1);
			cout << setw(6) << right << m.ele[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return;
}
