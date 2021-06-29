/*
 * cpp file for Matrix:
 * This file contains the implemented functions for Matrix
 * Written By Dumitru Chiriac
 * github: https://github.com/dit555/Matrix  
 */

#include "Matrix.h"

Matrix::Matrix (){

}

Matrix::Matrix (Matrix* m){
//TODO

}

Matrix::Matrix (int rows, int cols){
//TODO

}

Matrix::Matrix (int rows, int cols, type t){
//TODO

}

Matrix::Matrix (int rows, int cols, int i){
//TODO

}

Matrix::Matrix (int rows, int cols, float f){
//TODO

}

Matrix::Matrix (int rows, int cols, type t, float mean, float std){
//TODO

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
//TODO
	return 0;
}

int Matrix::cols(){
//TODO
	return 0;
}

type Matrix::getType(){
//TODO
	return 0;
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
//TODO
	return 0;
}

float Matrix::getf(int row, int col){
//TODO
	return (float)0.0;
}

void Matrix::set(int row, int col, int val){
//TODO

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

Matrix* subMat(int row1, int col1, int row2, int col2){
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
