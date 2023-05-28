#pragma once

class Matrix
{
	int** matrix{};
	int n = 0;
	int m = 0;

	void free();
	void copyFrom(const Matrix& other);

public:
	Matrix();
	Matrix(int n, int m);

	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other) const;
	Matrix& operator*=(int scalar);
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;

	int& operator[](unsigned ind);
	int operator[](unsigned ind) const;
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, int scalar);
Matrix operator*(int scalar, const Matrix& lhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);