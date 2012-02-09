/**
 * 
 */
package net.vexal.tool.mapchecksum;

import org.fusesource.jansi.AnsiConsole;



/**
 * @author Qix
 *
 */
public class Log {

	public void postStatus(String msg)
	{
		AnsiConsole.out.print("\u001b[0m" + msg + " ");
	}
	
	public void postSuccess()
	{
		AnsiConsole.out.println("[ \u001b[1m\u001b[32mPASS\u001b[0m ]");
	}
	
	public void postFailure()
	{
		AnsiConsole.out.println("[ \u001b[1m\u001b[31mFAIL\u001b[0m ]");
		System.exit(1);
	}
}
