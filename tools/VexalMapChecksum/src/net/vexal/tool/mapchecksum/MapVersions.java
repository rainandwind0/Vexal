/**
 * 
 */
package net.vexal.tool.mapchecksum;

import net.vexal.tool.mapchecksum.version.Version01;

/**
 * @author Qix
 *
 */
public enum MapVersions {

	V01(new byte[]{0,1}, Version01.class);
	
	private byte[] _mask;
	private Class<MVersion> _cls;
	
	MapVersions(byte[] mask, @SuppressWarnings("rawtypes") Class cls)
	{
		_mask = mask;
		_cls = cls;
	}
	
	public static MapVersions getByBytes(byte[] b)
	{
		for(MapVersions m : values())
		{
			if(m._mask[0] == b[0] && m._mask[1] == b[1])
				return m;
		}
		
		System.out.println("\n\nERROR: No map version implemented! Out of date vexal checksummer?");
		System.exit(1);
		return null;
	}
	
	public MVersion getNewInstance()
	{
		try {
			return _cls.newInstance();
		} catch (InstantiationException e) {
			e.printStackTrace();
			System.exit(1);
		} catch (IllegalAccessException e) {
			e.printStackTrace();
			System.exit(1);
		}
		
		return null;
	}
}
