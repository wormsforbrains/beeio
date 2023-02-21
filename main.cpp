#include <Image.h>

int main() {
  int width = 5;
  int height = 5;
  beeio::Image img = beeio::Image::create(beeio::Image::BINARY_BYTE, width, height);
  img.fill(1);
  img.save("test.jpg", "jpg");
  return 0;
}
