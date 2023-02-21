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

      std::vector<uint8_t> getMarkerData() const;

      virtual void pack();

    protected:
      bool has_data {};
      uint8_t marker_prefix {};
      uint8_t marker_type {};
      std::vector<uint8_t> marker_data;
      std::vector<uint8_t> segment_length;
      std::vector<uint8_t> segment_data;
  };

} // beeio

#endif //BEEIO_MARKER_H
