#include <iostream>
#include <vector>
#include <array>
#include <cmath>

int main( void ) {
    // dummy image
    double image[8][8] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
    };

    // matrix that contains the coeficients for each dct wave
    std::array<std::array<double, 8>, 8> coefs = {0};

    // define coefs ( calculate the dct frequencies in the meantime )
    for ( int l = 0; l < 8; l++ ) {
        for (int k = 0; k < 8; k++ ) {
            double coef = 0;
            for ( int i = 0; i < 8; i++ ) {
                for ( int j = 0; j < 8; j++ ) {
                    double verticalWave = (M_PI/8 * l * (i + 1/2)) * M_PI/180.f;
                    double horizontalWave = (M_PI/8 * k * (j + 1/2)) * M_PI/180.f;
                    coef += image[i][j] * cos(verticalWave) * cos(horizontalWave);
                }
            }

            // Normalize the coef

            // calculate for the vertical
            double verticalNorm = l;
            double horizontalNorm = k;
            if ( verticalNorm > 0 ) {
                verticalNorm  = sqrt(2/8);
            } else if ( verticalNorm == 0 ) {
                verticalNorm = sqrt(1/8);
            }

            // calculate for the horizontal
            if ( horizontalNorm > 0 ) {
                horizontalNorm  = sqrt(2/8);
            } else if ( verticalNorm == 0 ) {
                horizontalNorm = sqrt(1/8);
            }

            // define final coef value

            coefs[l][k] = coef * verticalNorm * horizontalNorm;
        }
    }

    return 0;
}