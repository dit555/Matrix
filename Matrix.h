
#ifndef __MATRIX__
#define __MATRIX__

typedef unsigned int type;

//type codes
const type INT = 1; //type code for interger type
const type FLOAT = 2; //type code for float type

//other type codes
const type ARRANGE = 100; //number code for arrange, type of matrix is int
const type RAND = 101; //number code for random, type of matrix is float

class Matrix {
	public:
		//constructors
		Matrix() {}; //init empty matrix
		Matrix(Matrix* m); //copy matrix
		Matrix(int rows, int cols); //init Matrix of rows x cols dim
		Matrix(int rows, int cols, type t); //init Matrix of rows x cols dim of specified type
		Matrix(int rows, int cols, int i); //init Matrix with each value being i
	       	Matrix(int rows, int cols, float f); //init Matrix with each value being f
		Matrix(int rows, int cols, type t, float mean, float std); //init matrix with random values
		Matrix(Matrix* a, Matrix* b); //for overloading matrix/matrix matrix operations
		Matrix(Matrix* a, int b); // for overloading matrix/int operations
		Matrix(Matrix* a, float b); //for overloading matrix/float operations

		//basic operations
		int rows(); //returns number of rows in matrix
		int cols(); //returns number of columns in matrix
		type getType(); //returns type of matrix
		void print(); //prints matrix
		void setType(type t); //set type of Matrix
		void fill(int i); //fill all values of Matrix with i (int)
		void fill(float f); //fill all values of Matrix with f (float)
		int get(int row, int col); //return value as int
		float getf(int row, int col); //return value of float
		void set(int row, int col, int val); //set value in Matrix to val
		void set(int row, int col, float val); //set value in Matrix to val
		int** array(); //return Matrix as an int array
		float** arrayf(); //return Matrix as a float array
		
		//operations
		int determinant(); //get determinant of matrix as int
		float determinantf(); //get determinant of matrix as float
		int equals(Matrix* a, Matrix* b); //check if matrixes are the same
		Matrix* pow(float p); //each value to the power of p
		Matrix* transpose(); //return a new matrix that is the transpose of current matrix
	       	Matrix* inverse(); //returns inverse matrix
		Matrix* add(Matrix* a, Matrix* b); //add two matrixes together
		Matrix* sub(Matrix* a, Matrix* b); //subtract the values of the matrixes
		Matrix* matmul(Matrix* a, Matrix* b); //mulitiply matrixes

		//operator overloads
		Matrix operator= (Matrix); //assign operator overload
		Matrix operator== (Matrix); //equals operator overload
		Matrix operator+ (Matrix); //addition operator overload
		Matrix operator- (Matrix); //subtraction operator overload
		Matrix operator* (Matrix); //mult operator overload
		Matrix operator/ (Matrix); //division operator overload
		
		//destructor
		~Matrix(); //destructor



	private:
		int r; //number of rows
		int c; //number of columns
		int** aI; //array of the matrix as int
		float** aF; //array of matrix as float
};

#endif
