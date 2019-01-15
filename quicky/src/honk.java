
public class honk {

	private static boolean f1(boolean a, boolean b, boolean c, boolean d) {
		return (a && b && c) || (a && !b && c && d) || (a && !b && c && !d) || (a && !b && !c && !d) || (!a && b && c && d) || (!a && b && c && !d) || (!a && !b && !c && !d) || (!a && !b && c) || (a && b && !c && d) || (a && b && !c && !d);
	}

	private static boolean f2(boolean a, boolean b, boolean c, boolean d) {
		return (!b && !d) || c || (a && b);
	}

	public static void main(String args[]) {

		for(int m = 0; m < 2; m ++) {

			boolean a;
			if (m == 0) a = true;
			else a = false;

			for(int n = 0; n < 2; n ++) {

				boolean b;
				if (n == 0) b = true;
				else b = false;

				for(int x = 0; x < 2; x ++) {

					boolean c;
					if (x == 0) c = true;
					else c = false;

					for(int y = 0; y < 2; y ++) {

						boolean d;
						if (y == 0) d = true;
						else d = false;


						System.out.println("f1 a:"+m+" b:"+n+" c:"+x+" d:"+y+"   "+ f1(a,b,c,d));
						System.out.println("f2 a:"+m+" b:"+n+" c:"+x+" d:"+y+"   "+ f2(a,b,c,d));


						System.out.println();

					}
				}
			}

		}
	}
}
