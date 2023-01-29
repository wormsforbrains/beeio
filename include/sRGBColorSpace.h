#ifndef BEEIO_SRGBCOLORSPACE_H
#define BEEIO_SRGBCOLORSPACE_H


#include <ColorSpace.h>

#include <vector>

namespace beeio {

  class sRGBColorSpace : public beeio::ColorSpace {
    public:
      explicit sRGBColorSpace() : beeio::ColorSpace(beeio::ColorSpace::TYPE_RGB, 3) {}

      std::vector<float> toRGB(std::vector<float> colorvalue) override;
      std::vector<float> fromRGB(std::vector<float> rgb) override;
      std::vector<float> toCIEXYZ(std::vector<float> colorvalue) override;
      std::vector<float> fromCIEXYZ(std::vector<float> XYZ) override;
  };

}


#endif //BEEIO_SRGBCOLORSPACE_H
