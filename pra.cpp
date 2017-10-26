#include "pra.hpp"
#include <fstream>
#include <queue>

#define INT_MAX 2147483647

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
      if(checkTableEmpty() != -1){ // If Table not full
        Table[checkTableEmpty()]=(*Sequence)[i];
        fifo.push((*Sequence)[i]);
      }
      else{ // If Table full
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
  pageLacks=0;
  for(unsigned int i=0;i<Sequence->size(); i++){
    if(checkInTable((*Sequence)[i]) == -1){ // If sequence number is not in Table
      pageLacks++;
      if(checkTableEmpty() != -1){ // If Table not full
        Table[checkTableEmpty()]=(*Sequence)[i];
      }
      else{ // If Table full
        int timeNextCall[nBlocks]={0};
        for(int j=0;j<nBlocks;j++){
          for(unsigned int u=i;u<Sequence->size();u++){
              if((*Sequence)[u] == Table[j]){
                timeNextCall[j]=u;
              }
          }
        }
        int posID=0;
        int posTimeNextCall=0;
        for(int j=0;j<nBlocks;j++){
          if(timeNextCall[j]== 0){
            posID=j;
            posTimeNextCall=INT_MAX;
          }
          else{
            if(timeNextCall[j] > posTimeNextCall){
              posID=j;
              posTimeNextCall=timeNextCall[j];
            }
          }
        }
        Table[posID]=(*Sequence)[i];
      }
    }
  }
  std::cout<<"OTM "<<pageLacks<<std::endl;
}
