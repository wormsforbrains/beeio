#ifndef BEEIO_MARKER_H
#define BEEIO_MARKER_H

#include <cstdint>
#include <vector>
#include <fstream>

namespace beeio {

  class Marker;

  std::basic_ofstream<uint8_t> &operator <<(std::basic_ofstream<uint8_t> &file, const Marker &marker);

  class Marker {
    public:
      Marker() = default;

    protected:
      bool hasData {};
      uint8_t markerPrefix {};
      uint8_t markerType {};
      std::vector<uint8_t> segmentLength;
      std::vector<uint8_t> segmentData;
  };

} // beeio

#endif //BEEIO_MARKER_H
