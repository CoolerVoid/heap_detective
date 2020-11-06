/* Generated by re2c 1.0.1 on Sat Sep 19 19:28:48 2020 */
#line 1 "rule.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OPEN,CLOSE,COUNTER,END
};

char *ReadLines(char * NameFile);


int parse_ion(char** p, char** lex)
{
    char* marker;

    for (;;) {
    *lex = *p;
        
#line 22 "gen_re2.c"
	{
		char yych;
		yych = **p;
		switch (yych) {
		case 0x00:	goto yy2;
		case '\n':	goto yy6;
		case 'c':	goto yy8;
		case 'o':	goto yy9;
		default:	goto yy4;
		}
yy2:
		++*p;
#line 28 "rule.c"
		{ return END; }
#line 37 "gen_re2.c"
yy4:
		++*p;
yy5:
#line 29 "rule.c"
		{ continue; }
#line 43 "gen_re2.c"
yy6:
		++*p;
#line 27 "rule.c"
		{ return COUNTER; }
#line 48 "gen_re2.c"
yy8:
		yych = *(marker = ++*p);
		switch (yych) {
		case 'l':	goto yy10;
		default:	goto yy5;
		}
yy9:
		yych = *(marker = ++*p);
		switch (yych) {
		case 'p':	goto yy12;
		default:	goto yy5;
		}
yy10:
		yych = *++*p;
		switch (yych) {
		case 'o':	goto yy13;
		default:	goto yy11;
		}
yy11:
		*p = marker;
		goto yy5;
yy12:
		yych = *++*p;
		switch (yych) {
		case 'e':	goto yy14;
		default:	goto yy11;
		}
yy13:
		yych = *++*p;
		switch (yych) {
		case 's':	goto yy15;
		default:	goto yy11;
		}
yy14:
		yych = *++*p;
		switch (yych) {
		case 'n':	goto yy16;
		default:	goto yy11;
		}
yy15:
		yych = *++*p;
		switch (yych) {
		case 'e':	goto yy19;
		default:	goto yy11;
		}
yy16:
		yych = *++*p;
		switch (yych) {
		case '\n':	goto yy18;
		default:	goto yy16;
		}
yy18:
#line 25 "rule.c"
		{ return OPEN; }
#line 103 "gen_re2.c"
yy19:
		yych = *++*p;
		switch (yych) {
		case '\n':	goto yy21;
		default:	goto yy19;
		}
yy21:
#line 26 "rule.c"
		{ return CLOSE; }
#line 113 "gen_re2.c"
	}
#line 30 "rule.c"

    }
    free(lex);
    free(marker);
}


int main() 
{
    char *p = ReadLines("extest.c");
    char *last = p;
    int test=0,result=0,line_number=1,opens=0,closes=0;
    puts(p);


    while(!result )
	switch (parse_ion(&p, &last)) 
	{
        	case OPEN:
		opens++;
	    	test=1;	
	    	printf("OPEN function at line %d\n",line_number); //   (line_number>2)?line_number+3:line_number);
            	break;


	        case CLOSE:
		closes++;
	        test=0;
     	        printf("CLOSE function at line %d\n",line_number);
   	        break;

        	case COUNTER:
	    	line_number++;
            	break;

        	case END:
	    	result=1;	
            	break;
        }

    if(opens!=closes)
	puts("\n Here be dragons here!\n");
    else
	puts("\n Cannot detect pitfalls here!");


    return 0;
}



char *ReadLines(char * NameFile)
{
	FILE * arq=NULL;

	arq = fopen(NameFile, "rx");

	if( arq == NULL )
	{
		puts("error in to open() file"); 	 
		exit(0);
	}

	char *lineBuffer=calloc(1,1); 
	char line[512];
	memset(line,0,511);

	while( fgets(line,sizeof line,arq) )  
	{
		lineBuffer=realloc(lineBuffer,strlen(lineBuffer)+strlen(line)+2);
		strncat(lineBuffer,line,strlen(lineBuffer)-1);
	}

 
	if( fclose(arq) == EOF )
	{
		printf("Error in close() file %s",NameFile);
		exit(0);
	}

	arq=NULL;

	lineBuffer[strlen(lineBuffer)-1]='\0';

	return lineBuffer;
}