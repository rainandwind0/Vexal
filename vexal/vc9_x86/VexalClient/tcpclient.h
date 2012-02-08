/*
 * TCPClient Header                                                     
 */

#include <winsock2.h>

namespace vexal
{
	class TCPClient 
	{
	public:
		TCPClient();
		~TCPClient();
	private:
		SOCKET _sock;
		WSADATA _wsa;
	};
}