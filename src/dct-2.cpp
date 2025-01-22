#include "dct-2.hpp"
#include <math.h>

void dct2(double **image, double **waves, int rows, int columns) {
	
}

void waves(double *waves, int rows, int columns) {
	int i, j, x, y;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			double sum = 0.0;
			for (x = 0; x < rows; x++) {
				for (y = 0; y < columns; y++) {
					double verticalWave = ((2.0 * y + 1.0) * j * M_PI)/(2.0 * 8.0);
					double horizontalWave = ((2.0 * x + 1.0) * i * M_PI)/(2.0 * 8.0);
					waves[(i * columns + j) * (rows * columns) + (x * columns + y)] = 
						cos(verticalWave) * cos(horizontalWave);
				}
			}
		}
	}
}
