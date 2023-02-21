#ifndef BEEIO_JPEG_HEADER_H
#define BEEIO_JPEG_HEADER_H

#include <Marker.h>
#include <QuantizationTable.h>

#include <cstdint>
#include <fstream>
#include "Image.h"

namespace beeio {

  class SOI : public Marker {
    public:
      SOI();
  };

  class EOI : public Marker {
    public:
      EOI();
  };

  class APP0 : public Marker {
    public:
      APP0();

    private:
      std::vector<uint8_t> jfif;
      std::vector<uint8_t> version;
      uint8_t densityUnits;
      std::vector<uint8_t> xDensity;
      std::vector<uint8_t> yDensity;
      uint8_t xThumbnail;
      uint8_t yThumbnail;
  };

  class DQT : public Marker {
    public:
      DQT(const QuantizationTable &quantizationTable);
    private:
      QuantizationTable quantizationTable;
  };

}

#endif //BEEIO_JPEG_HEADER_H
