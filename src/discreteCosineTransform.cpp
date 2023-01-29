#include "discreteCosineTransform.h"
#include "Image.h"

#include <cmath>
#include <vector>

namespace beeio {

  std::vector<double> DCT(const Image &image) {
    DataVector pixelValues = image.getData();
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<double> dctCoefficients(width * height);

    double C_x, C_y;
    for (int x = 0; x < width; x++) {
      C_x = (x == 0) ? 1.0 / sqrt(2.0) : 1.0;
      for (int y = 0; y < height; y++) {
        C_y = (y == 0) ? 1.0 / sqrt(2.0) : 1.0;
        double sum = 0.0;
        for (int i = 0; i < width; i++) {
          for (int j = 0; j < height; j++) {
            // FIXME: operator[] for DataVector and int
            double pixel = pixelValues[i + j * width];
            double val = pixel * cos((2 * i + 1) * x * M_PI / (2 * width)) * cos((2 * j + 1) * y * M_PI / (2 * height));
            sum += val;
          }
        }
        dctCoefficients[x + y * width] = (2.0 / sqrt(width * height)) * C_x * C_y * sum;
      }
    }
    return dctCoefficients;
  }

}
