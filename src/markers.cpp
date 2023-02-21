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
    segment_length << 0x00 << 0x10;

    jfif << 'J' << 'F' << 'I' << 'F' << 0x00;
    version << 0x01 << 0x02;
    densityUnits = 0x01;
    xDensity << 0x00 << 0x48;
    yDensity << 0x00 << 0x48;
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

  /*
   *      marker prefix:  1 byte  (0xFF)
   *        marker type:  1 byte  (0xDB)
   *     segment length:  2 bytes (0x00 0x43) (if precision is 8-bit, else (0x00 0x83))
   *          precision:  4 bits  (0b0000 (8-bit)) or (0b0001 (16-bit))
   *           table id:  4 bits  (0b0000 to 0b1111)
   * quantization table: 64 bytes (if precision is 8-bit, else 128 bytes)
   *         total size: 67 bytes (if precision is 8-bit, else 131 bytes)
   */
  DQT::DQT(uint8_t precision, uint8_t id) {
    quantizationTable = std::vector<uint8_t>(64);

    has_data = true;
    marker_prefix = 0xFF;
    marker_type = 0xDB;
    segment_length << 0x00 << 0x43;

    precisionAndId << (precision << 4) | id;
    quantizationTable << JPEG::jpegQuantizationTable;

    init();
  }
  void DQT::pack() {
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
    segment_data << segment_length << precisionAndId << quantizationTable;

    // Append segment_data to marker_data
    marker_data << segment_data;
  }
  void DQT::init() { pack(); }


    init();
  }

  }

}
