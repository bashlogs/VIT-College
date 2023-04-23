import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class SearchSupplier extends JFrame implements ActionListener
{
	JLabel b;
	ImageIcon img;
	JFrame jf;
	JTextField t1,t2,t3,t4,t5;
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

	SearchSupplier()
	{
		jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
		f = new Font("Arial",Font.PLAIN,20);
		b.setLayout(null);

	    l6=new JLabel("Search Supplier");
	    l6.setFont(new Font("Arial",Font.BOLD,25));
		l6.setHorizontalAlignment(JLabel.CENTER);
	    l6.setBounds(0,50,900,40);l6.setForeground(Color.black);
	    b.add(l6);

		l1= new JLabel("Search by id :");
		//l1.setFont(f);
   l1.setBounds(250,120,130,25);
    l1.setFont(new Font("Arial",Font.PLAIN,20));
	    l1.setForeground(Color.black);
		b.add(l1);

		t1=new JTextField(20);
		t1.setBounds(490,120,170,25);t1.setToolTipText("Enter supplier id to search supplier");
		 t1.setFont(new Font("Arial",Font.PLAIN,15));
	    t1.setForeground(Color.black);
		b.add(t1);

		l2 = new JLabel("Search by name :");
		//l2.setFont(f);
   l2.setBounds(250,160,170,25);
		 l2.setFont(new Font("Arial",Font.PLAIN,20));
	    l2.setForeground(Color.black);
		b.add(l2);

		t2=new JTextField(20);
		t2.setBounds(490,160,170,25);t2.setToolTipText("Enter supplier name to search supplier");
		 t2.setFont(new Font("Arial",Font.PLAIN,15));
	    t2.setForeground(Color.black);
		b.add(t2);

		l3 = new JLabel("Supplier address: ");
		//l3.setFont(f);
   l3.setBounds(250,200,170,25);
		 l3.setFont(new Font("Arial",Font.PLAIN,20));
	    l3.setForeground(Color.black);
		b.add(l3);

		t3=new JTextField(20);
		t3.setBounds(490,200,170,25);
		 t3.setFont(new Font("Arial",Font.PLAIN,15));
	    t3.setForeground(Color.black);b.add(t3);

		l4 = new JLabel("Supplier phone no: ");
		//l4.setFont(f);
   l4.setBounds(250,240,170,25);
		 l4.setFont(new Font("Arial",Font.PLAIN,20));
	    l4.setForeground(Color.black);
		b.add(l4);

		t4=new JTextField(20);
		t4.setBounds(490,240,170,25);
		 t4.setFont(new Font("Arial",Font.PLAIN,15));
	    t4.setForeground(Color.black);b.add(t4);

		l5 = new JLabel("Supplier email id: ");
		//l5.setFont(f);
   l5.setBounds(250,280,170,25);
		 l5.setFont(new Font("Arial",Font.PLAIN,20));
	    l5.setForeground(Color.black);
		 b.add(l5);

		t5=new JTextField(20);
		t5.setBounds(490,280,170,25);
		t5.setFont(new Font("Arial",Font.PLAIN,15));
	    t5.setForeground(Color.black);
		b.add(t5);


        b0 = new JButton("Search",new ImageIcon("images//search.png"));
        b0.setBounds(250,330,110,35);b0.setToolTipText("click to open supplier details");
		 b0.setFont(new Font("Arial",Font.PLAIN,15));
	    b0.setForeground(Color.black);
		b.add(b0);b0.addActionListener(this);

		b1 = new JButton("Clear",new ImageIcon("images//clear.png"));
		b1.setBounds(400,330,110,35);b1.setToolTipText("click to clear all textfields");
	     b1.setFont(new Font("Arial",Font.PLAIN,15));
	    b1.setForeground(Color.black);
		b.add(b1); b1.addActionListener(this);

        b2= new JButton("All",new ImageIcon("images//all.png"));
		b2.setBounds(550,330,110,35);b2.setToolTipText("click to view all supplier details");
		 b2.setFont(new Font("Arial",Font.PLAIN,15));
	    b2.setForeground(Color.black);
		b.add(b2); b2.addActionListener(this);

      scrlPane.setBounds(0,380,920,600);
      b.add(scrlPane);
      tabGrid.setFont(new Font ("Arial",0,15));

      model.addColumn("S_ID");
      model.addColumn("S_NAME");
      model.addColumn("S_ADDRESS");
      model.addColumn("S_PHONENO");
      model.addColumn("S_EMAILID");

	     jf.setTitle("Search Supplier");
	     jf.setSize(920,700);
		 jf.setLocation(20,20);
		 jf.setResizable(false);
		 jf.getContentPane().setBackground(Color.cyan);
	     jf.setVisible(true);

	}
 public void actionPerformed(ActionEvent ae)
    {
    if(ae.getSource()==b0)
	 {//fetch
	  try
	   {
	   		if(((t1.getText()).equals(""))&&((t2.getText()).equals("")))
	        {
		    JOptionPane.showMessageDialog(this,"Please enter supplier id or name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else
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
     else if(ae.getSource()==b1)
      {//clear
          t1.setText("");
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
          JOptionPane.showMessageDialog(null,"SQL Error :");
       }
       catch(Exception e)
       {
       	   System.out.println(e);
           JOptionPane.showMessageDialog(null,"Error :");
       }
	}
   }

	public static void main(String args[])
	{
	    new SearchSupplier();
	}
}

