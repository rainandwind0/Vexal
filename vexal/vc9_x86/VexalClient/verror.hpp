/*
 * verror Header
 */
#ifndef VERROR_H__
#define VERROR_H__

namespace vexal
{
	/**
	 * Sets the Vexal Error long
	 */
	void __stdcall SetVError(long err);

	/**
	 * Retrieves and clears the last VError
	 */
	long __stdcall GetLastVError();

	/**
	 * Retrieves and optionally clears the last VError
	 */
	long __stdcall GetLastVError(bool clear);
}


#endif