#include <markers.h>
#include "discreteCosineTransform.h"
#include "jpeg.h"

namespace beeio {

  std::vector<uint8_t> &operator <<(std::vector<uint8_t> &v1, const std::vector<uint8_t> &v2) {
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
  }

  std::vector<uint8_t> &operator <<(std::vector<uint8_t> &v, const uint8_t &value) {
    v.push_back(value);
    return v;
  }

  // SOI
  SOI::SOI() : Marker() {
    markerPrefix = 0xFF;
    markerType = 0xD8;
  }

  // EOI
  EOI::EOI() : Marker() {
    markerPrefix = 0xFF;
    markerType = 0xD9;
  }

  // APP0
  APP0::APP0() : Marker() {
    jfif = std::vector<uint8_t>(5);
    version = std::vector<uint8_t>(2);
    xDensity = std::vector<uint8_t>(2);
    yDensity = std::vector<uint8_t>(2);

    hasData = true;
    markerPrefix = 0xFF;
    markerType = 0xE0;

    segmentLength.assign({0x00, 0x10});
    jfif.assign({'J', 'F', 'I', 'F', 0x00});
    version.assign({0x01, 0x02});
    densityUnits = 0x01;
    xDensity.assign({0x00, 0x48});
    yDensity.assign({0x00, 0x48});
    xThumbnail = 0x00;
    yThumbnail = 0x00;
  }

  DQT::DQT(const QuantizationTable &quantizationTable) : quantizationTable(quantizationTable) {
    hasData = true;
    markerPrefix = 0xFF;
    markerType = 0xDB;
    uint16_t tableLength = quantizationTable.size() + 2;
    segmentLength.assign({static_cast<uint8_t>(tableLength >> 0x08), static_cast<uint8_t>(tableLength & 0xFF)});
    segmentData.assign({0});
    segmentData.insert(segmentData.end(), quantizationTable.begin(), quantizationTable.end());
  }

}
