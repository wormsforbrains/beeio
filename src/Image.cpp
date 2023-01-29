#include <Image.h>
#include <ImageDraw.h>

namespace beeio {

  // set the data vector based on color_depth
  void Image::setDataVectorType() {
    switch (colorDepth) {
      case BINARY_BYTE:
        data = std::vector<uint8_t>(width * height);
        break;
      case GRAY_BYTE:
        data = std::vector<uint8_t>(width * height);
        break;
      case RGB_3BYTE:
        data = std::vector<uint32_t>(width * height);
        break;
      case RGBA_4BYTE:
        data = std::vector<uint32_t>(width * height);
        break;
    }
  }
  
  Image Image::create(ColorDepth colorDepth, int width, int height) {
    Image img;
    img.colorDepth = colorDepth;
    img.width = width;
    img.height = height;
    img.setDataVectorType();
    return img;
  }

  Image Image::create(ColorDepth colorDepth, int width, int height, uint32_t color) {
    Image img;
    return img;
  }

  void beeio::Image::save(const std::string &filepath, const std::string &format) const {

  }

  int Image::getWidth() const {
    return width;
  }

  int Image::getHeight() const {
    return height;
  }

  DataVector Image::getData() const {
    return data;
  }

}
