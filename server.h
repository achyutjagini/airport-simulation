/* 
*	Admin: Arvind Krishna
*	github - github.com/ArvindAROO
*	type - c_project
* 	header file of the project
*/

//defining global constants
#define MAX_POSSIBLE 3
#define ARRIVE 0
#define DEPART 1

//Defining the structure plane
typedef struct Plane {
    int planeID;
    int fuelTime ;
}plane;

//Implementation of queue
typedef struct Queue {
    int count;
    int front;
    int back;
    plane arrayOfPlanes[MAX_POSSIBLE];
} queue;

//Defining the structure plane, which is basically the builder
typedef struct airPort {
    queue landingInit;
    queue takeoffInit;
    queue *landingQueue, *takeoffQueue;
    int waitForLanding, waitForTakeoff;
    int idletime, NumOfLand, NumOfPlanes, NumOfRefuses, NumOfTakeOffs;
    plane p;
}airport;


//function declarations
void delay(float);
void initializeQueue(queue*);
void addToQueue(queue*, plane);
plane popQueue(queue*);
int sizeOfQueue(queue);
int isEmptyQueue(queue);
int isFullQueue(queue);
void initializeAirport(airport*);
void start(int*, double*, double*);
void createNewPlane(airport*, int, int);
void refuseLand(airport*);
void land(airport*, plane, int);
void fly(airport*, plane, int);
void idle(airport*, int);
void Result(airport*, int);
int randomnumber(void);
void airportAddToQueue(airport*, int);
plane airportPopQueue(airport*, int);
int sizeOfAirport(airport, int);
int isFullAirport(airport, int);
int isEmptyAirport(airport, int);
void seed(void);
void clrscr(void);
void clean_stdin(void);
