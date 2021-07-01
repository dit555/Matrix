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
	cout << "\033[1;33m" << msg  << endl << endl;
}	

void e2(){
	cout << "\033[0m" << endl;
}
//start tests
//Constructor tests:
void test_declare(){
	//test wheter Matrix can be declared empty
	Matrix* a = new Matrix;
	t("test_declare", "pointer exists");
	if(a == nullptr){
		f();
		e("a is nullptr\n");
		e2();
	}
	else s();

	delete a;
}

void test_rowcol(){
	//test declaration of a matrix with n rows and m cols
	Matrix* a = new Matrix(2,3);
	t("test_rowcol","matrix dimensions");
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else {f(); e("rows or cols do not match"); e2();}
	
	delete a;
}

void test_typedec(){
	//test declration of a matrix with n rows, m cols, and a type
	Matrix* a = new Matrix(2,3, INT);
	Matrix* b = new Matrix(2,3, FLOAT);
	
	
	t("test_typedec", "rows & cols of INT matrix");
	if (a->rows() == 2 && a->cols() == 3){
		s();
	}
	else {f(); e("rows or cols did not match"); e2();}

	
	t("test_typedec", "rows & cols of FLOAT matrix");
	if (b->rows() == 2 && b->cols() == 3){
		s();
	}
	else {f(); e("rows or cols did not match");}

	
	t("test_typedec", "type INT");
	if (a->getType() == INT){
		s();
	}
	else {f(); e("matrix is not of type INT"); e2();}

	t("test_typedec", "type FLOAT");
	if (b->getType() == FLOAT){
		s();
	}
	else {f(); e("matrix is not of type FLOAT"); e2();}

	delete a;
	delete b;
}

void test_valuedec(){
	//test declaration of matrix with int i and float f
	int test_i = 7;
	float test_f = 4.5;
	Matrix* a = new Matrix(5, 5, test_i);
	Matrix* b = new Matrix(5, 5, test_f);

	int bad = 0; //flag for bad test
	t("test_valuedec", "INT values");
	for(int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			if (a->get(rows, cols) != test_i){
				f();
				e("one of the INT values does not match");
				cout << "matrix at " << rows << "," << cols << "!= " << test_i << endl;
				e2();
				bad = 1;
				break;
			}
		}
	}	
	if (a->rows() != 0 && a->cols() != 0 && bad != 1) s(); 
	else if (bad != 1) {f(); e("rows or cols = 0"); e2();}

	bad = 0;
	t("test_valuedec", "FLOAT values");
	for(int rows = 0; rows < b->rows(); rows++){
		for (int cols = 0; cols < b->cols(); cols++){
			if (b->getf(rows, cols) != test_f){
				f();
				e("one of the FLOAT values does not match");
				cout << "matrix at " << rows << "," << cols << "!= " << test_f << endl;
				e2();
				bad = 1;
				break;
			}
		}
	}
	if (b->rows() != 0 && b->cols() != 0 && bad != 1) s(); 
	else if (bad != 1) {f(); e("rows or cols = 0"); e2();}

	delete a;
	delete b;
}

void test_arrange(){
	//test the arrage type code
	Matrix* a = new Matrix(100,1, ARRANGE);
	t("test_arrange", "type INT");
	if (a->getType() == INT)
		s();
	else {f(); e("matrix is not of type INT"); e2();}


	t("test_arrange", "correct values");
	int i = 1; //iterates every index, follows the expected behavior of arrange
	int bad = 0; //flag for bad values
	for (int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			if (i != a->get(rows, cols)){
				bad = 1;
				f();
				e("one of the values did not match");
				cout << "expected: " << "matrix at " << rows;
			       	cout << "," << cols << " == " << i << 
					", matrix at " << rows << "," << cols << "=" << a->get(rows,cols) << endl;
				e2();
				break;
			}
			i++;
		}
		if (bad) break;
	}
	if(a->rows() != 0 && a->cols() != 0 && !bad) s();
	else if (bad != 1) {f(); e("either row or col is 0"); e2();}

	delete a;
}

void test_randdec(){
	//test the random declaration
	float std1 = 5;
	float std2 = 1;
	float mean1 = 5;
	float mean2 = 0;
	//using lrge matrixes for rand test to increase chance of finding bad values
	Matrix* a = new Matrix(100, 10, RAND, mean1, std1);
	Matrix* b = new Matrix(50, 70, RAND, mean2, std2);

	t("test_randec", "type float");
	if (a->getType() == FLOAT && b->getType() == FLOAT) {
		s();
	}
	else {f(); e("type is not float");}

	int bad = 0; //flag for bad test
	t("test_randec", "values in bounds (1)");
	for(int rows = 0; rows < a->rows(); rows++){
		for (int cols = 0; cols < a->cols(); cols++){
			if (a->getf(rows, cols) < mean1 - std1 || a->getf(rows,cols) > mean1 + std1){
				f();
				e("one of the random values is out of bounds");
				cout << "Matrix at " << rows << "," << cols << ", result found: "; 
				cout << mean1 - std1 << " <= " << a->getf(rows,cols) << " <= ";
				cout << mean1 + std1 << endl;
				bad = 1;
				e2();
				break;
			}
		}
		if (bad) break;
	}
	if (a->rows() != 0 && a->cols() != 0 && !bad) s();
	else if (bad != 1) {f(); e("rows or cols = 0"); e2();}

	bad = 0;
	t("test_randec", "values in bounds (2)");
	for(int rows = 0; rows < b->rows(); rows++){
		for (int cols = 0; cols < b->cols(); cols++){
			if (b->getf(rows, cols) < mean2 - std2 || b->getf(rows,cols) > mean2 + std2){
				f();
				e("one of the random values is out of bounds");
				cout << "Matrix at " << rows << "," << cols << ", result found: ";
				cout << mean2 - std2 << " <= " << b->getf(rows,cols);
			       	cout << " <= " << mean2 + std2 << endl;
				bad = 1;
				e2();
				break;
			}
		}
		if (bad) break;
	}
	if (b->rows() != 0 && b->cols() != 0 && !bad) s();
	else if (bad != 1) {f(); e("rows or cols = 0"); e2();}
	
	delete a;
	delete b;
}
//end constructor tests
//##############################################################################
//start basic operations tests:
//skip tests for rows(), cols(), and getType() as they are used in other tests

void test_settype(){
	//test converting matrix from INT to Float and vice versa
	int test_i = 5;
	float test_f = 6;
	Matrix* a = new Matrix(2,3,test_i);
	Matrix* b = new Matrix(2,3,test_f);


	t("test_settype", "INT to FLOAT");
	a->setType(FLOAT);
	if (a->getType() == FLOAT){
		s();
	}
	else{
		f();
		e("type did not set to FlOAT");
	}

	t("set_settype", "FLOAT to INT");
	b->setType(INT);
	if (b->getType() == INT){
		s();
	}
	else {
		f();
		e("type did not set to INT");
	}
	delete a;
	delete b;
}

void test_fill(){
	int fill_i = 4;
	float fill_f = 5.7;
	Matrix* c = new Matrix(1,3,INT);
	Matrix* d = new Matrix(5,6, FLOAT);
	
	int bad = 0; //flag for bad test
	t("test_fill()", "fill with INT on INT matrix");
	c->fill(fill_i);
	for (int i = 0; i < c->rows(); i++){
		for (int j = 0; j < c->cols(); j++){
			if(c->get(i,j) != fill_i){
				f();
				e("did not get the correct value for INT");
				cout << "expected: " << fill_i << " but got: " << c->get(i,j) << " at " << i << "," << j << endl;
				bad = 1;
				break;
			}
		}		
		if (bad) break;
	}
	if (c->rows() != 0 && c->cols() != 0 && bad != 1) {s();} 
	else if (bad != 1) {f(); e("either rows or cols is 0");}
	bad = 0;
	
	t("test_fill()", "fill with FLOAT on FLOAT matrix");
	d->fillf(fill_f);
	for (int i = 0; i < d->rows(); i++){
		for (int j = 0; j < d->cols(); j++){
			if(d->get(i,j) != fill_i){
				f();
				e("did not get the correct value for FLOAT");
				cout << "expected: " << fill_i << " but got: " << d->get(i,j) << " at " << i << "," << j << endl;
				bad = 1;
				break;
			}
		}		
		if (bad) break;
	}
	if (c->rows() != 0 && c->cols() != 0 && bad != 1) {s();} 
	else if (bad != 1) {f(); e("either rows or cols is 0");}
	delete c;
	delete d;
	
}

void test_set(){ //skip get() becuse its used in other tests
	Matrix* a = new Matrix(4,5, (int)3);
	Matrix* b = new Matrix(3,4, (float)6);

	a->set(3,4,6);
	b->setf(1,2, 4.5);

	t("test_set", "set INT to other INT");
	if (a->get(3,4) == 6){
		s();
	}
	else{
		f();
		e("did not get expected value");
		cout << "got: " << a->get(3,4) << " ,but expected: 6" << endl;
	}

	t("test_set", "set FLOAT to other FLOAT");
	if (b->getf(2,3) == 4.5){
		s();
	}
	else{
		f();
		e("did not get expected value");
		cout << "got: " << b->get(2,3) << " ,but expected: 4.5" << endl;
	}

	delete a;
	delete b;
}

void test_equals(){
	Matrix* a = new Matrix(3,4, ARRANGE);
	Matrix* b = new Matrix(3,4, ARRANGE);
	Matrix* c = new Matrix(4,5, ARRANGE);
	
	t("test_equals","two equal matrixes");
	if( a->equals(b)){
		s();
	}
	else {f();e("matrixes did not equal when they should have");}

	t("test_equals","two unequal mtrixes");
	if (!a->equals(c)){
		s();
	}
	else {f(); e("matrixes equalled each other when they shouldn't have");}
	
	delete a;
	delete b;
	delete c;


}
//end basic operations tests
//######################################################################
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
	test_fill();
	test_set();

	cout << endl << "--------------------------------------------" << endl;
	cout <<"\033[1;34m" <<  success << "\033[0m" << " out of " << "\033[1;34m" << total_tests << "\033[0m"  << " tests succeded" << endl << endl;
}
