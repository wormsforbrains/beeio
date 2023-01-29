#include <ColorModel.h>

namespace beeio {

    ColorModel::ColorModel(int numComponents, int type) {
        this->numComponents = numComponents;
        this->type = type;
    }

    int ColorModel::getNumComponents() {
        return numComponents;
    }

    int ColorModel::getType() {
        return type;
    }

} // beeio