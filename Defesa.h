#ifndef H_DEFESA_DEFINED
#define H_DEFESA_DEFINED

#define DEFAULT_ACCURACY 3.14
#define DEFAULT_HP 20
#define DEFAULT_POWER 2
#define DEFAULT_FREQUENCY 7
#define CRITICAL_DISTANCE 7.77

typedef struct {
   int x, y, z;
   double accuracy;
   int hp;
   int damage;
   int shotPower;
   int shotFrequency;
   int shotType;
   double distance;
} Defense;

Defense initDefense(int x, int y, int z, int hp, int shotType);

int isDestroyed(Defense d);

void calcDistance(Defense d, int xn, int yn, int zn);

void hit(Defense d, int shotPower);

void alterAtkPattern(Defense d);

#endif