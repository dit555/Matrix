#include "Matrix.h"

Matrix::Matrix (){
//TOD0

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

Matrix::Matrix (int rows, int cols, int f){
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
	return INT;
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

void Matrix::fill(float f){
//TODO

}

int Matrix::get(int row, int col){
//TODO
	return 0;
}

float Matrix::getf(int row, int col){
//TODO
	return 0.0;
}

void Matrix::set(int row, int col, int val){
//TODO

}

void Matrix::set(int row, int col, float val){
//TODO

}

int** Matrix::array(){
//TODO
  	int a[1][1];
	return a;
}

float** Matrix::array(){
//TODO
	float a[1][1];
	return a;
}

int Matrix::determinant(){
//TODO
	return 0;
}

float Matrix::determinantf(){
//TODO
	return 0;
}

int Matrix::equals(Matrix* a, Matrix* b){
//TODO
	return 0;
}

Matrix* Matrix::pow(float p){
//TODO	
	Matrix* a = new Matrix;
	return a;
}

Matrix* Matrix::transpose(){
//TODO
	Matrix* a = new Matrix;
	return a;
}


