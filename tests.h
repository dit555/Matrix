/*
 * Test file for Matrix:
 * This file constains the tests for Matrix
 * Written By Dumitru Chiriac
 * github: https://github.com/dit555/Matrix  
 */

#include <iostream>
#include <assert.h>

#include "Matrix.h"

using std::cout;
using std::endl;

int total_tests = 0; //keeps track of total tests
int success = 0;
//test that you can declare a Matrix Pointer

//count successes and failures
void f(){
	total_tests++;
	cout << "\033[1;31mFailure\033[0m" << endl;
}

void s(){
	total_tests++;
	success++;
	cout << "\033[1;32mSuccess!\033[0m" << endl;
}

//start tests
void test_declare(){
	//test wheter Matrix can be declared empty
	Matrix* a = new Matrix;
	cout << "testing declaration... ";
	if(a == nullptr){
		f();
	}
	else s();
}

void test_rowcol(){
	//test declaration of a matrix with n rows and m cols
	Matrix* a = new Matrix(2,3);
	cout << "testing row col... ";
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else f();
	
}

void test_typedec(){
	//test declration of a matrix with n rows, m cols, and a type
	Matrix* a = new Matrix(2,3, INT);
	Matrix* b = new Matrix(2,3, FLOAT);
	
	
	cout << "testing row col int dec... ";
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else f();

	
	cout << "testing row col float dec... ";
	if (b->rows() == 2 && b->cols() == 3){
		s();
	}
	else f();

	
	cout << "testing row col type int... ";
	if (a->getType() == INT){
		s();
	}
	else f();

	cout << "testing row col type float... ";
	if (b->getType() == FLOAT){
		s();
	}
	else f();
}

void tests(){
	cout << "beginning tests" << endl;
	cout << "--------------------------------------------" << endl;
	
	test_declare();
	test_rowcol();
	test_typedec();
	
	cout << "--------------------------------------------" << endl;
	cout << success << " out of " << total_tests << " tests succeded" << endl;
}
