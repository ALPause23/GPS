



#define F_CPU 40000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void init_periferal();
