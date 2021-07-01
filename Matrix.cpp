/*
 * cpp file for Matrix:
 * This file contains the implemented functions for Matrix
 * Written By Dumitru Chiriac
 * github: https://github.com/dit555/Matrix  
 */

#include <iostream>
#include <stdlib.h> // for random numbers
#include <time.h> // for random numbers
#include <assert.h>

#include "Matrix.h"

using std::cout;
using std::endl;

Matrix::Matrix (){
	t = EMPTY;
}

Matrix::Matrix (Matrix* m){
//TODO

}

Matrix::Matrix (const int rows, const int cols){
	if( rows <= 0 || cols <= 0){
		cout << "error at Matrix declaration: " << endl;
		cout << "either rows or cols is <= 0" << endl;
		cout << "rows: " << rows << endl;
		cout << "cols: " << cols << endl;
		assert(0);
	}
	
	aI = new int*[rows];
	for(int i = 0; i < rows; i++)
		aI[i] = new int[cols];
	r = rows;
	c = cols;
}

Matrix::Matrix (const int rows, const int cols, type typ){
	if( rows <= 0 || cols <= 0){
		cout << "error at Matrix declaration: " << endl;
		cout << "either rows or cols is <= 0" << endl;
		cout << "rows: " << rows << endl;
		cout << "cols: " << cols << endl;
		assert(0);
	}
	if(typ == INT){
		aI = new int*[rows];
		for(int i = 0; i < rows; i++)
			aI[i] = new int[cols];
		t = INT;
	}
	else if (typ == FLOAT){
		aF = new float*[rows];
		for(int i = 0; i < rows; i++)
			aF[i] = new float[cols];
		t = FLOAT;
	}
	else if (typ == ARRANGE){
		t = INT;
		aI = new int*[rows];
		int a = 1;
		for(int i = 0; i < rows; i++){
			aI[i] = new int[cols];
		}

		for(int row = 0; row < rows; row++){
			for (int col = 0; col < cols; col++){
				aI[row][col] = a;
				a++;
			}
		}
	}
	else {
		cout << "Type inputed is invalid" << endl;
		assert(0);
	}
	r = rows;
	c = cols;
}

Matrix::Matrix (const int rows, const int cols, int i){
	if( rows <= 0 || cols <= 0){
		cout << "error at Matrix declaration: " << endl;
		cout << "either rows or cols is <= 0" << endl;
		cout << "rows: " << rows << endl;
		cout << "cols: " << cols << endl;
		assert(0);
	}

	aI = new int*[rows];
	for(int l = 0; l < rows; l++)
		aI[l] = new int[cols];
	r = rows;
	c = cols;
	t = INT;
	for (int l = 0; l < r; l++){
		for (int j = 0; j < c;j++){
			aI[l][j] = i;
		}
	}

}

Matrix::Matrix (const int rows, const int cols, float f){
	if( rows <= 0 || cols <= 0){
		cout << "error at Matrix declaration: " << endl;
		cout << "either rows or cols is <= 0" << endl;
		cout << "rows: " << rows << endl;
		cout << "cols: " << cols << endl;
		assert(0);
	}
	aF = new float*[rows];
	for(int i = 0; i < rows; i++)
		aF[i] = new float[cols];
	r = rows;
	c = cols;
	t = FLOAT;
	for (int l = 0; l < r; l++){
		for (int j = 0; j < c;j++){
			aF[l][j] = f;
		}
	}



}

Matrix::Matrix (const int rows, const int cols, type typ, float mean, float std){
	if( rows <= 0 || cols <= 0){
		cout << "error at Matrix declaration: " << endl;
		cout << "either rows or cols is <= 0" << endl;
		cout << "rows: " << rows << endl;
		cout << "cols: " << cols << endl;
		assert(0);
	}
	aF = new float*[rows];
	for(int i = 0; i < rows; i++)
		aF[i] = new float[cols];
	r = rows;
	c = cols;
	t = FLOAT;
	srand(time(NULL));
	for (int l = 0; l < r; l++){
		for (int j = 0; j < c;j++){
			//generate a number
			float temp = (float)rand() / RAND_MAX; //generates numbers between 0.0 and 1.0
			//decide if below or above mean
			float m = mean;
			int neg = rand() % 2 ;
			if (neg == 0){
				m -= temp * std;
			}
			else
				m += temp * std;
		
			aF[l][j] = m;
		}
	}



}

Matrix::Matrix (Matrix* a, Matrix* b){
//TODO

}

Matrix::Matrix (Matrix* a, int b){
//TODO

}

Matrix::Matrix (Matrix* a, float b){


}

int Matrix::rows(){
	return r;
}

int Matrix::cols(){
	return c;
}

type Matrix::getType(){
	return t;
}

void Matrix::print(){
//TODO

}

void Matrix::setType(type typ){
	if(typ == t){
		; //do nothing
	}
	else if (typ == INT && t == FLOAT){
		aI = new int*[r];
		t = typ;
		for (int i = 0; i < r; i++){
			aI[i] = new int[c];
		}
		for (int row = 0; row < r; row++){
			for( int col = 0; col < c; col++){
				aI[row][col] = (int)aF[row][col];
			}
		}
		delete aF;
	}
	else if (typ == FLOAT && t == INT){
		aF = new float*[r];
		t = typ;
		for (int i = 0; i < r; i++){
			aF[i] = new float[c];
		}
		for (int row = 0; row < r; row++){
			for( int col = 0; col < c; col++){
				aF[row][col] = (float)aI[row][col];
			}
		}
		delete aI;

	}
	else{
		cout << "invalid type entered" << endl;
		assert(0);
	}

}

void Matrix::fill(int i){
	if(t == FLOAT){
		this->setType(INT);
	}
	for (int row = 0; row < r; row++){
		for (int col = 0; col < c;col++){
			aI[row][col] = i;
		}
	}

}

void Matrix::fillf(float f){
	if(t == INT){
		this->setType(FLOAT);
	}
	for (int row = 0; row < r; row++){
		for (int col = 0; col < c;col++){
			aF[row][col] = f;
		}
	}

}

int Matrix::get(int row, int col){
	if (t == INT)
		return aI[row][col];
	else if (t == FLOAT)
		return (int)aF[row][col];
}

float Matrix::getf(int row, int col){
	if (t == FLOAT)
		return aF[row][col];

	else if (t == INT)
		return (float)aI[row][col];
}

void Matrix::set(int row, int col, int val){
	if (t == FLOAT)
		this->setType(INT);
	aI[row][col] = val;	

}

void Matrix::setf(int row, int col, float val){
	if (t == INT)
		this->setType(FLOAT);
	aF[row][col] = val;

}

int** Matrix::array(){
//TODO
  	int** a;
	return a;
}

float** Matrix::arrayf(){
//TODO
	float** a;
	return a;
}

int Matrix::equals(Matrix* a){
//TODO
	return 0;
}

Matrix* Matrix::append(Matrix* a, type dir){
//TODO	
	Matrix* c = new Matrix;
	return c;
}

Matrix* subMat(const int row1, const int col1, const int row2, const int col2){
//TODO
	Matrix* c = new Matrix;
	return c;
}	

Matrix* tile(Matrix* a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

int Matrix::determinant(){
//TODO
	return 0;
}

float Matrix::determinantf(){
//TODO
	return 0;
}

Matrix* Matrix::pow(float p){
//TODO	
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::transpose(){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::inverse(){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::add(Matrix* a, Matrix* b){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::sub(Matrix* a, Matrix* b){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::matmul(Matrix* a, Matrix* b){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::operator= (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}
Matrix* Matrix::operator== (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::operator+ (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::operator- (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::operator* (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix* Matrix::operator/ (Matrix a){
//TODO
	Matrix* c = new Matrix;
	return c;
}

Matrix::~Matrix(){

}
