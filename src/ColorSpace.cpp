#include <ColorSpace.h>

namespace beeio {

  beeio::ColorSpace::ColorSpace(int type, int numComponents) {
    this->type = type;
    this->numComponents = numComponents;
  }

  std::string beeio::ColorSpace::getComponentName(int component) {
    if (componentNames.empty()) {
      switch (type) {
        case TYPE_XYZ:
          componentNames.assign({"X", "Y", "Z"});
          break;
        case TYPE_RGB:
          componentNames.assign({"Red", "Green", "Blue"});
          break;
        case TYPE_GRAY:
          componentNames.assign({"Gray"});
          break;
        default:
          int nComponents = getNumComponents();
          for (int i = 0; i < nComponents; i++) {
            componentNames.emplace_back("Unnamed color component(" + std::to_string(i) + ")");
          }
      }
    }
    return componentNames[component];
  }

  int beeio::ColorSpace::getType() const {
    return type;
  }

  int beeio::ColorSpace::getNumComponents() const {
    return numComponents;
  }

}
