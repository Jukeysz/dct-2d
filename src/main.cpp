#include <iostream>
#include <cmath>
#include <float.h>
#include "dct-2.hpp"
#include <time.h>

int main( void ) {
	int rows, columns {};
	std::cout <<"Usage:\nEnter every the amount of rows and columns (must be equal), respectively\nEnter each sample for the matrix" << std::endl;
	std::cout.flush();
	std::cin >> rows;
	std::cin >> columns;
	
	// allocate waves
	double *wvs = (double *)malloc(rows * columns * rows * columns * sizeof(double));
	if (wvs == NULL) {
		printf("Could not allocate waves\n");
		return 1;
	}
	waves(wvs, rows, columns);

    // dummy image
    double image[64] = {
		1,   19,  37,  55,  73,  91,  109, 127,
		19,  37,  55,  73,  91,  109, 127, 145,
		37,  55,  73,  91,  109, 127, 145, 163,
		55,  73,  91,  109, 127, 145, 163, 181,
		73,  91,  109, 127, 145, 163, 181, 199,
		91,  109, 127, 145, 163, 181, 199, 217,
		109, 127, 145, 163, 181, 199, 217, 235,
		127, 145, 163, 181, 199, 217, 235, 253
    };
	//double *image = (double *)malloc(columns * rows * sizeof(double));
	
	//for (int i = 0; i < columns; i++) {
	//	for (int j = 0; j < rows; j++) {
	//		int xOffset = i + 1;
	//		int yOffset = j + 1;
	//		double inpt = 0;
    //
	//		std::cout << "\nEnter sample offset\n" << xOffset << ","  << yOffset << std::endl;
	//		std::cout.flush();
	//		std::cin >> inpt;
    //
	//		image[i * columns + j] = inpt;
	//	}
	//}

	// test image input
	std::cout << "Image samples:" << std::endl;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << image[i * columns + j] << " ";
		}
		std::cout << std::endl;
	}

    // matrix that contains the coeficients for each dct wave
    double *coefs = (double *)malloc(rows * columns * sizeof(double));
	int i, j, x, y;
	double normalTwoEq = 1.f/sqrt(rows) * 1.f/sqrt(rows);
	double normalOneEq = 1.f/sqrt(rows) * sqrt(2.f/rows);
	double normalNoneEq = sqrt(2.f/rows) * sqrt(2.f/rows);

	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {
			float sum = 0;

			for (x = 0; x < columns; x++) {
				for (y = 0; y < rows; y++) {
					sum += wvs[(i * columns + j) * (rows * columns) + (x * columns + y)] *
						image[x * columns + y];
					//double basis = cos((2 * x + 1) * i * M_PI / (2 * columns)) *
					//             cos((2 * y + 1) * j * M_PI / (2 * rows));
					//sum += basis * image[x * columns + y];
				}
			}

			double normalizationFactor;

			if (i == 0 && j == 0) {
				normalizationFactor = normalTwoEq;
			} else if (i == 0 || j == 0) {
				normalizationFactor = normalOneEq;
			} else {
				normalizationFactor = normalNoneEq;
			}
			
			sum *= normalizationFactor;

			if (fabs(sum) < 1e-2) {
                sum = 0.0;
            }
			
			coefs[i * columns + j] = sum;
		}
	}
	
	std::cout << "Final coefs:" << std::endl;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << coefs[i * columns + j] << " ";
		}
		std::cout << std::endl;
	}
	
    return 0;
}
