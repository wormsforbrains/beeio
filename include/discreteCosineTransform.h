#ifndef BEEIO_DISCRETECOSINETRANSFORM_H
#define BEEIO_DISCRETECOSINETRANSFORM_H

#include <Image.h>

#include <vector>
#include <cstdint>

namespace beeio {

  class DCT;

  class DCT {
    public:
      static std::vector<double> discreteCosineTransform(const Image &img);
  };

}

#endif //BEEIO_DISCRETECOSINETRANSFORM_H
