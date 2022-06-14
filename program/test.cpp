#include <vector>
#include <iostream>

using namespace std;

void main()
{
  vector<float> record_fps;
  float avg_fps = 0;
  for(int i = 0; i < 100; i++)
  {
    record_fps.push_back(5);
  }
  for(int i = 0; i < record_fps.size(); i++)
  {
    avg_fps += record_fps[i] / record_fps.size();
  }

}