/*
 * Creates a datagram socket and connects to a server.
 *
 * serverName - the ip address or hostname of the server given as a string
 * serverPort - the port number of the server
 * dest       - the server's address information; the structure will be initialized with information
 *              on the server (like port, address, and family) in this function call
 *
 * return value - the socket identifier or a negative number indicating the error if a connection could not be established
 */
int createSocket(char * serverName, int serverPort, struct sockaddr_in * dest){
	
	return 0;
}
/*
 * Sends a request for service to the server. This is an asynchronous call to the server, 
 * so do not wait for a reply in this function.
 * 
 * sockfd  - the socket identifier
 * request - the request to be sent encoded as a string
 * dest    - the server's address information
 *
 * return   - 0, if no error; otherwise, a negative number indicating the error
 */
int sendRequest(int sockfd, char * request, struct sockaddr_in * dest){
	return 0;
}
/*
 * Receives the server's response formatted as an XML text string.
 *
 * sockfd   - the socket identifier
 * response - the server's response as an XML formatted string to be filled in by this function into the specified string array
 *
 * return   - 0, if no error; otherwise, a negative number indicating the error
 */
int receiveResponse(int sockfd, char * response){
	return 0;
}
/*
 * Prints the response to the screen in a formatted way.
 *
 * response - the server's response as an XML formatted string
 *
 */
void printResponse(char* response){
	return 0;
}
/*
 * Closes the specified socket
 *
 * sockfd - the ID of the socket to be closed
 * 
 * return - 0, if no error; otherwise, a negative number indicating the error
 */
int closeSocket(int sockfd){
	return 0;
}