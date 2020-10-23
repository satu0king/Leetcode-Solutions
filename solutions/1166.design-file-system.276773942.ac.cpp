class FileSystem {
  unordered_map<string, int> map;

public:
  FileSystem() {}

  bool createPath(string path, int value) {

    if (map.count(path))
      return false;

    int i = path.size() - 1;
    while (path[i] != '/')
      i--;

    if (i == 0 || map.count(path.substr(0, i))) {
      map[path] = value;
      return true;
    }

    return false;
  }

  int get(string path) {
    if (map.count(path))
      return map[path];
    return -1;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
