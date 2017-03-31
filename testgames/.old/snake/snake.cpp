#include "snake.h"

Snake::Snake() {
  eng.init("Snake", Width, Height, 0);
  handle.reset();

  snake.setImage("sprites.bmp", eng.getRenderer());
  cherry.setImage("sprites.bmp", eng.getRenderer());

  segmentsList.push_back(std::make_pair(5, 5));
  segmentsList.push_back(std::make_pair(5, 6));
  segmentsList.push_back(std::make_pair(4, 6));
  generateFruit();
}

void Snake::generateFruit() {
  auto done = false;
  do {
    fruitX = rand() % (Width / 64);
    fruitY = rand() % (Height / 64);
    done = true;
    for (const auto &segment: segmentsList) {
      if (fruitX == segment.first && fruitY == segment.second) {
        done = false;
        break;
      }
    }
  } while (!done);
}

Snake::~Snake() {

}

int Snake::exec() {

  bool done = true;
  while(done) {
    eng.loopStart();
    bool frame = true;
    while(frame) {
      eng.update();
	handle.logPress();
    if(handle.checkKey(handle.down)) {
      dx = 0;
      dy = 1;
    }
    if(handle.checkKey(handle.right)) {
      dx = 1;
      dy = 0;
    }
    if(handle.checkKey(handle.up)) {
      dx = 0;
      dy = -1;
    }
    if(handle.checkKey(handle.left)) {
      dx = -1;
      dy = 0;
    }
    if(handle.checkKey(handle.quit)) done = true;;
    if(handle.checkKey(handle.esc)) done = true;
    eng.setColor(0x7f, 0x7f, 0x7f);


    draw();
      if(!eng.FPS()) frame=false;
    }
    eng.render();
  }
  return 0;
}

bool Snake::tick() {
  if (ticks++ % 250 == 0) {
    auto p = segmentsList.front();
    p.first += dx;
    p.second += dy;
    if (p.first < 0 || p.first >= Width / 64 ||
        p.second < 0 || p.second >= Height / 64)
      return false;
    for (const auto &segment: segmentsList)
      if (p == segment)
        return false;
    segmentsList.push_front(p);
    if (p.first != fruitX || p.second != fruitY)
      segmentsList.pop_back();
    else
      generateFruit();
  }
  return true;
}

void Snake::draw() {
  snake.setFrame(0, 0, 64, 64);
  snake.setDestSize(64, 64);
  cherry.setFrame(0, 0, 64, 64);
  cherry.setDestSize(64, 64);
  int ds[][3] = {
    { -1, 0, 0 },
    { 0, -1, 90 },
    { 1, 0, 180 },
    { 0, 1, -90 },
  };
  for (auto iter = std::begin(segmentsList); iter != std::end(segmentsList); ++iter) {
    snake.setAngle(0);
    const auto &segment = *iter;
    if (iter == std::begin(segmentsList)) {
      if (iter->first + dx == fruitX && iter->second + dy == fruitY)
        snake.setFrameX(HeadOpenMouth * 64);
      else
        snake.setFrameX(Head * 64);
      if (iter + 1 != std::end(segmentsList)) {
        const auto &nextSegment = *(iter + 1);
        for (const auto &d: ds) {
          if (segment.first + d[0] == nextSegment.first && segment.second + d[1] == nextSegment.second) {
            snake.setAngle(d[2]);
            break;
          }
        }
      }
    }
    else if (iter + 1 == std::end(segmentsList)) {
      snake.setFrameX(Tail * 64);
      const auto &prevSegment = *(iter - 1);
      for (const auto &d: ds) {
        if (segment.first == prevSegment.first + d[0] && segment.second == prevSegment.second + d[1]) {
          snake.setAngle(d[2]);
          break;
        }
      }
    }
    else {
      const auto &nextSegment = *(iter + 1);
      const auto &prevSegment = *(iter - 1);
      if (nextSegment.first == prevSegment.first) {
        snake.setFrameX(Straight * 64);
        snake.setAngle(90);
      }
      else if (nextSegment.second == prevSegment.second) {
        snake.setFrameX(Straight * 64);
        snake.setAngle(0);
      }
      else {
        snake.setFrameX(Turn * 64);
        bool up = false;
        if (segment.first == nextSegment.first && segment.second - 1 == nextSegment.second)
          up = true;
        if (segment.first == prevSegment.first && segment.second - 1 == prevSegment.second)
          up = true;
        bool right = false;
        if (segment.first + 1 == nextSegment.first && segment.second == nextSegment.second)
          right = true;
        if (segment.first + 1 == prevSegment.first && segment.second == prevSegment.second)
          right = true;
        bool down = false;
        if (segment.first == nextSegment.first && segment.second + 1 == nextSegment.second)
          down = true;
        if (segment.first == prevSegment.first && segment.second + 1 == prevSegment.second)
          down = true;
        bool left = false;
        if (segment.first - 1 == nextSegment.first && segment.second == nextSegment.second)
          left = true;
        if (segment.first - 1 == prevSegment.first && segment.second == prevSegment.second)
          left = true;
        if (up && right)
          snake.setAngle(0);
        else if (right && down)
          snake.setAngle(90);
        else if (down && left)
          snake.setAngle(180);
        else if (left && up)
          snake.setAngle(270);
      }
    }

    snake.setDestX(64 * segment.first);
    snake.setDestY(64 * segment.second);
    eng.draw(snake);
  }
  cherry.setFrameX(Fruit * 64);
  cherry.setDestX(fruitX * 64);
  cherry.setDestY(fruitY * 64);
  cherry.setAngle(0);
  eng.draw(cherry);
}
