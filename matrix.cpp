#include <stdio.h>
#include <iostream>
#include <fstream>
#include "matrix.h"

void matrix::createMatrix()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>rows;
	inFile>>cols;
	grid = new double*[rows];
	grid_temp = new double*[rows];
	for(int i = 0; i<rows; i++){
		grid[i] = new double[cols];
		grid_temp[i] = new double[cols];
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			inFile>>grid[i][j];
		}
	}
	return;
}

void matrix::printMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
				std::cout<<grid[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}

void matrix::addMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			grid_temp[i][j] = grid[i][j]+grid[i][j];
		}
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
		}
	std::cout<<"\n";
	}
}

double matrix::getMax(){
	double max_element = 0;
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			max_element = max_element > grid[i][j] ? max_element : grid[i][j];
		}
	}
	return max_element;
}

bool matrix::findElement(int no){
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			if (no == grid[i][j]) {
				std::cout << "Element found at (" << i << ", " << j << ")\n";	//why isn't the file using namespace std? lol
				return true;
			}
		}
	}
	std::cout<<"Element not found\n";
	return false;
}

void matrix::changeElement(int r, int c, int no){
	if (r >= rows || c >= cols) {
		std::cout << "Invalid index outside of matrix\n";
		return;
	}
	grid[r][c] = no;
	return;
}
void matrix::multiplyMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			grid_temp[i][j] = grid[0][j] * grid[i][0] +
							  grid[1][j] * grid[i][1] +
							  grid[2][j] * grid[i][2] +
							  grid[3][j] * grid[i][3];
		}
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
		}
	std::cout<<"\n";
	}
	return;
}

void matrix::transposeMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
				std::cout<<grid[j][i]<<"\t";
		}
		std::cout<<"\n";
	}
	return;
}
matrix::~matrix(){
        for(int i = 0; i<rows; i++){
                delete[] grid[i];
                delete[] grid_temp[i];
        }
        delete[] grid;
        delete[] grid_temp;
}
