#include "QuantizationTable.h"
#include "jpeg.h"

#include <cmath>

namespace beeio {

  QuantizationTable::QuantizationTable(std::vector<double> &dctCoefficients) {
    this->quantizedCoefficients = std::vector<uint8_t>(64);

    // If no DCT coefficients were provided, use the standard JPEG quantization table
    if (dctCoefficients.empty()) {
      dctCoefficients = std::vector<double>(64);
      for (uint8_t i: JPEG::jpegQuantizationTable) {
        dctCoefficients.push_back(i);
      }
    }

    for (int i = 0; i < 64; ++i) {
      this->quantizedCoefficients[i] = (uint8_t)round(dctCoefficients[i] / JPEG::jpegQuantizationTable[i]);
    }
  }

  size_t QuantizationTable::size() const {
    return quantizedCoefficients.size();
  }

  std::vector<uint8_t>::const_iterator QuantizationTable::begin() const {
    return quantizedCoefficients.begin();
  }

  std::vector<uint8_t>::const_iterator QuantizationTable::end() const {
    return quantizedCoefficients.end();
  }

} // beeio