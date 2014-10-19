import java.math.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		BigInteger a;
		int inputNumber;
		List<BigInteger> fibs = new ArrayList<BigInteger>();
		fibs.add(BigInteger.ONE);
		fibs.add(new BigInteger("2"));
		for(int i = 2; i <= 1000; ++i){
			fibs.add(new BigInteger(fibs.get(i - 2).toString()).add(fibs.get(i - 1)));
		}
		
		while(s.hasNextInt()){
			inputNumber = s.nextInt();
			System.out.println(fibs.get(inputNumber));
		}
	}
}