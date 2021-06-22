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

int test_declare(){
	Matrix* a = new Matrix;
	cout << "testing declaration... ";
	assert(((void)"test_declare", a != nullptr));
	cout << "Success!" << endl;
}

void tests(){
	test_declare();
}
