#include <iostream>
#include <cmath>
#include <float.h>

int main( void ) {
    // dummy image
    double image[8][8] = {
		{1,   19,  37,  55,  73,  91,  109, 127},
		{19,  37,  55,  73,  91,  109, 127, 145},
		{37,  55,  73,  91,  109, 127, 145, 163},
		{55,  73,  91,  109, 127, 145, 163, 181},
		{73,  91,  109, 127, 145, 163, 181, 199},
		{91,  109, 127, 145, 163, 181, 199, 217},
		{109, 127, 145, 163, 181, 199, 217, 235},
		{127, 145, 163, 181, 199, 217, 235, 253}
    };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			image[i][j] = j;
		}
	}

    // matrix that contains the coeficients for each dct wave
    double coefs[8][8] = {0};
	
	int i, j, x, y;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			float sum = 0;

			for (x = 0; x < 8; x++) {
				for (y = 0; y < 8; y++) {
					double verticalWave = ((2.f * y + 1.f) * j * M_PI)/(2.f * 8.f);
					double horizontalWave = ((2.f * x + 1.f) * i * M_PI)/(2.f * 8.f);
					
					sum += cos(verticalWave) * cos(horizontalWave) * image[x][y];
				}
			}

			double normalizationFactor;

			if (i == 0 && j == 0) {
				normalizationFactor = (double)1/sqrt(8.f) * (double)1/sqrt(8);
			} else if (i == 0 || j == 0) {
				normalizationFactor = (double)1/sqrt(8) * sqrt((double)1/4);
			} else {
				normalizationFactor = sqrt((double)2/8) * sqrt((double)2/8);
			}

			sum *= normalizationFactor;

			if (fabs(sum) < 1e-2) {
                sum = 0.0;
            }
			
			coefs[i][j] = sum;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << coefs[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
    return 0;
}
