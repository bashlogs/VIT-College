import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class new1 {
public static void main(String[] args)throws Exception {
    Date date1 = new Date();
    Calendar calendar = new GregorianCalendar();
    //Calendar.setTime(date1);
    String strDate = calendar.get(Calendar.MONTH)+"-"+(calendar.get(Calendar.YEAR));
    System.out.println(strDate);
    String sDate1="12/1998";
    SimpleDateFormat formatter1=new SimpleDateFormat("MM-yyyy");
    Date date2=formatter1.parse(strDate);
    System.out.println(strDate);
    int result = date1.compareTo(date2);
	System.out.println(result);
}
}