#ifndef BEEIO_QUANTIZATIONTABLE_H
#define BEEIO_QUANTIZATIONTABLE_H

#include <vector>
#include <cstdint>

namespace beeio {

  class QuantizationTable;

  class QuantizationTable {
    public:
      std::vector<uint8_t> quantizedCoefficients;

      explicit QuantizationTable(std::vector<double>& dctCoefficients);

      size_t size() const;
      std::vector<uint8_t>::const_iterator begin() const;
      std::vector<uint8_t>::const_iterator end() const;
  };

} // beeio

#endif //BEEIO_QUANTIZATIONTABLE_H
