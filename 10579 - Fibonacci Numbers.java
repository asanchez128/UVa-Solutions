
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		BigInteger bg[] = new BigInteger[5001];
		bg[0] = BigInteger.ZERO;
		bg[1] = BigInteger.ONE;
		
		for(int i = 2; i < 5001; ++i) {
			bg[i] = bg[i - 1].add(bg[i - 2]);			
		}
		
		Scanner sc = new Scanner (System.in);
		while(sc.hasNext()){
			int i = sc.nextInt();
			System.out.println(bg[i]);
		}
	}
}
