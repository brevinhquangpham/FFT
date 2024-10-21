#include "FFT.h"

#include <cmath>
#include <complex>
#include <vector>

void fftHelper(std::vector<std::complex<double> >& data, bool inverse) {
    const size_t n = data.size();
    if (n <= 1) return;

    size_t log2n = std::log2(n);
    std::vector<std::complex<double> > temp(n);

    for (size_t i = 0; i < n; ++i) {
        size_t rev = 0;
        for (size_t j = 0; j < log2n; j++) {
            rev = (rev << 1) | ((i >> j) & 1);
        }
        temp[rev] = data[i];
    }
    data = temp;

    // FFT Calculation
    for (size_t size = 2; size <= n; size *= 2) {
        double angle = 2 * M_PI / size * (inverse ? -1 : 1);
        std::complex<double> wlen(cos(angle), sin(angle));
        for (size_t i = 0; i < n; i += size) {
            std::complex<double> w(1);
            for (size_t j = 0; j < size / 2; ++j) {
                std::complex<double> u = data[i + j];
                std::complex<double> v = data[i + j + size / 2] * w;
                // Symmetry for input
                data[i + j] = u + v;
                data[i + j + size / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (inverse) {
        for (auto& x : data) x /= n;
    }
};
/**
 * @brief Calculates the fft in-place of a vector of complex numbers.
 *
 * @param data
 *
 */
void FFT::fft(std::vector<std::complex<double> >& data) {
    fftHelper(data, false);
    return;
}

void FFT::ifft(std::vector<std::complex<double> >& data) {
    fftHelper(data, true);
    return;
}
