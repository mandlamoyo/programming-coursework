/* Programming Exercise Two: Simple RSS Parser
*	Mandla Moyo
*
* Reads and extracts the titles from an RSS document */

#include <stdio.h>

#define IDLE 0 
#define PRINTING 1
#define CHECKING_TITLE 2 

int main( int argc, char **args )
{
	int c, state=IDLE, titleCount = 0;
	char tag[] = "title";
	
	while(( c = getchar() ) != -1 ) {
	
		switch( state )
		{
			case PRINTING:
				if( c == '<' ) {	
					putchar('\n');
					state=IDLE;
				} else {
					putchar( c );
				}
				break;

			case CHECKING_TITLE:
				/* Match getchar() character
				to characters in 'title' */
				
				if( c == tag[titleCount] ) {
					titleCount++;
				} else {
					if( titleCount == 5 ) state=PRINTING;
					else state=IDLE;
					titleCount = 0;
				}
				break;

			case IDLE:
				if( c == '<' ) state = CHECKING_TITLE;
				break;
		}
	}
	return 0;
}

