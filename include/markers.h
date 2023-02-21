#ifndef BEEIO_JPEG_HEADER_H
#define BEEIO_JPEG_HEADER_H

#include <Marker.h>
#include <QuantizationTable.h>

#include <cstdint>
#include <fstream>
#include "Image.h"

namespace beeio {

  class SOI;

  class EOI;

  class APP0;

  class DQT;

  std::vector<uint8_t> &operator <<(std::vector<uint8_t> &v, const uint8_t &value);
  std::vector<uint8_t> &operator <<(std::vector<uint8_t> &v1, const std::vector<uint8_t> &v2);

  class SOI : public Marker {
    public:
      SOI();

    private:
      void init();
  };

  class EOI : public Marker {
    public:
      EOI();

    private:
      void init();
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

      void init();
      void pack() override;
  };

  class DQT : public Marker {
    public:
      explicit DQT(uint8_t precision, uint8_t id);

    private:
      uint8_t precisionAndId {};
      std::vector<uint8_t> quantizationTable;

      void init();
      void pack() override;
  };

  class SOF0 : public Marker {
    public:
      SOF0(uint16_t image_width, uint16_t image_height, uint8_t n_components);

    private:
      uint8_t precision {};
      std::vector<uint8_t> image_height;
      std::vector<uint8_t> image_width;
      uint8_t num_components {};
      std::vector<uint8_t> components;

      void init();
      void pack() override;
  };

  class DHT : public Marker {
    public:
      DHT();

    private:
      void init();
  };

  class SOS : public Marker {
    public:
      SOS();

    private:
      void init();
  };

}

#endif //BEEIO_JPEG_HEADER_H
