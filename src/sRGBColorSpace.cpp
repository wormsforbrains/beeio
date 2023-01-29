#include <sRGBColorSpace.h>

#include <vector>
#include <cmath>

namespace beeio {

  std::vector<float> beeio::sRGBColorSpace::toRGB(std::vector<float> colorvalue) {
    std::vector<float> rgb;
    for (float value: colorvalue) {
      if (value <= 0.04045f) {
        rgb.push_back(value / 12.92f);
      } else {
        rgb.push_back(std::pow((value + 0.055f) / 1.055f, 2.4f));
      }
    }
    return colorvalue;
  }


  std::vector<float> beeio::sRGBColorSpace::fromRGB(std::vector<float> colorvalue) {
    std::vector<float> srgb;
    for (float value: colorvalue) {
      if (value <= 0.0031308f) {
        srgb.push_back(value * 12.92f);
      } else {
        srgb.push_back(1.055f * std::pow(value, 1.f / 2.4f) - 0.055f);
      }
    }
    return srgb;
  }


  std::vector<float> beeio::sRGBColorSpace::toCIEXYZ(std::vector<float> colorvalue) {
    std::vector<float> XYZ;
    for (float value: colorvalue) {
      float v = value / 100.0f;
      if (v > 0.04045f) {
        v = std::pow((v + 0.055f) / 1.055f, 2.4f);
      } else {
        v = v / 12.92f;
      }
      v = v * 100.0f;
      XYZ.push_back(v * 0.4124f + v * 0.3576f + v * 0.1805f);
    }
    return XYZ;
  }


  std::vector<float> beeio::sRGBColorSpace::fromCIEXYZ(std::vector<float> XYZ) {
    // Convert to the RGB color space
    std::vector<float> rgb;
    rgb.push_back(3.2406f * XYZ[0] - 1.5372f * XYZ[1] - 0.4986f * XYZ[2]);
    rgb.push_back(-0.9689f * XYZ[0] + 1.8758f * XYZ[1] + 0.0415f * XYZ[2]);
    rgb.push_back(0.0557f * XYZ[0] - 0.2040f * XYZ[1] + 1.0570f * XYZ[2]);

    // Apply the reverse gamma correction
    for (float &value: rgb) {
      if (value <= 0.0031308f) {
        value = value * 12.92f;
      } else {
        value = 1.055f * std::pow(value, 1 / 2.4f) - 0.055f;
      }
    }
    return rgb;
  }

}
