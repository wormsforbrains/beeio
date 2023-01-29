#include <fstream>
#include <vector>
#include <jpeg.h>

int main() {
  int width = 200;
  int height = 300;
  std::vector<unsigned char> image_data(width * height);

  for (unsigned char & i : image_data) {
    i = 0xff;
  }

  beeio::JPEG jpeg(image_data, width, height);
  jpeg.save("image.jpg");
  return 0;
}
