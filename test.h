/*
 * Test file for Matrix:
 * This file constains the tests for Matrix
 * Written By Dumitru Chiriac
 * github: https://github.com/dit555/Matrix  
 */

#include <iostream>
#include <string>

#include "Matrix.h"

using std::cout;
using std::endl;
using std::string;

int total_tests = 0; //keeps track of total tests
int success = 0;
//test that you can declare a Matrix Pointer

//count successes and failures
void f(){
	cout << "\033[1;31mFailure\033[0m" << endl;
}

void s(){
	success++;
	cout << "\033[1;32mSuccess!\033[0m" << endl;
}

void t(string test, string desc){
	total_tests++;
	cout << "\033[1;34m" << test << "\033[0m"  << " " << desc << "... ";

}	
//print error message
void e(string msg){
	cout << "\033[1;33m" << msg << endl << " --------  " << "\033[0m" << endl;
}	
//start tests
void test_declare(){
	//test wheter Matrix can be declared empty
	Matrix* a = new Matrix;
	t("test_declare", "pointer exists");
	if(a == nullptr){
		f();
		e("a is nullptr\n");
	}
	else s();
}

void test_rowcol(){
	//test declaration of a matrix with n rows and m cols
	Matrix* a = new Matrix(2,3);
	t("test_rowcol","matrix dimensions");
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else {f(); e("rows or cols do not match");}
	
}

void test_typedec(){
	//test declration of a matrix with n rows, m cols, and a type
	Matrix* a = new Matrix(2,3, INT);
	Matrix* b = new Matrix(2,3, FLOAT);
	
	
	t("test_typedec", "rows & cols of INT matrix");
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else {f(); e("rows or cols did not match");}

	
	t("test_typedec", "rows & cols of FLOAT matrix");
	if (b->rows() == 2 && b->cols() == 3){
		s();
	}
	else {f(); e("rows or cols did not match");}

	
	t("test_typedec", "type INT");
	if (a->getType() == INT){
		s();
	}
	else {f(); e("matrix is not of type INT");}

	t("test_typedec", "type FLOAT");
	if (b->getType() == FLOAT){
		s();
	}
	else {f(); e("matrix is not of type FLOAT");}
}

void test_valuedec(){
	//test declaration of matrix with int i and float f
	int test_i = 7;
	float test_f = 4.5;
	Matrix* a = new Matrix(5, 5, test_i);
	Matrix* b = new Matrix(5, 5, test_f);

	t("test_valuedec", "INT values");
	for(int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			cout << a->get(rows, cols) << endl;
			if (a->get(rows, cols) != test_i){
				f();
				e("one of the INT values does not match");
				cout << "matrix at " << rows << "," << cols << "!= " << test_i << endl;
				break;
			}
		}
	}	
	if (a->rows() != 0 && a->cols() != 0) s(); 
	else {f(); e("rows or cols = 0");}

	t("test_valuedec", "FLOAT values");
	for(int rows = 0; rows < b->rows(); rows++){
		for (int cols = 0; cols < b->cols(); cols++){
			if (b->getf(rows, cols) != test_f){
				f();
				e("one of the FLOAT values does not match");
				cout << "matrix at " << rows << "," << cols << "!= " << test_f << endl;
				break;
			}
		}
	}
	if (b->rows() != 0 && b->cols() != 0) s(); 
	else {f(); e("rows or cols = 0");}
}

void test_arrange(){
	//test the arrage type code
	Matrix* a = new Matrix(100,1, ARRANGE);
	t("test_arrange", "type INT");
	if (a->getType() == INT)
		s();
	else {f(); e("matrix is not of type INT");}

	t("test_arrange", "correct values");
	int i = 0; //iterates every index, follows the expected behavior of arrange
	int bad = 0; //flag for bad values
	for (int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			if (i != a->get(rows, cols)){
				bad = 1;
				f();
				e("one of the values did not match");
				cout << "expected: " << "matrix at " << rows << "," << cols << "==" << i << 
					", matrix at " << rows << "," << cols << "=" << a->get(rows,cols) << endl;
				break;
			}
			i++;
		}
	}
	if(a->rows() != 0 && a->cols() != 0) s();
	else {f(); e("either row or col is 0");}

}

void test_randdec(){
	//test the random declaration
	float rand1 = 5;
	float rand2 = 1;
	float mean1 = 5;
	float mean2 = 0;
	//using lrge matrixes for rand test to increase chance of finding bad values
	Matrix* a = new Matrix(100, 10, RAND, mean1, rand1);
	Matrix* b = new Matrix(50, 70, RAND, mean2, rand2);

	t("test_randec", "type float");
	if (a->getType() == FLOAT && b->getType() == FLOAT) {
		s();
	}
	else {f(); e("type is not float");}


	t("test_randec", "values in bounds (1)");
	for(int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			if (a->getf(rows, cols) < mean1 - rand1 || a->getf(rows,cols) > mean1 + rand1){
				f();
				e("one of the random values is out of bounds");
				cout << "Matrix at " << rows << "," << cols << ", result found: "; 
				cout << mean1 - rand1 << " <= " << a->getf(rows,cols) << " <= ";
				cout << mean1 + rand1 << endl;
				break;
			}
		}
	}
	if (a->rows() != 0 && a->cols() != 0) s();
	else {f(); e("rows or cols = 0");}

	t("test_randec", "values in bounds (2)");
	for(int rows = 0; rows < b->rows(); rows++){
		for (int cols = 0; cols < b->cols(); cols++){
			if (b->getf(rows, cols) < mean1 - rand1 || b->getf(rows,cols) > mean1 + rand1){
				f();
				e("one of the random values is out of bounds");
				cout << "Matrix at " << rows << "," << cols << ", result found: ";
				cout << mean2 - rand2 << " <= " << b->getf(rows,cols);
			       	cout << " <= " << mean2 + rand2 << endl;
				break;
			}
		}
	}
	if (b->rows() != 0 && b->cols() != 0) s();
	else {f(); e("rows or cols = 0");}
	
}

void test_settype(){
	//test converting matrix from INT to Float and vice versa
	int test_i = 5;
	float test_f = 6;
	Matrix* a = new Matrix(2,3,test_i);
	Matrix* b = new Matrix(2,3,test_f);

	t("test_settype", "INT to FLOAT");
}

//test controller
void tests(){
	cout << "beginning tests" << endl;
	cout << "--------------------------------------------" << endl;
	
	test_declare();
	test_rowcol();
	test_typedec();
	test_valuedec();
	test_arrange();
	test_randdec();
	test_settype();

	cout << endl << "--------------------------------------------" << endl;
	cout <<"\033[1;34m" <<  success << "\033[0m" << " out of " << "\033[1;34m" << total_tests << "\033[0m"  << " tests succeded" << endl << endl;
}