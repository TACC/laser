#include "laser.h"
#include <stdlib.h>

laser_reduction *createReduction(short options, double(*custom)(double, double, unsigned long)) {
  laser_reduction *tmp = (laser_reduction*)malloc(sizeof(laser_reduction));

  tmp->options = options;
  tmp->custom = custom;
  tmp->count = 0;

  return tmp;
}