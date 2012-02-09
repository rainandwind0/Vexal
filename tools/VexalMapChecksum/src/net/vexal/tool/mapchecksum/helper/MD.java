package net.vexal.tool.mapchecksum.helper;

public class MD {

	public static enum MapDescriptorField {
		VERSION((byte) 0x1, 2), SEED((byte) 0x2, 10), NAME((byte) 0x3, 255), CREATOR(
				(byte) 0x4, 255), CREATE_DATE((byte) 0x5, 32), TOTAL_PLAYERS(
				(byte) 0x6, 4);

		private byte _b;
		private int _len;

		MapDescriptorField(byte b, int len) {
			_b = b;
			_len = len;
		}

		public byte getByte() {
			return _b;
		}

		public int getLen() {
			return _len;
		}
	}

	public static String getMapDSPropString(byte[] inp, MapDescriptorField field) {

		return new String(getMapDSProp(inp, field)).replaceAll("\0", "");
	}

	public static byte[] getMapDSProp(byte[] inp, MapDescriptorField field) {
		// Zero array
		byte[] nb = inp.clone();
		for (int i = 0; i < nb.length; i++)
			nb[i] = 0;

		// Find placer byte
		int c = -1;
		for (int i = 0; i < nb.length; i++) {
			if (inp[i] == field.getByte()) {
				c = i;
				break;
			}
		}

		if (c == -1) {
			System.out.println("ERROR! File descriptor is CORRUPT!");
			System.exit(1);
		}

		// Get bytes
		for (int i = 0; i < field.getLen(); i++) {
			nb[i] = inp[i + c];
		}
		
		return nb;
	}

}
