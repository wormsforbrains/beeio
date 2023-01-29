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

  void JPEG::_write_header(std::ofstream &file) {
    // Write Start of Image marker
    file << (unsigned char)0xff << (unsigned char)0xd8;

    // Write application-specific segment
    unsigned short segment_length = 16;
    unsigned short version = 1;
    unsigned char units = 1;
    unsigned short x_density = 1;
    unsigned short y_density = 1;
    file << (unsigned char)0xff << (unsigned char)0xe0;
    file.write(reinterpret_cast<char *>(&segment_length), sizeof(unsigned short));
    file << "JFIF" << (unsigned char)0x00;
    file.write(reinterpret_cast<char *>(&version), sizeof(unsigned short));
    file.write(reinterpret_cast<char *>(&units), sizeof(unsigned char));
    file.write(reinterpret_cast<char *>(&x_density), sizeof(unsigned short));
    file.write(reinterpret_cast<char *>(&y_density), sizeof(unsigned short));
    file << (unsigned char)0x00 << (unsigned char)0x00;
    file << (unsigned char)0x00 << (unsigned char)0x00;


    // Write Start of Frame marker
    unsigned short length2 = 17;
    unsigned char precision = 8;
    file << (unsigned char)0xff << (unsigned char)0xc0;
    file.write(reinterpret_cast<char *>(&length2), sizeof(unsigned short));
    file.write(reinterpret_cast<char *>(&precision), sizeof(unsigned char));
    file.write(reinterpret_cast<char *>(&height_), sizeof(int));
    file.write(reinterpret_cast<char *>(&width_), sizeof(int));
    file.write(reinterpret_cast<char *>(&num_components_), sizeof(unsigned char));
  }

  void JPEG::_write_image_data(std::ofstream &file) {
    // Write image data
    file.write(reinterpret_cast<char *>(image_data_.data()), static_cast<std::streamsize>(image_data_.size()));

    // Write End of Image marker
    file << (unsigned char)0xff << (unsigned char)0xd9;
  }

}
