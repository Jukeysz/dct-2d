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
    for ( double l = 0; l < 8; l++ ) {
        for ( double k = 0; k < 8; k++ ) {
            double coef = 0;
            for ( int i = 0; i < 8; i++ ) {
                for ( int j = 0; j < 8; j++ ) {
                    double verticalWave = M_PI/8.0 * ( 2*l + 1 ) * i;
                    double horizontalWave = M_PI/8.0 * ( 2*k + 1 ) * j;
                    coef += image[i][j] * cos( verticalWave ) * cos( horizontalWave );
                }
            }

            // Normalize the coef
            // calculate for the vertical
            if ( l == 0 && k == 0 ) {
                coef *= 1.0/sqrt( 8.0 );
            } else {
                coef *= 2.0/sqrt( 8.0 );
            }

            // define final coef value
            coefs[l][k] = coef;
        }
    }

    for ( int i = 0; i < 8; i++ ) {
        for ( int j = 0; j < 8; j++ ) {
            std::cout << coefs[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}