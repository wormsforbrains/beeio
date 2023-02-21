#ifndef BEEIO_JPEG_H
#define BEEIO_JPEG_H

#include <markers.h>

#include <vector>
#include <string>
#include "Image.h"

namespace beeio {

  class JPEG;

  class JPEG {
    public:
      static std::vector<uint8_t> jpegQuantizationTable;

      JPEG(Image image, int width, int height, int num_components = 3);

      void save(const std::string &file_path);

    private:
      Image image_;
      int width_;
      int height_;
      int num_components_;

      void _write_header(std::basic_ofstream<uint8_t> &file);
      void _write_image_data(std::basic_ofstream<uint8_t> &file);
  };

}

#endif //BEEIO_JPEG_H
