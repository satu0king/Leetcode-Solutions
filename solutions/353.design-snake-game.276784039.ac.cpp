class SnakeGame {
public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the
     second is at [1,0]. */

  vector<vector<int>> food;
  bool gameOver;

  set<pair<int, int>> positionMap;
  queue<pair<int, int>> positions;
  int width;
  int height;

  SnakeGame(int width, int height, vector<vector<int>> &food)
      : gameOver(false), food(food), width(width), height(height) {
    reverse(this->food.begin(), this->food.end());
    positions.emplace(0, 0);
    positionMap.emplace(0, 0);
  }

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
      @return The game's score after the move. Return -1 if game over.
      Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    if (gameOver)
      return -1;

    auto position = positions.back();
    if (direction == "L")
      position.second--;
    else if (direction == "R")
      position.second++;

    else if (direction == "U")
      position.first--;
    else
      position.first++;

    // cout << position.second <<" "<<  position.first << "
    // "<<positionMap.size() << endl; cout << food.back()[0] <<" "<<
    // food.back()[1] << endl;
    if (food.size() &&
        food.back() == vector<int>{position.first, position.second}) {
      food.pop_back();
    } else {
      positionMap.erase(positions.front());
      positions.pop();
    }

    if (position.first < 0 || position.second < 0 || position.second == width ||
        position.first == height || positionMap.count(position)) {
      gameOver = true;
      return -1;
    }

    positions.push(position);
    positionMap.insert(position);

    return positions.size() - 1;
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
