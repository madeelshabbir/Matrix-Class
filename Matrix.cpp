#include<iostream>
using namespace std;
class Matrix
{
private:
	int row;
	int col;
	double **array;
public:
	Matrix()
	{
		row = 0;
		col = 0;
		array = new double*[row];
		for (int i = 0; i < row; i++)
		{
			array[i] = new double[col];
		}
	}
	Matrix(int s)
	{
		row = s;
		col = s;
		array = new double*[row];
		for (int i = 0; i < row; i++)
		{
			array[i] = new double[col];
			for (int j = 0; j < col; j++)
			{
				array[i][j] = 0;
			}
		}
	}
	Matrix(int r,int w)
	{
		row = r;
		col = w;
		array = new double*[row];
		for (int i = 0; i < row; i++)
		{
			array[i] = new double[col];
			for (int j = 0; j < col; j++)
			{
				array[i][j] = 0;
			}
		}
	}
	Matrix(int r, int w, double v)
	{
		row = r;
		col = w;
		array = new double*[row];
		for (int i = 0; i < row; i++)
		{
			array[i] = new double[col];
			for (int j = 0; j < col; j++)
			{
				array[i][j] = v;
			}
		}
	}
	Matrix(const Matrix &m)
	{
		row = m.row;
		col = m.col;
		array = new double*[m.row];
		for (int i = 0; i < m.row; i++)
		{
			array[i] = new double[m.col];
			for (int j = 0; j < m.col; j++)
			{
				array[i][j] = m.array[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] array[i];
		}
		delete[] array;
	}
	Matrix operator+(const Matrix &m) const
	{
		if (row == m.row && col == m.col)
		{
			Matrix temp;
			temp.row = m.row;
			temp.col = m.col;
			temp.array = new double*[temp.row];
			for (int i = 0; i < temp.row; i++)
			{
				temp.array[i] = new double[temp.col];
				for (int j = 0; j < temp.col; j++)
				{
					temp.array[i][j] = array[i][j] + m.array[i][j];
				}
			}
			return temp;
		}
		else
		{
			throw;
		}
	}
	Matrix operator-(const Matrix &m) const
	{
		if(row == m.row && col == m.col)
		{
			Matrix temp;
			temp.row = m.row;
			temp.col = m.col;
			temp.array = new double*[temp.row];
			for (int i = 0; i < temp.row; i++)
			{
				temp.array[i] = new double[temp.col];
				for (int j = 0; j < temp.col; j++)
				{
					temp.array[i][j] = array[i][j] - m.array[i][j];
				}
			}
			return temp;
		}
		else
		{
			throw;
		}
	}
	Matrix& operator=(const Matrix &m)
	{
		if(this != &m)
		{
			for (int i = 0; i < row; i++)
			{
				delete[] array[i];
			}
			delete[] array;
			row = m.row;
			col = m.col;
			array = new double*[m.row];
			for (int i = 0; i < m.row; i++)
			{
				array[i] = new double[m.col];
				for (int j = 0; j < m.col; j++)
				{
					array[i][j] = m.array[i][j];
				}
			}
		}
		return  *this;
	}
	void display() const
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << array[i][j] << "  ";
			}
			cout << endl;
		}
	}
};
int main()
{
	Matrix m1(2, 2, 9);
	Matrix m2(2, 2, 8);
	m2.display();
	Matrix m3;
	m3 = m1 + m2;
	m3.display();
	m3 = m1 - m2;
	m3.display();
	system("pause");
}