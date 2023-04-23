import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.Locale;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.time.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class medicine_report extends JFrame
 {
    JFrame jf=new JFrame();
	JLabel b;
	ImageIcon img;
    JLabel ln;
    Connection con;
    Date date1;
    GregorianCalendar calendar;
    String strDate;
    PreparedStatement ps;
    Statement stmt;
    ResultSet rs;
 	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);

  public medicine_report()
  {
    jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
	b=new JLabel("",img,JLabel.CENTER);
	b.setBounds(0,0,800,600);
	jf.add(b);
	//setVisible(true);
	b.setLayout(null);
  	ln = new JLabel("Expired Medicine");
    ln.setFont(new Font("Arial",Font.BOLD,25));
    ln.setForeground(Color.BLACK);
    ln.setHorizontalAlignment(JLabel.CENTER);
		ln.setBounds(0,30,900,40);ln.setForeground(Color.black);
    b.add(ln);

    scrlPane.setBounds(0,100,920,600);
    b.add(scrlPane);
    tabGrid.setFont(new Font ("Arial",0,15));

    model.addColumn("Batchno");model.addColumn("Name");model.addColumn("Quantity");
  	model.addColumn("Type");model.addColumn("Purcahasedate");model.addColumn("Expirydate");model.addColumn("Purchaseprice");
    model.addColumn("Rackno");
  		int r = 0;
     try
     {

     	Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("select * from medicine");
        Date date1 = new Date();
        Calendar calendar = new GregorianCalendar();
        //Calendar.setTime(date1);
        String strDate = calendar.get(Calendar.MONTH)+"-"+(calendar.get(Calendar.YEAR));
        SimpleDateFormat formatter=new SimpleDateFormat("MM-yyyy");
        Date date=formatter.parse(strDate);
          while(rs.next())
            {
                String sDate1=rs.getString(5);
                Date date2=formatter.parse(sDate1);
                int result = date.compareTo(date2);
                if(result > 0) {
            	    model.insertRow(r++,new Object[]{rs.getString(1),rs.getString(2),rs.getString(4),rs.getString(7),rs.getString(6),rs.getString(5),rs.getString(8),rs.getString(10)});
                }
                else{
                    continue;
                }
            }
             con.close();
       }
      catch(SQLException se)
       {
       	  System.out.println(se);
          JOptionPane.showMessageDialog(null,"SQL Error:"+se);
       }
       catch(Exception e)
       {
       	   System.out.println(e);
           JOptionPane.showMessageDialog(null,"Error:"+e);
       }


    jf.setTitle("Medicine List");
    jf.setSize(920,700);
	jf.setLocation(20,20);
	jf.setResizable(false);
    jf.getContentPane().setBackground(Color.cyan);
    jf.setVisible(true);
  }


  public static void main(String args[])
    {
    	new medicine_report();
    }
}
