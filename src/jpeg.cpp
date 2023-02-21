#include "jpeg.h"
#include <markers.h>

#include <fstream>

namespace beeio {

  JPEG::JPEG(Image image, int width, int height, int num_components)
      : image_(std::move(image)), width_(width), height_(height), num_components_(num_components) {
    jpegQuantizationTable = std::vector<uint8_t>(64);
    jpegQuantizationTable.assign({
                                     16, 11, 10, 16, 24, 40, 51, 61,
                                     12, 12, 14, 19, 26, 58, 60, 55,
                                     14, 13, 16, 24, 40, 57, 69, 56,
                                     14, 17, 22, 29, 51, 87, 80, 62,
                                     18, 22, 37, 56, 68, 109, 103, 77,
                                     24, 35, 55, 64, 81, 104, 113, 92,
                                     49, 64, 78, 87, 103, 121, 120, 101,
                                     72, 92, 95, 98, 112, 100, 103, 99
                                 });
  }

  void JPEG::save(const std::string &file_path) {
    std::basic_ofstream<uint8_t> file(file_path, std::ios::binary);
    _write_header(file);
    _write_image_data(file);
  }

  void JPEG::_write_header(std::basic_ofstream<uint8_t> &file) {
    // Write Start of Image marker
    file << SOI();

    // Write application-specific segment
    file << APP0();

    // Write DQT marker
    file << DQT(0, 0);

    // Write SOF0 marker
    file << SOF0(width_, height_, num_components_);
  }

  void JPEG::_write_image_data(std::basic_ofstream<uint8_t> &file) {
    // Write image data
    std::vector<uint8_t> imageData = image_.getPixelVector();
    file.write(imageData.data(), static_cast<std::streamsize>(imageData.size()));

    // Write End of Image marker
    file << (unsigned char)0xff << (unsigned char)0xd9;
  }

}
