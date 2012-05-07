#include "laser.h"

void aggregate(laser_aggregate *aggregator, double val) {
  double delta;

  //COUNT
  aggregator->count++;

  //SUM
  aggregator->values[0] += val;  

  //MIN
  if(val < aggregator->values[2]) aggregator->values[2] = val;

  //MAX
  if(val > aggregator->values[3]) aggregator->values[3] = val;

  //MEAN & VARIANCE
  delta = val - aggregator->values[1];
  aggregator->values[1] += delta / aggregator->count;
  aggregator->values[6] += delta * (val - aggregator->values[1]);
  aggregator->values[4] = aggregator->values[6] / aggregator->count;

  //CUSTOM
  if(aggregator->custom != NULL) {
    aggregator->values[5] = aggregator->custom(aggregator->values[5], val, aggregator->count);
  }
}
