#include "common.h"
#include "./client/UDPclient.h"

int main(int argc, char *argv[])
{
	int sockfd;
	int i;
	char *name;
	char *port;
	char * received;
	char send[256];
	char testMessages[5][256] = {"<loadavg/>", "<echo>Hello World!</echo>", "<echo></echo>", "", "<echo>Bye Bye World...<echo>"};
	struct sockaddr_in * dest;
	char expectedResponses[5][256] = {"", "<reply>Hello World!</reply>", "<reply></reply>", 
				"<error>unknown format</error>", "<error>unknown format</error>"};

	if(argc != 3)
	{
		printf("Not enough arguments -- Exiting program\n");
		return 0;
	}

	name = argv[1];
	port = argv[2];

	srand(time(NULL));

	// 1. Check for loadavg and the print at the same time
	// 2. Check for a standard echo request
	// 3. Check for empty echo request
	// 4. Check for empty request
	// 5. Check for incorrectly formatted echo
	for(i=0;i<5;i++){
		printf("\nTEST %i", i+1);
		printf(((rand() % 2) ? ":\n" : " :\n"));
		sprintf(send, "%s", testMessages[i]);
		sockfd = createSocket(name, atoi(port), &dest);
		if(sockfd < 0){
			printf(" xx Open socket failed\n");	
		}
		else{
			printf(" -> Socket open success\n");			
			if(sendRequest(sockfd, send, dest) < 0){
				printf(" xx Send failed\n");
			}
			else{
				printf(" -> Request sent success\n");	
				if(receiveResponse(sockfd, &received) < 0){
					printf(" xx Receive failed\n");
				}
				else{
					printf(" -> Response received success\n");
					if(i!=0 && strcmp(received, expectedResponses[i]) != 0){
						printf("Incorrect message\n");
						printf("Expected: %s\n", expectedResponses[i]);
						printf("Received: %s\n", received);		
					}
					else if(i!=0){
						printf("Test %i. passed successfully!\n", i+1);		
					}
					else{
						printf("Testing print:\n");
						printResponse(received);
						fprintf(stdout, "Real response -> %s\n", received);
					}
				} 
			}
		}

		free(received);
		free(dest);

		if(closeSocket(sockfd)==0){
			printf(" -> Socket closed success\n");
		}
		else{
			printf(" XX Close failed\n");		
		}
	}

	return 0;
}

