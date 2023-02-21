#ifndef BEEIO_JPEG_H
#define BEEIO_JPEG_H

#include <markers.h>

#include <vector>
#include <string>
#include "Image.h"

namespace beeio {

  class JPEG {
    public:
      JPEG(std::vector<unsigned char> image_data, int width, int height, int num_components = 3);
      void save(const std::string &file_path);
    private:
      std::vector<unsigned char> image_data_;
      int width_;
      int height_;
      int num_components_;
      void _write_header(std::ofstream &file);
      void _write_image_data(std::ofstream &file);
  };

}


#endif //BEEIO_JPEG_H
