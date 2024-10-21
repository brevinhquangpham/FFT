#ifndef FFT_H
#define FFT_H

#include <complex>
#include <vector>

class FFT {
   public:
    static void fft(std::vector<std::complex<double> >& data);
    static void ifft(std::vector<std::complex<double> >& data);
};

#endif
