#ifndef INC_COMMON_H
#define INC_COMMON_H

#if		_MSC_VER > 1000
#pragma once


#ifdef WIN32
#include <WinSock2.h>
#include <io.h>
#pragma comment(lib,"Ws2_32.lib")
#endif

#ifdef LINUX
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inter.h>
#endif

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#endif
#endif
