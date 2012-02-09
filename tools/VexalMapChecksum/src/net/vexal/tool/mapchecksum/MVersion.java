package net.vexal.tool.mapchecksum;

public abstract class MVersion implements iMappable {

	protected String world;
	
	public MVersion setWorld(String w)
	{
		world = w;
		return this;
	}
	
}
