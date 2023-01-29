#ifndef BEEIO_DISCRETECOSINETRANSFORM_H
#define BEEIO_DISCRETECOSINETRANSFORM_H

#include <vector>
#include <cstdint>

namespace beeio {

  std::vector<double> discreteCosineTransform(const std::vector<uint32_t> &image);

}

#endif //BEEIO_DISCRETECOSINETRANSFORM_H
