#include <stdio.h>
#include "ceserial.h"

using namespace std;

int main()
{
#ifdef CE_WINDOWS
	ceSerial com("\\\\.\\COM3",9600,8,'N',1); // Windows
#else
	ceSerial com("/dev/ttyS0",9600,8,'N',1); // Linux
#endif

	printf("Opening port %s.\n",com.GetPort().c_str());
	if (com.Open() == 0) {
		printf("OK.\n");
	}
	else {
		printf("Error.\n");
		return 1;
	}

	bool successFlag;
	// printf("Writing.\n");
	// char s[]="Hello";
	// successFlag=com.Write(s); // write string
	// successFlag=com.WriteChar('!'); // write a character

	// printf("Waiting 3 seconds.\n");
	// ceSerial::Delay(3000); // delay to wait for a character

	printf("Reading.\n");

    while(true) {
	    char c=com.ReadChar(successFlag); // read a char
	    if(successFlag) printf("%c",c);

        if (c == '\n') {
            printf(".");
        }
        
    }
	printf("Closing port %s.\n",com.GetPort().c_str());
	com.Close();
	return 0;
}
