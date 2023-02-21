#include "Marker.h"

namespace beeio {

  std::basic_ofstream<uint8_t> &operator <<(std::basic_ofstream<uint8_t> &file, const Marker &marker) {
    // write marker data to the file
    file.write(marker.getMarkerData().data(), static_cast<std::streamsize>(marker.getMarkerData().size()));
    return file;
  }

  bool hasData = false;
  std::vector<uint8_t> segmentLength(2);

} // beeio