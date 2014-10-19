import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main{
	
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		BigInteger a = s.nextBigInteger();
		BigInteger b = s.nextBigInteger();
		List<BigInteger> fibs = new ArrayList<BigInteger>();

		fibs.add(BigInteger.ONE);
		fibs.add(new BigInteger("2"));
		
		for(int i = 2; i <= 500; ++i){
			fibs.add(new BigInteger(fibs.get(i - 2).toString()).add(fibs.get(i - 1)));
		}
		while(a.compareTo(BigInteger.ZERO) != 0  || b.compareTo(BigInteger.ZERO) != 0){
			int i = 0;
			int ant = 0;
			while(fibs.get(i).compareTo(b) <= 0){
				if(fibs.get(i).compareTo(a) >= 0){
					++ant;
				}
				++i;
			}
			System.out.println(ant);
			a = s.nextBigInteger();
			b = s.nextBigInteger();
		} 
		
		
		
	}
}