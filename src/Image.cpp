#include <Image.h>
#include <ImageDraw.h>

namespace beeio {

  Image Image::create(ColorDepth colorDepth, int width, int height) {
    Image img;
    img.colorDepth = colorDepth;
    img.width = width;
    img.height = height;
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

    return data;
  }

}
