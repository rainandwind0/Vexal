/**
 * 
 */
package net.vexal.tool.mapchecksum;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import org.fusesource.jansi.Ansi;
import org.fusesource.jansi.AnsiConsole;
import org.fusesource.jansi.AnsiOutputStream;




/**
 * @author Qix
 *
 */
public class Main {

	public static Log log = new Log();
	private String[] _args;
	
	public Main(String[] aargs)
	{
		_args = aargs;
	}
	
	public String getNameFromCMD()
	{
		return _args[0];
	}
	
	public byte[] getBytesFromCMD()
	{
		File f = new File(getNameFromCMD() + "/mp.d");
		if(!f.exists())
		{
			System.out.println("ERROR! World file does NOT exist, or is missing map descriptor file!!");
			System.exit(1);
		}
		
		
		
		try {
			FileInputStream fis = new FileInputStream(f);
			
			byte[] buf = new byte[2048];
			fis.read(buf);
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		
		
		
		return new byte[2];
	}
	
	public void run()
	{	
		// Install STDOUT
		AnsiConsole.systemInstall();
		
		// Get bytes
		byte[] bts = getBytesFromCMD();
		
		// Trigger start of scan
		//MapVersions.getByBytes(new byte[]{0, 1}).getNewInstance().setWorld("test").run();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// Create new class instance
		new Main(args).run();
	}

}
