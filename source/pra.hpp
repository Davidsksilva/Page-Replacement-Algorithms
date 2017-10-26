#include <iostream>
#include <vector>
#include <queue>

struct Page{
  int id=-1;
  int counter=0;
};

class PRA{
  int timeCounter = 0;
  int nBlocks = 0;
  std::vector<int>* Sequence;
  Page* Table = nullptr;
  int pageLacks = 0;
  int checkTableEmpty(void);
  int checkInTable(int);
  bool isInQueue(std::queue <int>,int);
  void getData(std::string);
  void resetTable();
public:
  PRA(std::string);
  void FIFO(void);
  void OTM(void);
  void LRU(void);
};
