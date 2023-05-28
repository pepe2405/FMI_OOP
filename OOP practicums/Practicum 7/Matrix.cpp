#include "Matrix.h"
#include <exception>

Matrix::Matrix() : Matrix(2, 2) {}

Matrix::Matrix(int n, int m) 
{
	this->n = n;
	this->m = m;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
}

void Matrix::copyFrom(const Matrix& other)
{
	n = other.n;
	m = other.m;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::free()
{
	n = 0;
	m = 0;
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}


//OPERATORS
Matrix& Matrix::operator+=(const Matrix& other)
{
	if (n != other.n || m != other.m)
		throw std::exception("The matrices are different sizes!");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			matrix[n][m] += other.matrix[n][m];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (n != other.n || m != other.m)
		throw std::exception("The matrices are different sizes!");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			matrix[n][m] -= other.matrix[n][m];
	}

	return *this;
}

int& Matrix::operator[](unsigned ind)
{
	if (ind > n + m)
		throw std::exception("Out of range");
	return *matrix[ind];
}

int Matrix::operator[](unsigned ind) const
{
	return *matrix[ind];
}

Matrix& Matrix::operator*=(const Matrix& other) const
{
	if (n != other.m)
		throw std::exception("Cannot multiply, bcs rows and colms are diff size!");

	Matrix result(n, other.m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < other.m; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < other.n; k++)
			{
				result[i][j] += (matrix[i][k] * other.matrix[k][j]);
			}
		}
	}

	return result;
}

Matrix& Matrix::operator*=(int scalar)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] *= scalar;
		}
	}

	return *this;
}

bool Matrix::operator==(const Matrix& other) const
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != other.matrix[i][j])
				return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(this->matrix == other.matrix);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix lhsCopy = lhs;
	lhsCopy += rhs;
	return lhsCopy;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix lhsCopy = lhs;
	lhsCopy -= rhs;
	return lhsCopy;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	return (lhs *= rhs);
}

Matrix operator*(const Matrix& lhs, int scalar)
{
	Matrix lhsCopy = lhs;
	return (lhsCopy *= scalar);
}

Matrix operator*(int scalar, const Matrix& lhs)
{
	Matrix lhsCopy = lhs;
	return (lhsCopy *= scalar);
}
