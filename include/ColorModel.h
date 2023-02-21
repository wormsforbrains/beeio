#ifndef BEEIO_SRC_COLOR_MODEL_H
#define BEEIO_SRC_COLOR_MODEL_H

#include <string>
#include <vector>

namespace beeio {

  class ColorModel;

  class ColorModel {
    public:
      ColorModel(int numComponents, int type);

      int getNumComponents();
      int getType();

    private:
      int numComponents;
      int type;
      std::vector<std::string> componentNames;
  };

} // beeio

#endif //BEEIO_SRC_COLOR_MODEL_H
