#include "Defesa.h"
#include "general.h"
#include <stdlib.h>
#include <math.h>

Defense *initDefense(Point *p, int hp, TIRO_TIPO shotType) {
   Defense *d;
   d = mallocSafe(sizeof(Defense));
   d->position = p;
   if (hp == 0) d->hp = DEFAULT_HP;
   if (shotType == NORMAL) {
     d->accuracy = DEFAULT_ACCURACY;
     d->shotPower = DEFAULT_POWER;
     d->shotFrequency = DEFAULT_FREQUENCY;
   }
   return d;
}

int isDefenseDestroyed(Defense *d) {
   return d->hp == 0;
}

void defenseGotHit(Defense *d, int shotPower) {
   d->hp -= shotPower;
}

void alterAttackPattern(Defense *d) {
   if (d->distance <= CRITICAL_DISTANCE) d->shotFrequency += 2;
}

boolean updateDefesa(Defense *d)
{
  d->position->z -= (double) DZ;
  return (d->position->z < 0);
}

/*Não basta dar free em d, precisa librera a struct position também*/
void freeDefense(Defense *d)
{
  if(d != NULL)
  {
    free(d->position);
    free(d);
  }
}
