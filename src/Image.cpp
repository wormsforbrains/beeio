#include <Image.h>
#include <stdexcept>
#include <jpeg.h>

namespace beeio {

  const std::map<Image::ColorDepth, int> Image::colorDepthMap = {
      {Image::ColorDepth::BINARY_BYTE, 8},
      {Image::ColorDepth::GRAY_BYTE,   8},
      {Image::ColorDepth::RGB_3BYTE,   24},
      {Image::ColorDepth::RGBA_4BYTE,  32}
  };

  Image Image::create(ColorDepth colorDepth, int width, int height) {
    Image img;
    img.colorDepth = colorDepth;
    img.width = width;
    img.height = height;
    const uint8_t byteDepth = colorDepthMap.at(colorDepth) >> 3; // x >> 3 == x / 8
    img.data = std::vector<uint8_t>(width * height * byteDepth);
    return img;
  }

  Image Image::create(ColorDepth colorDepth, int width, int height, int color) {
    Image img;
    img.colorDepth = colorDepth;
    img.width = width;
    img.height = height;
    const uint8_t byteDepth = colorDepthMap.at(colorDepth) >> 3; // x >> 3 == x / 8
    img.data = std::vector<uint8_t>(width * height * byteDepth);
    img.fill(color);
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

  void Image::fill(int color) {
    switch (colorDepth) {
      case BINARY_BYTE: {
        color *= 0xff; // 0 if color is 0, 255 if color is 1
        std::fill(this->data.begin(), this->data.end(), color);
        break;
      }
      case GRAY_BYTE: {
        std::fill(this->data.begin(), this->data.end(), color);
        break;
      }
      case RGB_3BYTE: {
        uint8_t r = color >> 24 & 0xff;
        uint8_t g = color >> 16 & 0xff;
        uint8_t b = color >> 8 & 0xff;
        for (int i = 0; i < this->data.size(); i += 3) {
          this->data[i] = r;
          this->data[i + 1] = g;
          this->data[i + 2] = b;
        }
        break;
      }
      case RGBA_4BYTE: {
        uint8_t r = color >> 24 & 0xff;
        uint8_t g = color >> 16 & 0xff;
        uint8_t b = color >> 8 & 0xff;
        uint8_t a = color & 0xff;
        for (int i = 0; i < this->data.size(); i += 4) {
          this->data[i] = r;
          this->data[i + 1] = g;
          this->data[i + 2] = b;
          this->data[i + 3] = a;
        }
        break;
      }
    }
  }

}
