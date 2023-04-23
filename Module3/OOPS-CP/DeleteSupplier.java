import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;


public class DeleteSupplier extends JFrame implements ActionListener
{
	
	JFrame jf;
	JLabel b;
	ImageIcon img;
	JLabel l1,l2,l3,l4,l5,l6;
	JTextField t1,t2,t3,t4,t5;
	JButton b0,b1,b2,b3;
	GridBagLayout gbl;
	GridBagConstraints gbc;
	Font f;
    Connection con;
	PreparedStatement ps;
	Statement stmt;
	ResultSet rs;
    DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);

	DeleteSupplier()
	{
		jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
		f = new Font("Arial",Font.PLAIN,20);
		b.setLayout(null);

	    l6=new JLabel(" Delete Supplier ");
	    l6.setFont(new Font("Arial",Font.BOLD,25));
	    l6.setHorizontalAlignment(JLabel.CENTER);
	    l6.setBounds(0,50,900,40);l6.setForeground(Color.black);
	    b.add(l6);

		l1= new JLabel("Supplier Id: ");
		//l1.setFont(f);
		l1.setFont(new Font("Arial",Font.PLAIN,20));
 l1.setBounds(250,120,130,25);l1.setForeground(Color.black);
		b.add(l1);

		t1=new JTextField(20);
		t1.setBounds(490,120,170,25);t1.setToolTipText("Enter supplier id to delete supplier");
		 t1.setFont(new Font("Arial",Font.PLAIN,15));
		 t1.setForeground(Color.black);
		b.add(t1);

		l2 = new JLabel("Supplier Name: ");
		//l2.setFont(f);
		l2.setFont(new Font("Arial",Font.PLAIN,20));
  l2.setBounds(250,160,170,25);l2.setForeground(Color.black);
		b.add(l2);

		t2=new JTextField(20);
		t2.setBounds(490,160,170,25);t2.setToolTipText("Enter supplier name to delete supplier");
		 t2.setFont(new Font("Arial",Font.PLAIN,15));
		 t2.setForeground(Color.black);
		b.add(t2);

		l3 = new JLabel("Supplier Address: ");
		//l3.setFont(f);
		l3.setFont(new Font("Arial",Font.PLAIN,20));
    l3.setBounds(250,200,170,25);l3.setForeground(Color.black);
		b.add(l3);

		t3=new JTextField(20);
		t3.setBounds(490,200,170,25);b.add(t3);
         t3.setFont(new Font("Arial",Font.PLAIN,15));
		 t3.setForeground(Color.black);
		 
		l4 = new JLabel("Supplier Phone No: ");
		l4.setFont(f);l4.setForeground(Color.black);
   	l4.setBounds(250,240,200,25);
		b.add(l4);

		t4=new JTextField(20);
		t4.setBounds(490,240,170,25);b.add(t4);
         t4.setFont(new Font("Arial",Font.PLAIN,15));
		 t4.setForeground(Color.black);
		l5 = new JLabel("Supplier Email Id: ");
		l5.setFont(f);l5.setForeground(Color.black);
   l5.setBounds(250,280,170,25);
		b.add(l5);

		t5=new JTextField(20);
		t5.setBounds(490,280,170,25);b.add(t5);
         t5.setFont(new Font("Arial",Font.PLAIN,15));
		 t5.setForeground(Color.black);
		 b0 = new JButton("Open",new ImageIcon("images//open.png"));
		 b0.setBounds(180,330,100,35);b0.setToolTipText("click to open supplier details");
	     b.add(b0); b0.addActionListener(this);

	     b1 = new JButton("Delete",new ImageIcon("images//delete.png"));
		 b1.setBounds(330,330,120,35);b1.setToolTipText("click to delete supplier details");
		 b.add(b1);b1.addActionListener(this);

		 b2 = new JButton("Clear",new ImageIcon("images//clear.png"));
		 b2.setBounds(480,330,100,35);b2.setToolTipText("click to clear all textfields");
		 b.add(b2); b2.addActionListener(this);

     	b3 = new JButton("All",new ImageIcon("images//all.png"));
		b3.setBounds(630,330,100,35);b3.setToolTipText("click to view all supplier details");
		b.add(b3); b3.addActionListener(this);

      scrlPane.setBounds(0,380,920,600);
      b.add(scrlPane);
      tabGrid.setFont(new Font ("Arial",0,15));

      model.addColumn("S_ID");
      model.addColumn("S_NAME");
      model.addColumn("S_ADDRESS");
      model.addColumn("S_PHONENO");
      model.addColumn("S_EMAILID");

	     jf.setTitle("Delete Supplier");
	     jf.setSize(920,700);
		 jf.setLocation(20,20);
		 jf.setResizable(false);
		 
	     jf.setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
	if(ae.getSource()==b0)
      {
	   	if(((t1.getText()).equals(""))&&((t2.getText()).equals("")))
	     {
		  JOptionPane.showMessageDialog(this,"Please enter supplier id or name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	      }
	      else
	      {//fetch
	      try
	       {
	         int foundrec = 0;
	    Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
         ps=con.prepareStatement("select * from supplier where sid='"+t1.getText()+"' or sname='"+t2.getText()+"'");
	      rs=ps.executeQuery();
		  while(rs.next())
	      {
		    t1.setText(rs.getString(1));
	        t2.setText(rs.getString(2));
	        t3.setText(rs.getString(3));
	        t4.setText(rs.getString(4));
		    t5.setText(rs.getString(5));
		     foundrec = 1;
	       }
	       if (foundrec == 0)
                {
                    JOptionPane.showMessageDialog(null,"Record is not available","Dialog",JOptionPane.WARNING_MESSAGE);
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

   else if(ae.getSource()==b1)
	 {//delete
	 	if(((t1.getText()).equals(""))&&((t2.getText()).equals("")))
	     {
		  JOptionPane.showMessageDialog(this,"Please enter supplier id or name !","Warning!!!",JOptionPane.ERROR_MESSAGE);
	      }
	      else
	      {
	      try
	       {
	    Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
	    ps=con.prepareStatement("delete from supplier where sid='"+t1.getText()+"' or sname='"+t2.getText()+"'");
	    ps.executeUpdate();
        JOptionPane.showMessageDialog(null,"Record is deleted.");
        t1.setText("");
        t2.setText("");
        t3.setText("");
        t4.setText("");
        t5.setText("");
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
        rs = stmt.executeQuery("SELECT * from supplier" );
          while(rs.next())
            {
            	model.insertRow(r++, new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5) });
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
	      new DeleteSupplier();
	}
}

