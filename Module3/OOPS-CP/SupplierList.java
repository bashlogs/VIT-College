import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class SupplierList extends JFrame
 {
    JFrame jf=new JFrame();
	JLabel b;
	ImageIcon img;
    JLabel ln;
    Connection con;
    PreparedStatement ps;
    Statement stmt;
    ResultSet rs;
 	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);

  public SupplierList()
  {     
    jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
    b.setLayout(null);
  	ln = new JLabel("List Of Supplier Details");
    ln.setFont(new Font("Arial",Font.BOLD,25));
    ln.setForeground(Color.WHITE);
    ln.setHorizontalAlignment(JLabel.CENTER);
	  ln.setBounds(0,50,900,40);ln.setForeground(Color.black);
    b.add(ln);

    scrlPane.setBounds(0,150,920,600);
    b.add(scrlPane);
    tabGrid.setFont(new Font ("Arial",0,15));

   	model.addColumn("S_ID");
   	model.addColumn("S_NAME");
  	model.addColumn("S_Address");
  	model.addColumn("S_PhNo");
  	model.addColumn("S_EmailId");

  		int r = 0;
     try
     {

     	Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("select * from supplier");
          while(rs.next())
            {
            	model.insertRow(r++,new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5)});

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


    jf.setTitle("Supplier List");
    jf.setSize(920,700);
	jf.setLocation(20,20);
	jf.setResizable(false);
   
    jf.setVisible(true);
  }


  public static void main(String args[])
    {
    	new SupplierList();
    }
}
