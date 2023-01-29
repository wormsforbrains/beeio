#ifndef BEEIO_QUANTIZATIONTABLE_H
#define BEEIO_QUANTIZATIONTABLE_H

#include <vector>

namespace beeio {

  class QuantizationTable {
    explicit QuantizationTable(std::vector<double> dctCoefficients);
  };

} // beeio

#endif //BEEIO_QUANTIZATIONTABLE_H
