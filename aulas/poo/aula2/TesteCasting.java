
//Aprendendo sobre casting em java

public class TesteCasting {
	public static void main (String[] args) {
		
		long a = 2047; //64 bits
		double b = 0.00000000000000000000000001;

		int a1 = (int) a; //32 bits
		short b1 = (short) a1; //16 bits
		byte c1 = (byte) a1; // 8 bits

		System.out.println(a1); // conversão long to int | perda = 32bits
		System.out.println(b1); // conversão int to short | perda = 16bits
		System.out.println(c1); // conversão short to byte | perda = 8bits

		float a2 = (float) b; // 32 bits
		double a3 = (double) a; // 64 bits
		
		System.out.println(a2);
		System.out.println(a3);
	}
}