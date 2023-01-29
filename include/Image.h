#ifndef BEEIO_IMAGE_H
#define BEEIO_IMAGE_H

#include <ImageDraw.h>

#include <vector>
#include <map>
#include <string>
#include <variant>

namespace beeio {

  typedef std::variant<std::vector<uint8_t>, std::vector<uint32_t>> DataVector;

  enum ColorDepth {
    BINARY_BYTE, GRAY_BYTE, RGB_3BYTE, RGBA_4BYTE
  };

  std::map<beeio::ColorDepth, int> colorDepthMap = {
      {beeio::ColorDepth::BINARY_BYTE, 1},
      {beeio::ColorDepth::GRAY_BYTE,   8},
      {beeio::ColorDepth::RGB_3BYTE,   24},
      {beeio::ColorDepth::RGBA_4BYTE,  32}
  };

  class Image {
    public:
      // Factory methods
      static Image create(ColorDepth colorDepth, int width, int height);
      static Image create(ColorDepth colorDepth, int width, int height, uint32_t color);

      // Getters
      int getWidth() const;
      int getHeight() const;
      DataVector getData() const;

      // Member methods
      void save(const std::string &filepath, const std::string &format) const;

    private:
      // Member variables
      ColorDepth colorDepth {};
      int width {};
      int height {};
      DataVector data;

      // Constructors
      Image() = default;

      // Member methods
      void setDataVectorType();
  };

}

#endif //BEEIO_IMAGE_H
