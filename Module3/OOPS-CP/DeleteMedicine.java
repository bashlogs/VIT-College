import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class DeleteMedicine extends JFrame implements ActionListener
{
	JFrame jf;
	JLabel b;
	ImageIcon img;
	JTextField t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	JLabel l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,ln;
    JButton b0,b1,b2,b3;
	Font f;
    Connection con;
	PreparedStatement ps;
	Statement stmt;
	ResultSet rs;
	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);

	DeleteMedicine()
	{
		jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
		f = new Font("Arial",Font.BOLD,20);
		b.setLayout(null);

	    ln=new JLabel(" Delete Medicine ");
	    ln.setFont(new Font("Arial",Font.BOLD,25));
	    ln.setForeground(Color.BLACK);
	    ln.setHorizontalAlignment(JLabel.CENTER);
		ln.setBounds(0,30,900,40);ln.setForeground(Color.black);
	    b.add(ln);

		l1 = new JLabel("Medicine Batch no*");
		//l1.setFont(f);
        l1.setBounds(30,100,200,25);l1.setForeground(Color.BLACK);
		l1.setFont(new Font("Arial",Font.PLAIN,20));
		b.add(l1);

		t1 = new JTextField(20);
		t1.setBounds(250,100,170,25);t1.setToolTipText("Enter medicine batch no to delete medicine");
		t1.setFont(new Font("Arial",Font.PLAIN,15));b.add(t1);t1.setForeground(Color.black);

		l2 = new JLabel("Medicine name*");
		//l2.setFont(f);
  l2.setBounds(30,140,200,25);l2.setForeground(Color.BLACK);
  l2.setFont(new Font("Arial",Font.PLAIN,20));

		b.add(l2);

    	t2 = new JTextField(20);
		t2.setBounds(250,140,170,25);t2.setToolTipText("Enter medicine name to delete medicine");
		t2.setFont(new Font("Arial",Font.PLAIN,15));b.add(t2);t2.setForeground(Color.black);

		l3 = new JLabel("Medicine company: ");
		//l3.setFont(f);
  l3.setBounds(30,180,200,25);l3.setForeground(Color.BLACK);
  l3.setFont(new Font("Arial",Font.PLAIN,20));
		b.add(l3);

     	t3 = new JTextField(20);
		t3.setBounds(250,180,170,25);t3.setForeground(Color.black);
		t3.setFont(new Font("Arial",Font.PLAIN,15));b.add(t3);

		l4 = new JLabel("Medicine quantity: ");
		//l4.setFont(f);
l4.setBounds(30,220,200,25);l4.setForeground(Color.BLACK);
l4.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l4);

        t4= new JTextField(20);
		t4.setBounds(250,220,170,25);
		t4.setFont(new Font("Arial",Font.PLAIN,15));
		b.add(t4);t4.setForeground(Color.black);

		l5= new JLabel("Med expiry date: ");
		//l5.setFont(f);
l5.setBounds(30,260,250,25);l5.setForeground(Color.BLACK);
l5.setFont(new Font("Arial",Font.PLAIN,20));
		b.add(l5);

	    t5= new JTextField(20);
		t5.setBounds(250,260,170,25);
		t5.setFont(new Font("Arial",Font.PLAIN,15));b.add(t5);t5.setForeground(Color.black);

		l6= new JLabel("Med purchase date: ");
		//l6.setFont(f);
    l6.setBounds(30,300,250,25);l6.setForeground(Color.BLACK);
	l6.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l6);

        t6= new JTextField(20);
		t6.setBounds(250,300,170,25);
		t6.setFont(new Font("Arial",Font.PLAIN,15));b.add(t6);t6.setForeground(Color.black);

		l7 = new JLabel("Medicine type: ");
		//l7.setFont(f);
    l7.setBounds(470,100,200,25);
	l7.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l7);l7.setForeground(Color.BLACK);

        t7 = new JTextField(20);
		t7.setBounds(720,100,170,25);
		t7.setFont(new Font("Arial",Font.PLAIN,15));b.add(t7);t7.setForeground(Color.black);

		l8= new JLabel("Medicine purchase price: ");
		//l8.setFont(f);
    l8.setBounds(470,140,240,25);
	l8.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l8);l8.setForeground(Color.BLACK);

        t8 = new JTextField(20);
		t8.setBounds(720,140,170,25);
		t8.setFont(new Font("Arial",Font.PLAIN,15));b.add(t8);t8.setForeground(Color.black);

		l9 = new JLabel("Medicine sale price: ");
		//l9.setFont(f);
  l9.setBounds(470,180,200,25);
  l9.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l9);l9.setForeground(Color.BLACK);

        t9 = new JTextField(20);
		t9.setBounds(720,180,170,25);
		t9.setFont(new Font("Arial",Font.PLAIN,15));b.add(t9);t9.setForeground(Color.black);

		l10 = new JLabel("Medicine rack no: ");
		//l10.setFont(f);
  	l10.setBounds(470,220,200,25);
		l10.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l10);l10.setForeground(Color.BLACK);

        t10 = new JTextField(20);
		t10.setBounds(720,220,170,25);t10.setFont(new Font("Arial",Font.PLAIN,15));
		b.add(t10);t10.setForeground(Color.black);

		l11 = new JLabel("Supplier name: ");
		//l11.setFont(f);
   l11.setBounds(470,260,180,25);
   l11.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l11);l11.setForeground(Color.BLACK);

        t11 = new JTextField(20);
	   	t11.setBounds(720,260,170,25);
		t11.setFont(new Font("Arial",Font.PLAIN,15));
	   	b.add(t11);t11.setForeground(Color.black);

	   	l12 = new JLabel("Supplier id: ");
		//l12.setFont(f);
       l12.setBounds(470,300,180,25);
	   l12.setFont(new Font("Arial",Font.PLAIN,20));
    	b.add(l12);l12.setForeground(Color.BLACK);

    	t12 = new JTextField(20);
	    t12.setBounds(720,300,170,25);
		t12.setFont(new Font("Arial",Font.PLAIN,15));
	    b.add(t12);t12.setForeground(Color.black);

        b0 = new JButton("Open",new ImageIcon("images//open.png"));
        b0.setBounds(150,350,110,35);b0.setToolTipText("click to open medicine details");
		b.add(b0);b0.addActionListener(this);

		b1 = new JButton("Delete",new ImageIcon("images//delete.png"));
		b1.setBounds(300,350,110,35);b1.setToolTipText("click to delete medicine details");
	    b.add(b1); b1.addActionListener(this);

        b2= new JButton("Clear",new ImageIcon("images//clear.png"));
		b2.setBounds(450,350,110,35);b2.setToolTipText("click to clear all textfields");
		b.add(b2); b2.addActionListener(this);

    	b3 = new JButton("All",new ImageIcon("images//all.png"));//if button is press then record display repeat
		b3.setBounds(600,350,110,35);b3.setToolTipText("click to view all medicine details");
		b.add(b3); b3.addActionListener(this);

	    scrlPane.setBounds(0,400,920,600);
        b.add(scrlPane);
        tabGrid.setFont(new Font ("Arial",0,15));

        model.addColumn("M_BNO");
        model.addColumn("M_NAME");
        model.addColumn("M_COMPANY");
        model.addColumn("M_QUANTITY");
        model.addColumn("M_EXPDATE");
        model.addColumn("M_PURDATE");
        model.addColumn("M_TYPE");
        model.addColumn("M_SALEPRICE");
        model.addColumn("M_PURPRICE");
        model.addColumn("M_RACKNO");
        model.addColumn("M_SID");
        model.addColumn("M_SNAME");

	     jf.setTitle("Delete Medicine ");
	     jf.setSize(920,700);
		 jf.setLocation(20,20);
		 jf.setResizable(false);		
	     jf.setVisible(true);
 }

public void actionPerformed(ActionEvent ae)
{
    if(ae.getSource()==b0)
	  {
	  	try
	  	{
	  	 if(((t1.getText()).equals(""))&&((t2.getText()).equals("")))
	        {
		    JOptionPane.showMessageDialog(this,"Please enter medicine bno or name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else
	        {
	         int foundrec = 0;

	    Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");

		  ps=con.prepareStatement("select * from medicine where mname='"+ t2.getText()+"' or mbno='"+t1.getText()+"'");
		  rs=ps.executeQuery();
		  while(rs.next())
	      {
		    t1.setText(rs.getString(1));
	        t2.setText(rs.getString(2));
	        t3.setText(rs.getString(3));
	        t4.setText(rs.getString(4));
		    t5.setText(rs.getString(5));
		    t6.setText(rs.getString(6));
	        t7.setText(rs.getString(7));
	        t8.setText(rs.getString(8));
	        t9.setText(rs.getString(9));
		    t10.setText(rs.getString(10));
		    t12.setText(rs.getString(11));
		    t11.setText(rs.getString(12));
		     foundrec = 1;
	       }
	        if (foundrec == 0)
                {
                    JOptionPane.showMessageDialog(null,"Record is not available","Dialog",JOptionPane.WARNING_MESSAGE);
                }
	         }
	         con.close();
        }
      catch(SQLException se)
		{
	      System.out.println(se);
	     JOptionPane.showMessageDialog(null,"SQL Error."+se);
        }
	    catch(Exception e)
	     {
	     System.out.println(e);
		 JOptionPane.showMessageDialog(null,"Error."+e);
	     }
    }
  else if(ae.getSource()==b1)
	 {//delete
	 	if(((t1.getText()).equals(""))&&((t2.getText()).equals("")))
	     {
		  JOptionPane.showMessageDialog(this,"Please enter medicin batchno or name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	      }
	      else
	      {
	      try
	       {
	    Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
	    ps=con.prepareStatement("delete from medicine where mbno='"+t1.getText()+"' or mname='"+t2.getText()+"'");
	    ps.executeUpdate();
        JOptionPane.showMessageDialog(null,"Record is deleted.");
        t1.setText("");
        t2.setText("");
        t3.setText("");
        t4.setText("");
        t5.setText("");
        t6.setText("");
        t7.setText("");
        t8.setText("");
        t9.setText("");
        t10.setText("");
        t11.setText("");
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

        else if(ae.getSource()==b2)
           {
                t1.setText("");
                t2.setText("");
                t3.setText("");
                t4.setText("");
                t5.setText("");
                t6.setText("");
			    t7.setText("");
			    t8.setText("");
                t9.setText("");
                t10.setText("");
                t11.setText("");
                t12.setText("");
            }
   else if(ae.getSource()==b3)
    {//list
  	int r = 0;
     try
     {
         Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("SELECT * from medicine" );
          while(rs.next())
            {
model.insertRow(r++, new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6),rs.getString(7),rs.getString(8),rs.getString(9),rs.getString(10),rs.getString(11),rs.getString(12) });
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
  	}
  }

 public static void main(String args[])
	{
	  new DeleteMedicine();
	}
}

