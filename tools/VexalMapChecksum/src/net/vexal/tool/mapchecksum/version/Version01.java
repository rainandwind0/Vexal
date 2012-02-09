/**
 * 
 */
package net.vexal.tool.mapchecksum.version;

import net.vexal.tool.mapchecksum.MVersion;

/**
 * @author Qix
 *
 */
public class Version01 extends MVersion {

	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	@Override
	public void run() {
		System.out.println("Starting Version01 scan on world " + world + "!");

	}

	/* (non-Javadoc)
	 * @see net.vexal.tool.mapchecksum.iMappable#getVersion()
	 */
	@Override
	public String getVersion() {
		return "v0.1";
	}

}
