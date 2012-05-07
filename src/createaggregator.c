#include "laser.h"
#include <stdlib.h>

laser_aggregate *createAggregator(short options, double(*custom)(double, double, unsigned long)) {
  laser_aggregate *tmp = (laser_aggregate*)malloc(sizeof(laser_aggregate));

  tmp->options = options;
  tmp->custom = custom;
  tmp->count = 0;

  return tmp;
}
