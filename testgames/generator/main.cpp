#include <arch/arch.h>
using namespace std;
#include <vector>

#define WIDTH 500
#define HEIGHT 500
#define SIZE 1

vector<Object> pixel;

Engine e;

void generate();

int main() {
 Engine e;
 e.debugMode(true);
 e.init("Generator", WIDTH, HEIGHT, 0);
 e.exitOnEscape(true);
 generate();
 while(e.getRunning()) {
  e.draw(pixel);
  e.loop();
 }
 return 0;
}

void generate() {
 Object tmp;
 tmp.setDestSize(SIZE,SIZE);
 for(int i=0; i<WIDTH/SIZE; i++) {
  for(int j=0; j<HEIGHT/SIZE; j++) {
   tmp.setDestCoord(i*SIZE,j*SIZE);
   tmp.setColor(tmp.blue);
   if(j>((WIDTH/SIZE)/2)) tmp.setColor(tmp.green);
   if(i>((HEIGHT/SIZE)/2)) tmp.setColor(tmp.red);
   pixel.push_back(tmp);
  }
 }
}
