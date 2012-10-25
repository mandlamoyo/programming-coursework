#include <stdio.h>

#define TRUE 1
#define FALSE 0


int main( int argc, char **args )
{
	int c, titleCount = 0;
	int isTitle = FALSE, printingOut = FALSE, checkingTitle = FALSE;
	char tag[] = "title";
	
	while(( c = getchar() ) != -1 ) {
		
		/* Title checking procedure; matches getchar() 
			position to characters in 'title' */
		if( checkingTitle ) {
			if( c == tag[titleCount] ) {
				titleCount++;
			} else {
				titleCount = 0;
				checkingTitle = FALSE;
			}
		}

		if( titleCount == 5 ) {
			checkingTitle = FALSE;
			isTitle = TRUE;
			titleCount = 0;
		}

		// If tag start, begin checking for 'title' tag
		if( c == '<' ) {
			if( printingOut ) {
				putchar('\n');
				printingOut = FALSE;
			} else {
				checkingTitle = TRUE;
			}
		}

		// Actual character printing
		if( printingOut ) putchar(c); 
		
		// Check for control characters
		if( c == '>' && isTitle ) printingOut = TRUE;
		if( c == '/' && isTitle ) isTitle = FALSE;

	}

	return 0;
}

