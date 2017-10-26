#include "pra.hpp"
#include <fstream>
#include <queue>

void PRA::getData(std::string fileName){
  std::ifstream file(fileName);
  int aux = 0;
  file >> aux;
  nBlocks = aux;
  Sequence= new std::vector<int>;
  while(file >> aux )
    Sequence->push_back(aux);
}
PRA::PRA(std::string fileName){
  getData(fileName);
  Table = new int[nBlocks];
}
int PRA::checkTableEmpty(){
  for(int i=0;i<nBlocks;i++){
    if(Table[i] == -1)
      return i;
  }
  return -1;
}
int PRA::checkInTable(int value){
  for(int i=0;i<nBlocks;i++){
    if(Table[i] == value)
      return i;
  }
  return -1;
}
bool PRA::isInQueue(std::queue <int> ProcessQueue,int value)
{
  int aux;
  while(!ProcessQueue.empty())
  {
    aux=ProcessQueue.front();
    ProcessQueue.pop();
    if(aux == value)
      return true;
  }
  return false;
}
void PRA::FIFO(){
  std::fill(Table, Table + nBlocks, -1);
  std::queue<int> fifo;
  int pos;
  for(unsigned int i=0;i<Sequence->size(); i++){
    if(checkInTable((*Sequence)[i]) == -1){ // If sequence number is not in Table
      pageLacks++;
      if(checkTableEmpty() != -1){ // If Table not empty
        Table[checkTableEmpty()]=(*Sequence)[i];
        fifo.push((*Sequence)[i]);
      }
      else{ // If Table empty
        pos = checkInTable(fifo.front());
        Table[pos] = (*Sequence)[i];
        fifo.pop();
        fifo.push((*Sequence)[i]);
      }
    }
  }
  std::cout<<"FIFO "<<pageLacks<<std::endl;
}
void PRA::OTM(){
  std::fill(Table, Table + nBlocks, -1);

}
