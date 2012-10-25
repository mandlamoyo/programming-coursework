/* G51PRG Exercise One: Variables and Functions
*	Mandla Moyo - mxm12u - 4102907
*
*	Consists of three parts:
*		1) Prints out the volumes of four spheres
*		2) Converts four monetary values into constituents
*		3) Prints an end time given a start and duration
*/


#include <stdio.h>

#define START    0
#define DURATION 1
#define PI 3.14159265


double volumeForRadius( double radius );
double exponentOf( double base, int exp );

void getChange( int value );

int addTimes( int start, int duration );
int getMins( int time );
int getHours( int mins );


int main( int args, char **argc )
{
	int i;
	double radii[4]    =  { 1, 4.657, 10, 42 };
	int moneyValues[4] =  { 20, 79, 10, 42 };
	int times[3][2]    = {{ 1045, 345 },
			      { 800, 435 },
			      { 2300, 300 }};

	for( i = 0; i < 11; i++ ) {
		if( i%4 == 0 ) printf( "\n" );

		// Execution of part 1
		if( i < 4 ) printf( "The volume for a sphere with radius %g is %3.7f\n", radii[i], volumeForRadius( radii[i] ));
		
		// Execution of part 2
		if( i > 3 && i < 8 ) getChange( moneyValues[i%4]);
		
		// Execution of part 3
		if( i > 7 ) printf( "Start time is %d. Duration is %d. End time is %d\n", times[i%4][START], times[i%4][DURATION], addTimes( times[i%4][START], times[i%4][DURATION] )); 
	}
}

// Part 1
double volumeForRadius( double radius )
{
	return (4.0/3.0)*PI*exponentOf( radius, 3 );
}

double exponentOf( double base, int exp )
{
	int i, result = 0;
	
	for( i = 0; i < exp; i++ ) result += base;
	return result;
}

// Part 2
void getChange( int value )
{
	/* This function returns the change combination with
	    the fewest possible notes/coins required to represent
	    a given value.
	
		Pre: None
		Post: Combination is printed to stdout */

	int i;
	int denom[]   = {20,10,5,1};
	int results[4] = {0};
	char text[4][6] = { "notes", "notes", "notes", "coins" };
	int valueLeft = value;

	for( i = 0; i < 4; i++ ) {
		results[i] = valueLeft/denom[i];
		valueLeft = valueLeft%denom[i];
		
		if( results[i] == 1) text[i][4] = '\0';
		if( valueLeft == 0 ) break;
	}

	printf( "£%d consists of %d £20 %s, %d £10 %s, %d £5 %s, and %d pound %s\n", value, results[0], text[0], results[1], text[1], results[2], text[2], results[3], text[3] );
	
}

// Part 3
int addTimes( int start, int duration )
{
	/* This function returns the finishing time given a
	    starting time and the duration of time elapsed since.
	
		Pre: 'start' and 'duration' are specified in military time (ie 1400)
		Post: Finishing time is returned in military time */

	int mins;

	mins = getMins( start ) + duration;
	return getHours( mins );
}

int getMins( int time )
{
	/* Returns the numbers of minutes which constitute
	    a time specified in military time */
	
	int hours, mins, minsInHours;
	
	hours = time/100;
	mins = time - hours*100;
	minsInHours = hours*60;

	return mins + minsInHours;
}

int getHours( int mins )
{
	/* Returns, starting from 0000, the military time
	    after a given number of minutes have elapsed */

	int hours, minsLeft;

	hours = (mins/60) * 100;
	minsLeft = mins%60;
	return (hours+minsLeft)%2400;
}

