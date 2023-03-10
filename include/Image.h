#ifndef BEEIO_IMAGE_H
#define BEEIO_IMAGE_H

#include <vector>
#include <map>
#include <string>

namespace beeio {

  class Image;

  class Image {
    public:
      enum ColorDepth {
        BINARY_BYTE, GRAY_BYTE, RGB_3BYTE, RGBA_4BYTE
      };

      static const std::map<ColorDepth, int> colorDepthMap;

      // Factory methods
      static Image create(ColorDepth colorDepth, int width, int height);
      static Image create(ColorDepth colorDepth, int width, int height, int color);

      // Getters
      int getWidth() const;
      int getHeight() const;
      std::vector<uint8_t> getPixelVector() const;
      std::vector<uint8_t> getPixel(int x, int y) const;

      // Setters
      void setPixelVector(const std::vector<uint8_t> &vector);
      void setPixel(int x, int y, int color);

      // Member methods
      void fill(int color);
      void save(const std::string &filepath, const std::string &format) const;
    private:
      // Member variables
      ColorDepth colorDepth {};
      int width {};
      int height {};
      std::vector<uint8_t> data;

      // Constructors
      Image() = default;
  };

}

#endif //BEEIO_IMAGE_H
