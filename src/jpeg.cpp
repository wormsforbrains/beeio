#include "jpeg.h"
#include <markers.h>

#include <fstream>

namespace beeio {

  JPEG::JPEG(std::vector<unsigned char> image_data, int width, int height, int num_components)
      : image_data_(std::move(image_data)), width_(width), height_(height), num_components_(num_components) {}

  void JPEG::save(const std::string &file_path) {
    std::ofstream file(file_path, std::ios::binary);
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
