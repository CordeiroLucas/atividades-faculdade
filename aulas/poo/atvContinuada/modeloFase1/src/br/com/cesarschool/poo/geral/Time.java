package br.com.cesarschool.poo.geral;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.concurrent.TimeUnit;

// public class Time {
// 	public static void main(String[] args) throws ParseException {  
// 		SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
// 		Date firstDate = sdf.parse("06/10/2022");
// 		Date secondDate = sdf.parse("06/11/2022");

// 		long diffInMillies = Math.abs(secondDate.getTime() - firstDate.getTime());
// 		long diff = TimeUnit.DAYS.convert(diffInMillies, TimeUnit.MILLISECONDS);

// 		System.out.printf("Diferença = %d\n", diff);
// 	}
// }

public class Time {
	public static void main(String[] args) throws ParseException {
	
		SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy", Locale.ENGLISH);
		Date firstDate = sdf.parse("06/24/2017");
		Date secondDate = sdf.parse("06/30/2017");

		long diffInMillies = Math.abs(secondDate.getTime() - firstDate.getTime());
		long diff = TimeUnit.DAYS.convert(diffInMillies, TimeUnit.MILLISECONDS);

		System.out.printf("Diferença = %d\n", diff);
	}
}