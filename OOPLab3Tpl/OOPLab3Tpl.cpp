#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
#include <clocale>
#endif
#include "Lab3Example.h"
using namespace std;


class Matrix {
public:
    double** matrix; // вказівник на вказівник на double
    int rows; // кількість рядків
    int cols; // кількість стовпців
    int error; // стан помилки
    static int count; // кількість об'єктів

    // конструктор без параметрів
    Matrix() {
        rows = 2;
        cols = 2;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new double[cols]{0.0}; // ініціалізуємо нулями
        error = 0;
        count++;
    }

    // конструктор з одним параметром
    Matrix(int n) {
        rows = n;
        cols = n;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new double[cols]{0.0}; // ініціалізуємо нулями
        error = 0;
        count++;
    }

    // конструктор із трьома параметрами
    Matrix(int n, int m, double value = 0.0) {
        rows = n;
        cols = m;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new double[cols]{value}; // ініціалізуємо значенням value
        error = 0;
        count++;
    }

    // конструктор копій
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
            for (int j = 0; j < cols; j++)
                matrix[i][j] = other.matrix[i][j]; // копіюємо елементи
        }
        error = other.error;
        count++;
    }

    // операція присвоєння
    Matrix& operator=(const Matrix& other) {
        if (this == &other) // перевірка на самоприсвоєння
            return *this;

        // видалення поточної матриці
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        // копіювання елементів з іншої матриці
        rows = other.rows;
        cols = other.cols;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
            for (int j = 0; j < cols; j++)
                matrix[i][j] = other.matrix[i][j];
        }
        error = other.error;

        return *this;
    }

    // деструктор
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
        count--;
    }

    // функція, яка присвоює елементу масиву деяке значення
    void set(int i, int j, double value = 0.0) {
        if (i >= rows || j >= cols) {
            error = 1;
            return;
        }
        matrix[i][j] = value;
    }

    // функція яка одержує деякий елемент матриці за індексами i та j
    double get(int i, int j) const {
        if (i >= rows || j >= cols) {
            
            return 0.0; // якщо помилка, поверне 0.0
        }
        return matrix[i][j];
    }

    // функція друку
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    // функція додавання двох матриць
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            return Matrix(); // якщо розміри матриць різні, повертаємо порожню матрицю зі станом помилки
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        return result;
    }

    // функція віднімання двох матриць
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            return Matrix(); // якщо розміри матриць різні, повертаємо порожню матрицю зі станом помилки
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        return result;
    }

    // функція множення двох матриць
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            return Matrix(); // якщо кількість стовпців першої матриці не дорівнює кількості рядків другої, повертаємо порожню матрицю зі станом помилки
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
					result.matrix[i][j] += matrix[i][k] * other.matrix[k][j]; 
					return result; 
					}
	}
	// функція отримання кількості створених об'єктів
	static int getCount() {
		return count;
	}

	// функція отримання стану помилки
	int getError() const {
		return error;
	}
};
int Matrix::count = 0;
void testMatrix() {
    
    Matrix m1; // test default constructor
    cout << "Matrix 1:" << endl;
    m1.print();

    Matrix m2(3); // test constructor with one parameter
    cout << "Matrix 2:" << endl;
    m2.print();

    Matrix m3(2, 3, 1.5); // test constructor with three parameters
    cout << "Matrix 3:" << endl;
    m3.print();

    m1.set(0, 0, 2.5); // test set function
    m1.set(1, 1, 3.5);
    cout << "Matrix 1 after set function:" << endl;
    m1.print();

    double value = m3.get(1, 2); // test get function
    cout << "Value at (1, 2) in Matrix 3: " << value << endl;

    Matrix m4 = m2; // test copy constructor
    cout << "Matrix 4 (copy of Matrix 2):" << endl;
    m4.print();

    Matrix m5;
    m5 = m3; // test assignment operator
    cout << "Matrix 5 (assigned from Matrix 3):" << endl;
    m5.print();

    Matrix m6 = m1 + m5; // test + operator
    cout << "Matrix 6 (result of Matrix 1 + Matrix 5):" << endl;
    m6.print();

    Matrix m7 = m3 - m5; // test - operator
    cout << "Matrix 7 (result of Matrix 3 - Matrix 5):" << endl;
    m7.print();

    Matrix m8 = m2 * m3; // test * operator
    cout << "Matrix 8 (result of Matrix 2 * Matrix 3):" << endl;
    m8.print();

    int count = Matrix::getCount(); // test static function
    cout << "Number of Matrix objects created: " << count << endl;

    int error = m7.getError(); // test getError function
    cout << "Error state of Matrix 7: " << error << endl;

    // test invalid parameter for set and get functions
    m1.set(2, 0, 1.0);
    value = m3.get(1, 3);
    error = m3.getError();
    cout << "After setting (2, 0) in Matrix 1 and getting (1, 3) in Matrix 3:" << endl;
    cout << "Matrix 1:" << endl;
    m1.print();
    cout << "Matrix 3:" << endl;
    m3.print();
    cout << "Value at (1, 3) in Matrix 3: " << value << endl;
    cout << "Error state of Matrix 3: " << error << endl;
}

int main()
{
	cout << " Lab #3  !\n Additional Task: Press ENTER to start TEST: ";
    cin.get();
	cout << "Test started: \n";
    
	testMatrix();
	cout << "\nTest Completed. \n";
}

