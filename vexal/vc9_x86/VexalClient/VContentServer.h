/*
 * VContentServer Header
 */
#ifndef VCONTENTSERVER_H__
#define VCONTENTSERVER_H__

namespace vexal
{
	class VContentServer
	{
	public:
		/*
		 * Returns the singleton instance of the content server
		 */
		VContentServer get();

		/**
		 * Returns whether or not the content is being served from online
		 */
		bool online();


	protected:
		static VContentServer* inst;
		VContentServer();
	private:
	};
}

#endif