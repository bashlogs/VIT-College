import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class AddNewSupplier extends JFrame implements ActionListener
{
	JFrame jf;
	JLabel b;
	ImageIcon img;
	JTextField t1,t2,t4,t5,tr,tq;
	JTextArea t3,tin;
	JScrollPane tout;
	JLabel l1,l2,l3,l4,l5,l6;
	JButton b0,b1,b2;
	Font f;
    Connection con;
	PreparedStatement ps;
	Statement stmt;
	ResultSet rs;
	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);
	String id, name, phone_no, email_id, address,data="";
	AddNewSupplier()
	{
		jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
		f = new Font("Times New Roman",Font.BOLD,22);
		b.setLayout(null);

	    l6=new JLabel("New Supplier details");
	    l6.setFont(new Font("Times New Roman",Font.BOLD,25));
		l6.setHorizontalAlignment(JLabel.CENTER);
	    l6.setBounds(25,50,800,40);l6.setForeground(Color.black);
	    b.add(l6);

	//	l1= new JLabel("Supplier id ");
	//	l1.setFont(f);l1.setBounds(150,122,130,25);
	//	jf.add(l1);

	//	t1=new JTextField(22);t1.setEditable(false);
	//	t1.setBounds(322,122,100,25);
	//	jf.add(t1);

		l2 = new JLabel("Supplier name: ");
		l2.setFont(new Font("Arial", Font.PLAIN, 20));
        l2.setBounds(40,160,170,25);
		l2.setForeground(Color.black);
		b.add(l2);

		l4 = new JLabel("Supplier phone no: ");
		l4.setFont(new Font("Arial", Font.PLAIN, 20));
        l4.setBounds(40,240,170,25);
		b.add(l4);l4.setForeground(Color.black);

		l5 = new JLabel("Supplier email id: ");
		l5.setFont(new Font("Arial", Font.PLAIN, 20));
        l5.setBounds(40,200,170,25);
		b.add(l5);l5.setForeground(Color.black);

		l3 = new JLabel("Supplier address: ");
		l3.setFont(new Font("Arial", Font.PLAIN, 20));
        l3.setBounds(40,280,170,25);
		b.add(l3);l3.setForeground(Color.black);

		t2=new JTextField(22);
		t2.setBounds(240,160,250,25);t2.setToolTipText("Enter supplier name");
		t2.setFont(new Font("Arial",Font.PLAIN,15));b.add(t2);t2.setForeground(Color.black);

		//t3=new JTextField(22);
		//t3.setBounds(240,200,250,25);t3.setToolTipText("Enter supplier address");
		//t3.setFont(new Font("Arial", Font.PLAIN, 25));b.add(t3);t3.setForeground(Color.black);

		t4=new JTextField(22);
		t4.setBounds(240,240,250,25);t4.setToolTipText("Enter supplier phone no");
		t4.setFont(new Font("Arial", Font.PLAIN, 15));b.add(t4);t4.setForeground(Color.black);

		t5=new JTextField(22);
		t5.setSize(100, 100);
		t5.setBounds(240,200,250,25);t5.setToolTipText("Enter supplier email id");
		t5.setFont(new Font("Arial", Font.PLAIN, 15));b.add(t5);t5.setForeground(Color.black);

	
	    b0 = new JButton("Save",new ImageIcon("images//save.png"));
		b0.setBounds(240,400,110,35);
        b0.setToolTipText("click to save supplier details");
		b.add(b0);b0.addActionListener(this);

		//b0.setBounds(40,330,110,35);
		b1 = new JButton("Clear",new ImageIcon("images//clear.png"));
		b1.setBounds(40,400,110,35);
		b1.setToolTipText("click to clear all textfilds");
	    b.add(b1); b1.addActionListener(this);

        b2= new JButton("Data",new ImageIcon("images//all.png"));
		b2.setBounds(380,400,110,35);b2.setToolTipText("click to view all supplier details");
		b.add(b2); b2.addActionListener(this);

		t3=new JTextArea(2,1);
		t3.setSize(10,10);
		t3.setPreferredSize(new Dimension(80,80));
		t3.setLineWrap(true);
		t3.setBounds(240,280,250,100);t3.setToolTipText("Enter supplier address");
		t3.setFont(new Font("Arial", Font.PLAIN, 15));b.add(t3);t3.setForeground(Color.black);


		tin = new JTextArea();
		tin.setEditable(false);
		tin.setFont(new Font("Arial", Font.PLAIN, 14));
		tout = new JScrollPane(tin);
        //tout.setFont(new Font("Arial", Font.PLAIN, 17));
        tout.setSize(300, 400);
        tout.setLocation(550, 160);
        // tout.setLineWrap(true);
        // tout.setEditable(false);
        b.add(tout);

	    scrlPane.setBounds(0,380,900,600);
        //b.add(scrlPane);
        tabGrid.setFont(new Font ("Times New Roman",0,15));

        model.addColumn("S_ID");
        model.addColumn("S_NAME");
        model.addColumn("S_ADDRESS");
        model.addColumn("S_PHONENO");
        model.addColumn("S_EMAILID");

	     jf.setTitle("Add New Supplier");
	     jf.setSize(900,700);
		 jf.setLocation(22,22);
		 jf.setResizable(false);
		
	     jf.setVisible(true);
	}

public void actionPerformed(ActionEvent ae)
	{
	if(ae.getSource()==b0)
	 {
	 	    String mob = t4.getText();
	       	String email=t5.getText();
	       	Pattern p=Pattern.compile("[_a-z_A-Z_0-9]+[0-9]*@[a-zA-Z0-9]+.[a-zA-Z0-9]+");
	       	Matcher m=p.matcher(email);
	        boolean matchFound=m.matches();

	    	if(((t2.getText()).equals(""))||((t3.getText()).equals(""))||((t4.getText()).equals(""))||((t5.getText()).equals("")))
	        {
		    JOptionPane.showMessageDialog(this,"* Detail are Missing !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else if(!matchFound)
	        {
	       	  JOptionPane.showMessageDialog(this,"Invalid email id!","Warning!!!",JOptionPane.WARNING_MESSAGE);
	       	}
			else
			{
			  try
			  	 {
			Class.forName("com.mysql.jdbc.Driver");
		    con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
			System.out.println("Connected to database.");
            ps=con.prepareStatement("insert into supplier (sname,saddress,sphoneno,semailid)values(?,?,?,?)");
            ps.setString(1,t2.getText());
		    ps.setString(2,t3.getText());
		    ps.setString(3,t4.getText());
			ps.setString(4,t5.getText());
		  	ps.executeUpdate();

  			int reply=JOptionPane.showConfirmDialog(null,"Supplier added successfully.Do you want add more supplier?","Added Supplier",JOptionPane.YES_NO_OPTION);

	            if (reply == JOptionPane.YES_OPTION)
	   			{
	   		       jf.setVisible(false);
	   		       new AddNewSupplier();
	   		    }
	   		    else if (reply == JOptionPane.NO_OPTION)
	   			{
	   			  jf.setVisible(false);
		        }con.close();
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
 }
}
  else if(ae.getSource()==b1)
     {//clear
          //t1.setText("");
          t2.setText("");
          t3.setText("");
          t4.setText("");
          t5.setText("");
      }
    else if(ae.getSource()==b2)
    {//list
  	int r = 0;
     try
     {
         Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("select * from supplier;" );
          while(rs.next())
            {
				id = " ID: "+rs.getString(1)+"\n";
				name = " Name: " + rs.getString(2)+"\n";
				phone_no = " Phone_No: " + rs.getString(4)+"\n";
				email_id = " Email_id: " + rs.getString(5)+"\n";
				address = " Address: " + rs.getString(3)+"\n\n";
				data += (id + name + phone_no + email_id + address);
            	//model.insertRow(r++, new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5) });
            }
			tin.setText(data);
            tin.setEditable(false);
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
	}
 }
public static void main(String args[])
	{
	      new AddNewSupplier();
	}
}

