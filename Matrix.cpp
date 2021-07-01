/*
 * cpp file for Matrix:
 * This file contains the implemented functions for Matrix
 * Written By Dumitru Chiriac
 * github: https://github.com/dit555/Matrix  
 */

#include <iostream>
#include <stdlib.h> // for random numbers
#include <time.h> // for random numbers


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
	aI = new int*[rows];
	for(int i = 0; i < rows; i++)
		aI[i] = new int[cols];
	r = rows;
	c = cols;
}

Matrix::Matrix (const int rows, const int cols, type typ){
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

	r = rows;
	c = cols;
}

Matrix::Matrix (const int rows, const int cols, int i){
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

void Matrix::setType(type t){
//TODO

}

void Matrix::fill(int i){
//TODO

}

void Matrix::fillf(float f){
//TODO

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
	

}

void Matrix::setf(int row, int col, float val){
//TODO

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
