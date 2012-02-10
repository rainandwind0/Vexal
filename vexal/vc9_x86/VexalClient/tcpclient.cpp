/*
 * TCPClient                                                            
 */

#include "defs.hpp"
#include "logger.hpp"
#include "tcpclient.hpp"

#if defined(VWIN32)
#include <winsock2.h>

#elif defined(VLINUX)
#endif

namespace vexal
{
	TCPClient::TCPClient()
	{
#if defined(VWIN32)
		// Log
		f1("Starting TCP connection");

		// Start up WSA
		int result = WSAStartup(MAKEWORD(2,2), &_wsa);
		switch (result)
		{
		case WSASYSNOTREADY:
			e("The underlying network subsystem is not ready for network communication.");
			return;
		case WSAVERNOTSUPPORTED:
			e("The version of Windows Sockets support requested is not provided by this particular Windows Sockets implementation.");
			return;
		case WSAEINPROGRESS:
			e("A blocking Windows Sockets 1.1 operation is in progress.");
			return;
		case WSAEPROCLIM:
			e("A limit on the number of tasks supported by the Windows Sockets implementation has been reached.");
			return;
		case WSAEFAULT:
			e("The lpWSAData parameter is not a valid pointer.");
			return;
		}

		// Create/store SOCKET object
		_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Check for error & log if necessary
		if(_sock == INVALID_SOCKET)
		{
			switch(WSAGetLastError()){
		case WSANOTINITIALISED:
			e("A successful WSAStartup call must occur before using this function.");
			return;
		case WSAENETDOWN:
			e("The network subsystem or the associated service provider has failed.");
			return;
		case WSAEAFNOSUPPORT:
			e("The specified address family is not supported. For example, an application tried to create a socket for the AF_IRDA address family but an infrared adapter and device driver is not installed on the local computer.");
			return;
		case WSAEINPROGRESS:
			e("A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");
			return;
		case WSAEMFILE:
			e("No more socket descriptors are available.");
			return;
		case WSAEINVAL:
			e("An invalid argument was supplied. This error is returned if the af parameter is set to AF_UNSPEC and the type and protocol parameter are unspecified.");
			return;
		case WSAENOBUFS:
			e("No buffer space is available. The socket cannot be created.");
			return;
		case WSAEPROTONOSUPPORT:
			e("The specified protocol is not supported.");
			return;
		case WSAEPROTOTYPE:
			e("The specified protocol is the wrong type for this socket.");
			return;
		case WSAEPROVIDERFAILEDINIT:
			e("The service provider failed to initialize. This error is returned if a layered service provider (LSP) or namespace provider was improperly installed or the provider fails to operate correctly.");
			return;
		case WSAESOCKTNOSUPPORT:
			e("The specified socket type is not supported in this address family.");
			return;
			}
		}

		// Create sockaddr_in* object
		sockaddr_in sin;
		sin.sin_addr.S_un.S_addr = inet_addr("192.168.0.8");
		sin.sin_family = AF_INET;
		sin.sin_port = htons(1127);

		// Attempt to connect
		result = connect(_sock, (SOCKADDR*) &sin, sizeof(sin));

		// Check connect outcome and log/return if necessary
		switch(WSAGetLastError())
		{
		case WSANOTINITIALISED:
			e("A successful WSAStartup call must occur before using this function.");
			return;
		case WSAENETDOWN:
			e("The network subsystem has failed.");
			return;
		case WSAEADDRINUSE:
			e("The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs when executing bind, but could be delayed until the connect function if the bind was to a wildcard address (INADDR_ANY or in6addr_any) for the local IP address. A specific address needs to be implicitly bound by the connect function.");
			return;
		case WSAEINTR:
			e("The blocking Windows Socket 1.1 call was canceled through WSACancelBlockingCall.");
			return;
		case WSAEINPROGRESS:
			e("A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");
			return;
		case WSAEALREADY:
			e("A nonblocking connect call is in progress on the specified socket. Note  In order to preserve backward compatibility, this error is reported as WSAEINVAL to Windows Sockets 1.1 applications that link to either Winsock.dll or Wsock32.dll.");
			return;
		case WSAEADDRNOTAVAIL:
			e("The remote address is not a valid address (such as INADDR_ANY or in6addr_any) .");
			return;
		case WSAEAFNOSUPPORT:
			e("Addresses in the specified family cannot be used with this socket.");
			return;
		case WSAECONNREFUSED:
			e("The attempt to connect was forcefully rejected.");
			return;
		case WSAEFAULT:
			e("The sockaddr structure pointed to by the name contains incorrect address format for the associated address family or the namelen parameter is too small. This error is also returned if the sockaddr structure pointed to by the name parameter with a length specified in the namelen parameter is not in a valid part of the user address space.");
			return;
		case WSAEINVAL:
			e("The parameter s is a listening socket.");
			return;
		case WSAEISCONN:
			e("The socket is already connected (connection-oriented sockets only).");
			return;
		case WSAENETUNREACH:
			e("The network cannot be reached from this host at this time.");
			return;
		case WSAEHOSTUNREACH:
			e("A socket operation was attempted to an unreachable host.");
			return;
		case WSAENOBUFS:
			e("Note  No buffer space is available. The socket cannot be connected.");
			return;
		case WSAENOTSOCK:
			e("The descriptor specified in the s parameter is not a socket.");
			return;
		case WSAETIMEDOUT:
			e("An attempt to connect timed out without establishing a connection.");
			return;
		case WSAEWOULDBLOCK:
			e("The socket is marked as nonblocking and the connection cannot be completed immediately.");
			return;
		case WSAEACCES:
			e("An attempt to connect a datagram socket to broadcast address failed because setsockopt option SO_BROADCAST is not enabled.");
			return;
		}
#elif defined(VLINUX)

#endif
		// Log that we've connected!
		i("Client Connected!");
	}


	TCPClient::~TCPClient()
	{
#if defined(VWIN32)
		// Shutdown socket
		shutdown(_sock, SD_BOTH);

		// Cleanup WSA
		WSACleanup();
#elif defined(VLINUX)

#endif
	}
}