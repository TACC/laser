#include "laser.h"
#include <stdlib.h>

laser_reduction *createReduction(double(*custom)(double, double, unsigned long)) {
  laser_reduction *tmp = (laser_reduction*)malloc(sizeof(laser_reduction));

  tmp->custom = custom;
  tmp->count = 0;

  int i;
  for(i=0; i<7; i++) tmp->values[i]=0.0;

  return tmp;
}
