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
    marker_prefix = 0xFF;
    marker_type = 0xD8;
    init();
  }
  void SOI::init() { pack(); }

  // EOI
  EOI::EOI() : Marker() {
    marker_prefix = 0xFF;
    marker_type = 0xD9;
    init();
  }
  void EOI::init() { pack(); }

  // APP0
  APP0::APP0() : Marker() {
    jfif = std::vector<uint8_t>(5);
    version = std::vector<uint8_t>(2);
    xDensity = std::vector<uint8_t>(2);
    yDensity = std::vector<uint8_t>(2);

    has_data = true;
    marker_prefix = 0xFF;
    marker_type = 0xE0;

    segmentLength.assign({0x00, 0x10});
    jfif.assign({'J', 'F', 'I', 'F', 0x00});
    version.assign({0x01, 0x02});
    densityUnits = 0x01;
    xDensity.assign({0x00, 0x48});
    yDensity.assign({0x00, 0x48});
    xThumbnail = 0x00;
    yThumbnail = 0x00;

    init();
  }
  void APP0::pack() {
    // Concatenate the values of the two bytes in the `segment_length` vector to get one int
    const uint16_t segmentLengthU16 = (segment_length[0] << 8) | segment_length[1];

    // Calculate the length of the marker by adding 2 (marker prefix/type length) to the segment length
    const uint16_t markerLength = segmentLengthU16 + 2;

    // Initialize segment_data's size to the segment length
    segment_data = std::vector<uint8_t>(segmentLengthU16);

    // Initialize marker_data's size to the marker length (marker header + segment)
    marker_data = std::vector<uint8_t>(markerLength);

    // Pack marker_prefix and marker_type into marker_data
    marker_data << marker_prefix << marker_type;

    // Pack the segment's data into segment_data in the correct order
    segment_data << segment_length << jfif << version << densityUnits;
    segment_data << xDensity << yDensity << xThumbnail << yThumbnail;

    // Append segment_data to marker_data
    marker_data << segment_data;
  }
  void APP0::init() { pack(); }

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
