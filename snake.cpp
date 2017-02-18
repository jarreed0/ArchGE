#include "snake.h"

Snake::Snake() {
  eng.init(Width, Height, 0);

  snake.setImage("sprites.bmp", eng.renderScreen());
  cherry.setImage("sprites.bmp", eng.renderScreen());

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
  eng.deconstruct();
}

int Snake::exec() {
  auto oldTick = SDL_GetTicks();
  for (auto done = false; !done;) {
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
    eng.preLoop();
    auto currentTick = SDL_GetTicks();
    for (auto t = oldTick; t < currentTick; ++t)
      if (!tick())
        return 1;
    oldTick = currentTick;
    draw();
    eng.endLoop();
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
  snake.setSource(0, 0, 64, 64);
  snake.setDest(64, 64);
  cherry.setSource(0, 0, 64, 64);
  cherry.setDest(64, 64);
  int ds[][3] = {
    { -1, 0, 0 },
    { 0, -1, 90 },
    { 1, 0, 180 },
    { 0, 1, -90 },
  };
  for (auto iter = std::begin(segmentsList); iter != std::end(segmentsList); ++iter) {
    snake.setAng(0);
    const auto &segment = *iter;
    if (iter == std::begin(segmentsList)) {
      if (iter->first + dx == fruitX && iter->second + dy == fruitY)
        snake.setSX(HeadOpenMouth * 64);
      else
        snake.setSX(Head * 64);
      if (iter + 1 != std::end(segmentsList)) {
        const auto &nextSegment = *(iter + 1);
        for (const auto &d: ds) {
          if (segment.first + d[0] == nextSegment.first && segment.second + d[1] == nextSegment.second) {
            snake.setAng(d[2]);
            break;
          }
        }
      }
    }
    else if (iter + 1 == std::end(segmentsList)) {
      snake.setSX(Tail * 64);
      const auto &prevSegment = *(iter - 1);
      for (const auto &d: ds) {
        if (segment.first == prevSegment.first + d[0] && segment.second == prevSegment.second + d[1]) {
          snake.setAng(d[2]);
          break;
        }
      }
    }
    else {
      const auto &nextSegment = *(iter + 1);
      const auto &prevSegment = *(iter - 1);
      if (nextSegment.first == prevSegment.first) {
        snake.setSX(Straight * 64);
        snake.setAng(90);
      }
      else if (nextSegment.second == prevSegment.second) {
        snake.setSX(Straight * 64);
        snake.setAng(0);
      }
      else {
        snake.setSX(Turn * 64);
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
          snake.setAng(0);
        else if (right && down)
          snake.setAng(90);
        else if (down && left)
          snake.setAng(180);
        else if (left && up)
          snake.setAng(270);
      }
    }

    snake.setDX(64 * segment.first);
    snake.setDY(64 * segment.second);
    eng.pushToScreen(snake);
  }
  cherry.setSX(Fruit * 64);
  cherry.setDX(fruitX * 64);
  cherry.setDY(fruitY * 64);
  cherry.setAng(0);
  eng.pushToScreen(cherry);
}
