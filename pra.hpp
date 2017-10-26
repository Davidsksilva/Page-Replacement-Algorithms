#include <iostream>
#include <vector>
#include <queue>

struct Page{
  int id;
  int counter;
};

class PRA{
  int timeCounter = 0;
  int nBlocks = 0;
  std::vector<int>* Sequence;
  int* Table = nullptr;
  int pageLacks = 0;
public:
  int checkTableEmpty(void);
  int checkInTable(int);
  bool isInQueue(std::queue <int>,int);
  PRA(std::string);
  void FIFO(void);
  void OTM(void);
  void LRU(void);
  void getData(std::string);
};
