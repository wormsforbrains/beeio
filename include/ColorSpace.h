#ifndef BEEIO_COLORSPACE_H
#define BEEIO_COLORSPACE_H


#include <string>
#include <vector>

namespace beeio {

  class ColorSpace {
    private:
      // Variables
      std::vector<std::string> componentNames;
      int type;
      int numComponents;

    public:
      // Constants
      static const int TYPE_XYZ = 0;
      static const int TYPE_RGB = 1;
      static const int TYPE_GRAY = 2;
      static const int TYPE_2CLR = 3;
      static const int CS_CIEXYZ = 10;
      static const int CS_sRGB = 11;
      static const int CS_GRAY = 12;
      static const int CS_2CLR = 13;

      // Constructors
      ColorSpace(int type, int numComponents);

      // Getters
      std::string getComponentName(int component);
      int getType() const;
      int getNumComponents() const;

      // Virtual methods
      virtual std::vector<float> toRGB(std::vector<float> colorvalue) = 0;
      virtual std::vector<float> toCIEXYZ(std::vector<float> colorvalue) = 0;
      virtual std::vector<float> fromCIEXYZ(std::vector<float> XYZ) = 0;
      virtual std::vector<float> fromRGB(std::vector<float> rgb) = 0;
  };

}


#endif //BEEIO_COLORSPACE_H
