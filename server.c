/* 
*	Admin: Arvind Krishna
*	github - github.com/ArvindAROO
*	type - c_project
*	server file for the project
*/

//All the includes
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<limits.h>

#include"server.h"

void clean_stdin() {
  //Since the default buffer clear function 
  //is system dependent.,this function clears buffer in all cases 
  int c;
  while ((c = getchar()) != '\n' && c != EOF){}
}

void clrscr(){
	//This func clears the buffer 
	clean_stdin();
	//and also clears the screen when you press any key
	//this is system dependent
	
	printf("\nPress Enter key to exit\n");
    #ifdef _WIN64
    	getchar();
        system("cls");
    #endif
    #ifdef __APPLE__
    	getchar();
        system("clear");
    #endif
    #ifdef __linux__
    	getchar()
        system("clear");
    #endif
}

void delay(float seconds)	
{
	//This function mimics the sleep function in python
	//by taking control for an amount of time
	int milli=1000*seconds;
	clock_t start=clock();
	while(clock()<start+milli);
	
}
void initializeQueue(queue* q){
	//This function initializes the queue values
	//which can be used further ado
    q->count = 0;
    q->front = 0;
    q->back = -1;
}
void addToQueue(queue* q, plane next){
	//This functions adds the plnlane item
    if(q->count >= MAX_POSSIBLE){
    	// if the queue is full, no more planes can be handled
        printf("\nQueue is isFull\n");
        return ;
    }
    //else adds one more plnlane to the queue
	// and increases the count by one
    (q->count)++;
    q->back++;
	q->back %= MAX_POSSIBLE;
    q->arrayOfPlanes[q->back] = next ;
}

plane popQueue(queue *q) {
	//the function delete the element of the queue
	//which element doesm't matter because queue always follows FIFO
    plane Plane ;

    if(q->count <= 0) {
    	//if the queue is already empty,
    	//there is no point is popping the element
    	//hence returns the first plane
        printf("\nQueue is isEmptyQueue.\n");
        Plane.planeID = 0 ;
        Plane.fuelTime = 0 ;
    }else {
    	//else if will pop the first element entered
    	//and makes the second element as the first element
        (q->count)--;
        //the loss of one element reduces the count by one
        Plane=q->arrayOfPlanes[q->front] ;
        q->front=(q->front+ 1) % MAX_POSSIBLE ;
    	//this part does the popping
	}
    return Plane ;
	//returns the plane object
}

int sizeOfQueue(queue q) {
	//this function returns the size of the queue
	//count is an element of the above defined queue object
    return q.count ;
}

int isEmptyQueue(queue q){
	//this returns a boolean which says whether the sizeOfQueue
	// is non-zero or not
    return(sizeOfQueue(q) < 1);
}

int isFullQueue(queue q){
	//this functions returns a boolean which says 
	//whether the queue is full or not
    return(sizeOfQueue(q) >= MAX_POSSIBLE);
}

void initializeAirport(airport *airPort){
	//This function initialises the airport by taking an
	//airport object and setting its values  
    initializeQueue(&(airPort->landingInit));
    initializeQueue(&(airPort->takeoffInit));
	//the above lines call the function which initialises the queues
	// the initialized queues are queue objects, we now replace
	//with queue pointers for easy handling
    //landingQueue and takeoffQueue are pointers
	airPort->landingQueue = &(airPort->landingInit);
    airPort->takeoffQueue = &(airPort->takeoffInit);
    //the below values are initialised to zero for future purposes
    airPort->NumOfPlanes = airPort->NumOfLand = airPort->NumOfTakeOffs =0;
	airPort->NumOfRefuses = airPort->idletime = 0 ;
    airPort->waitForLanding = airPort->waitForTakeoff = 0 ;
}

void start(int *totalTime, double *expectArrive, double *expectDepart){
	//this functions is the submain function which just
	//starts the whole process.
    int flag = 1;
	double temp;

    printf("\nProgram that simulates an airport with only one runway.\n");
    printf("One plane can land or depart in each unit of time.\n");
    printf("Up to %d planes can be waiting to land or take off at any time.\n", MAX_POSSIBLE);
    //since the random number generator in c is bad version of pseudo random generator
    //it will generate the same pattern each time unless we explicitly seed it
    seed();
    while(flag){
    	//making sure that the values we take are not meaning less
    	//we use a while loop and break out if everythings fine
        printf("How many units of time will the simulation run?");
    	scanf("%lf", &temp);
    	*totalTime = temp/1;
    	//If the input by mistake is given as a float for total time
    	//The above lines handle that
		printf("\nExpected number of arrivals per unit time?>> ");
        scanf(" %lf", expectArrive);
        printf("\nExpected number of departures per unit time?>> ");
        scanf(" %lf", expectDepart);
        //since its mathematically meaningless to get negative values
        //we keep on taking the values as long as there are wrong values
        if(*expectArrive < 0.0 || *expectDepart < 0.0 || *totalTime < 0){
            printf("These numbers must not be negative.\nPlease re-enter the values\n");
        	flag = 1;
    	}else
            flag = 0;
    }
    printf("\n%lf %lf %d\n",*expectArrive,*expectDepart,*totalTime);
    printf("\n\n\n");
    return;
}


void createNewPlane(airport *airPort, int curtime, int type) {
	//this function generate a neew plane 
    (airPort->NumOfPlanes)++;
    //adding a new plane increases the number of planes
    //the id will be 'n' for 'n'th plane
	airPort->p.planeID = airPort->NumOfPlanes ;
    airPort->p.fuelTime = curtime ;
	//alloting the necessary values
    switch(type) {
    	//printing the statements
    	//since return is used, there is no need for break
        case ARRIVE :
            printf("\nPlane %d ready to land.\n", airPort->NumOfPlanes);
        	return;

        case DEPART :
            printf("\nPlane %d ready to take off.\n", airPort->NumOfPlanes);
            return ;
            
        default:
        	printf("Error");
        	exit(0);
        	break;
    }
}

void refuseLand(airport *airPort) {
	//if there is an incoming queue of landing planes
	// the takeoffs must be refused, since they are of lower priority
    printf("\nPlane %d told to try later.\n", airPort->p.planeID);
	//since only takeoffs can be refused, there is no need for an identifier
	//whether its takeoff or landing
    (airPort->NumOfRefuses)++;
}

void land(airport *airPort, plane Plane, int currentTime) {
	//This function effectively lands the plane
	//By changing the variables which must be changed after landing
    int wait;
    //The plane wait a maximum of time wait
    wait = currentTime - Plane.fuelTime;
    printf("\n%d: Plane %d landed ", currentTime, Plane.planeID);
    printf("in queue %d units \n", wait);
    (airPort->NumOfLand)++ ;
    //The num of planes landed will increase 
    //Also the total time waited will also be incremented
	(airPort->waitForLanding) += wait ;
}

void fly(airport *airPort, plane Plane, int curtime) {
	//This function effectively takes off the plane
	//By changing the variables which must be changed after landing
    int wait ;
    //The plane wait a maximum of time wait
    wait = curtime - Plane.fuelTime ;
    printf("%d: Plane %d took off ", curtime, Plane.planeID);
    printf("in queue %d units \n", wait);
    (airPort->NumOfTakeOffs)++ ;
    //The num of planes took off will increase 
    //Also the total time waited will also be incremented
    (airPort->waitForTakeoff) += wait ;
}

void idle(airport *airPort, int curtime) {
	//This function calculates the amount of time runway left idle
    printf("%d: Runway is idle.\n", curtime);
    airPort->idletime++;
}

void Result(airport *airPort, int totalTime) {
	//This functions prints all the results 
	printf("\nResult>>>\n");
    printf("\tSimulation has concluded after %d units.\n", totalTime);
    printf("\tTotal number of planes processed: %d\n", airPort->NumOfPlanes);
    printf("\tNumber of planes landed: %d\n", airPort->NumOfLand);
    printf("\tNumber of planes taken off: %d\n", airPort->NumOfTakeOffs);
    printf("\tNumber of planes refused use: %d\n", airPort->NumOfRefuses);
    printf("\tNumber left ready to land: %d\n", sizeOfAirport(*airPort, ARRIVE));
    printf("\tNumber left ready to take off: %d\n", sizeOfAirport(*airPort, DEPART));
	//the below statements must be executed only if
	//certain values are defined
	
	//eg, if numoflands = 0, then there is no point in calculationg avgWaitForLand
    if(totalTime>0){
		double percentIdleTime =((double)airPort->idletime/totalTime)*100.0;
		printf("\tPercentage of time runway idle: %.3lf \n", percentIdleTime);
	}
	if(airPort->NumOfLand>0){
		double avgWaitTimeForLand =((double)airPort->waitForLanding/airPort->NumOfLand);
		printf("\tAverage wait time to land: %.3lf \n", avgWaitTimeForLand);
	}
	if(airPort->NumOfTakeOffs>0){
	double avgWaitTimeForTakeOff =((double)airPort->waitForTakeoff/airPort->NumOfTakeOffs);
	printf("\tAverage wait time to take off: %.3lf \n",avgWaitTimeForTakeOff);
}
	
}

int randomnumber(void) {
	//This function generates random number
	//The seeding was done beforehand
    int random;
    //Since random number generate by c have a flaw of repetition
    //We have taken quite a few steps to avoid that
	random =(rand() + rand())/2;
	random *=(rand() %63);
	//to generate true random nubers we are combining three random numbers
	//All the hardcoded values chosen here are totally random
	random %= 3;
    return random;
}

void airportAddToQueue(airport *airPort, int type) {
	//This function adds a plane to the queue of the airport
	//it is basically a caller function which decides 
	//whether the parameter must be takeoff of landing queue
    switch(type) {
        case ARRIVE :
              addToQueue(airPort->landingQueue, airPort->p);
              break ;

        case DEPART :
              addToQueue(airPort->takeoffQueue, airPort->p);
              break ;
            
		default:
            printf("Error");
            exit(0);

    }
}

plane airportPopQueue(airport *airPort, int type) {
	//This function deletes a plane to the queue of the airport
	//it is basically a caller function which decides 
	//whether the parameter must be takeoff of landing queue
   	plane p1 ;
	switch(type) {
        case ARRIVE :
            p1 = popQueue(airPort->landingQueue);
            return p1 ;

        case DEPART :
            p1 = popQueue(airPort->takeoffQueue);
            return p1 ;

        default:
            printf("Error");
            exit(0);
    }
}

int sizeOfAirport(airport airPort, int type) {
	//This function finds the size of the airport
	//it is basically a caller function which decides 
	//whether the parameter must be takeoff of landing queue
    switch(type) {
        case ARRIVE :
              return(sizeOfQueue(*(airPort.landingQueue)));

        case DEPART :
              return(sizeOfQueue(*(airPort.takeoffQueue)));

        default:
            printf("Error");
            exit(0);

    }
}

int isFullAirport(airport airPort, int type) {
	//This function finds the size of the airport and 
	//determines whether it is isFullQueue 
	//it is basically a caller function which decides 
	//whether the parameter must be takeoff of landing queue
    switch(type) {
        case ARRIVE :
            return(isFullQueue(*(airPort.landingQueue)));

        case DEPART :
            return(isFullQueue(*(airPort.takeoffQueue)));
    	
    	default:
            printf("Error");
            exit(0);
    }
}

int isEmptyAirport(airport airPort, int type) {
	//This function finds the size of the airport and 
	//determines whether it is empty
	//it is basically a caller function which decides 
	//whether the parameter must be takeoff of landing queue
    switch(type) {
        case ARRIVE :
            return(isEmptyQueue(*(airPort.landingQueue)));

        case DEPART :
            return(isEmptyQueue(*(airPort.takeoffQueue)));
        
        default:
            printf("Error");
            exit(0);
    }
}

void seed(void){
	//This function seeds the rand function
	//making it generate a differnent pattern
    srand((unsigned int)(time(NULL) % 10000));
}

