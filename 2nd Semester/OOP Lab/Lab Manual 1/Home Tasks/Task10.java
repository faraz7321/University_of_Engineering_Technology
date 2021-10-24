import java.util.Scanner;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.Period;
import java.util.Calendar;
import java.util.Date;

public class Task10 {// age Calculator.//

    // Function to calculate age in years.//
    public static int age(String dateOfBirth) throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date date = sdf.parse(dateOfBirth);
        Calendar c = Calendar.getInstance();
        c.setTime(date);
        int year = c.get(Calendar.YEAR);
        int month = c.get(Calendar.MONTH) + 1;
        int date1 = c.get(Calendar.DATE);
        LocalDate l1 = LocalDate.of(year, month, date1);
        LocalDate now1 = LocalDate.now();
        Period diff1 = Period.between(l1, now1);
        int age = diff1.getYears();
        return age;
    }

    public static void main(String[] args) throws ParseException {

        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter DOB (DD/MM/YYYY) :");
        String dateOfBirth = scanner.nextLine();
        scanner.close();
        System.out.println("Your Age: " + age(dateOfBirth) + " years");
    }
}