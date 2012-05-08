#include "laser.h"

void reduce(laser_reduction *reducer, double val) {
  double delta;

  //COUNT
  reducer->count++;

  //SUM
  reducer->values[0] += val;  

  //MIN
  if(val < reducer->values[2]) reducer->values[2] = val;

  //MAX
  if(val > reducer->values[3]) reducer->values[3] = val;

  //MEAN & VARIANCE
  delta = val - reducer->values[1];
  reducer->values[1] += delta / reducer->count;
  reducer->values[6] += delta * (val - reducer->values[1]);
  reducer->values[4] = reducer->values[6] / reducer->count;

  //CUSTOM
  if(reducer->custom != NULL) {
    reducer->values[5] = reducer->custom(reducer->values[5], val, reducer->count);
  }
}
