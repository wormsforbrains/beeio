#ifndef BEEIO_IMAGE_H
#define BEEIO_IMAGE_H

#include <vector>
#include <map>
#include <string>

namespace beeio {


  class Image {
    public:
      enum ColorDepth {
        BINARY_BYTE, GRAY_BYTE, RGB_3BYTE, RGBA_4BYTE
      };

      static const std::map<ColorDepth, int> colorDepthMap;

      // Factory methods
      static Image create(ColorDepth colorDepth, int width, int height);
      static Image create(ColorDepth colorDepth, int width, int height, uint32_t color);

      // Getters
      int getWidth() const;
      int getHeight() const;

      // Member methods
      void save(const std::string &filepath, const std::string &format) const;
    private:
      // Member variables
      ColorDepth colorDepth {};
      int width {};
      int height {};

      // Constructors
      Image() = default;
  };

}

#endif //BEEIO_IMAGE_H
