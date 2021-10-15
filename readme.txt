SIMULATION OF THE AIRPORT
By,
	Arvind Krishna
	Roll no - 43,
	sec - 'O', sem - II
	SRN - PES1UG19CS090
	github - github.com/ArvindAROO
	mail - i.arvindkrishna@gmail.com

Topic explanation:
	I was given the topic to simulate an airport with only one runway.
Since there is only one runway, only one plane can do any action,
being takeoff or landing. Ofcourse, landing must be given first preference
because a plane can be left to stay in the airport and not in air,
since fuel amount is not infinite. 

Process of running:
1. The user will be prompted to enter the amount of time which the
	simulation take place
2. Then the user will be prompted to enter the average number of planes 
	per unit time taking off and landing
3. The system will simulate for the whole amount of time

Working:
1. After the above mentioned process the backend will start working
2. The system will create random number of planes and randomly 
	initiate their fuel amount
3. Then it will be handled accordingly as per the conditions
4. After every unit of time the output and information
	will be printed to STDOUT.

Requirements:
1. MinGW(gcc) must be in set as Environment variable
2. The system must be able to take input from the STDIN and print to STDOUT
3. The system must have atleast 256 mb of RAM or else the simulation 
	may fail because of data overflow
4. The system must have root access or else the system commands will not work

Example test case:

Program that simulates an airport with only one runway.
One plane can land or depart in each unit of time.
Up to 3 planes can be waiting to land or take off at any time.
How many units of time will the simulation run? 30
Expected number of arrivals per unit time?>>  0.47
Expected number of departures per unit time?>>  0.47


1: Runway is idle.

Plane 1 ready to land.

Plane 2 ready to land.

2: Plane 1 landed in queue 0 units 

2: Plane 2 landed in queue 0 units 

Plane 3 ready to land.

Plane 4 ready to land.

3: Plane 3 landed in queue 0 units 

3: Plane 4 landed in queue 0 units 

Plane 5 ready to take off.
4: Plane 5 took off in queue 0 units 
5: Runway is idle.

Plane 6 ready to land.

Plane 7 ready to land.

6: Plane 6 landed in queue 0 units 

6: Plane 7 landed in queue 0 units 

Plane 8 ready to take off.

Plane 9 ready to take off.

Plane 10 ready to land.

Plane 11 ready to land.

7: Plane 10 landed in queue 0 units 

7: Plane 11 landed in queue 0 units 
8: Plane 8 took off in queue 1 units 
9: Plane 9 took off in queue 2 units 

Plane 12 ready to take off.

Plane 13 ready to take off.
10: Plane 12 took off in queue 0 units 

Plane 14 ready to take off.

Plane 15 ready to take off.

Plane 16 ready to land.

11: Plane 16 landed in queue 0 units 
12: Plane 13 took off in queue 2 units 
13: Plane 14 took off in queue 2 units 
14: Plane 15 took off in queue 3 units 

Plane 17 ready to take off.

Plane 18 ready to take off.

Plane 19 ready to land.

Plane 20 ready to land.

15: Plane 19 landed in queue 0 units 

15: Plane 20 landed in queue 0 units 

Plane 21 ready to land.

Plane 22 ready to land.

16: Plane 21 landed in queue 0 units 

16: Plane 22 landed in queue 0 units 

Plane 23 ready to land.

17: Plane 23 landed in queue 0 units 
18: Plane 17 took off in queue 3 units 
19: Plane 18 took off in queue 4 units 

Plane 24 ready to land.

Plane 25 ready to land.

20: Plane 24 landed in queue 0 units 

20: Plane 25 landed in queue 0 units 

Plane 26 ready to take off.

Plane 27 ready to take off.
21: Plane 26 took off in queue 0 units 

Plane 28 ready to land.

22: Plane 28 landed in queue 0 units 

Plane 29 ready to land.

Plane 30 ready to land.

23: Plane 29 landed in queue 0 units 

23: Plane 30 landed in queue 0 units 

Plane 31 ready to take off.

Plane 32 ready to take off.

Plane 33 ready to land.

Plane 34 ready to land.

24: Plane 33 landed in queue 0 units 

24: Plane 34 landed in queue 0 units 
25: Plane 27 took off in queue 4 units 
26: Plane 31 took off in queue 2 units 

Plane 35 ready to take off.

Plane 36 ready to take off.

Plane 37 ready to land.

27: Plane 37 landed in queue 0 units 
28: Plane 32 took off in queue 4 units 
29: Plane 35 took off in queue 2 units 

Plane 38 ready to take off.

Plane 39 ready to land.

Plane 40 ready to land.

30: Plane 39 landed in queue 0 units 

30: Plane 40 landed in queue 0 units 

Result>>>
	Simulation has concluded after 30 units.
	Total number of planes processed: 40
	Number of planes landed: 24
	Number of planes taken off: 14
	Number of planes refused use: 0
	Number left ready to land: 0
	Number left ready to take off: 2
	Percentage of time runway idle: 6.667 
	Average wait time to land: 0.000 
	Average wait time to take off: 2.071 

Press Enter key to exit
//screen is cleared
Thanks
By,
	Arvind Krishna
	SRN - PES1UG19CS090
	Roll no - 43
	sec - 'O', sem - 2


References:
	1. problem solving with C
	2. geeksforgeeks.com
	3. programiz.com
	4. Let us C


***********************