import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class SearchMedicine extends JFrame implements ActionListener
{
	JFrame jf;
	JLabel b;
	ImageIcon img;
	JTextField t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	JLabel l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,ln;
    JButton b0,b1,b2;
    JComboBox msname;
    String s;
	Font f;
    Connection con;
	PreparedStatement ps;
	Statement stmt;
	ResultSet rs;
	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);
	
	SearchMedicine()
	{
		jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
		f = new Font("Arial",Font.PLAIN,20);
		b.setLayout(null);

	    ln=new JLabel("Search Medicine");
	    ln.setFont(new Font("Arial",Font.BOLD,25));
	    ln.setForeground(Color.BLACK);
	    ln.setHorizontalAlignment(JLabel.CENTER);
	  	ln.setBounds(0,40,900,40);ln.setForeground(Color.black);
	    b.add(ln);

		l1 = new JLabel("*Medicine Batch no: ");
		//l1.setFont(f);
  l1.setBounds(20,100,200,25); l1.setFont(new Font("Arial",Font.PLAIN,20));
	    l1.setForeground(Color.BLACK);
		b.add(l1);

		t1 = new JTextField(20);
		t1.setBounds(250,100,170,25);t1.setToolTipText("Enter medicine batch no to search");
		 t1.setFont(new Font("Arial",Font.PLAIN,20));
	    t1.setForeground(Color.black);
		b.add(t1);

		l2 = new JLabel("*Medicine name: ");
		//l2.setFont(f);
   l2.setBounds(20,140,200,25);
    l2.setFont(new Font("Arial",Font.PLAIN,20));
	    l2.setForeground(Color.BLACK);
		b.add(l2);

    	t2 = new JTextField(20);
		t2.setBounds(250,140,170,25);t2.setToolTipText("Enter medicine name to search");
		 t2.setFont(new Font("Arial",Font.PLAIN,20));
	    t2.setForeground(Color.black);
		b.add(t2);

		l3 = new JLabel("Medicine company: ");
		//l3.setFont(f);
   l3.setBounds(20,180,200,25);
    l3.setFont(new Font("Arial",Font.PLAIN,20));
	    l3.setForeground(Color.BLACK);
		b.add(l3);

     	t3 = new JTextField(20);
		t3.setBounds(250,180,170,25);
		 t3.setFont(new Font("Arial",Font.PLAIN,20));
	    t3.setForeground(Color.black);
		b.add(t3);

		l4 = new JLabel("Medicine quantity: ");
		//l4.setFont(f);
   l4.setBounds(20,220,200,25);
    	 l4.setFont(new Font("Arial",Font.PLAIN,20));
	    l4.setForeground(Color.BLACK);
		b.add(l4);

        t4= new JTextField(20);
		t4.setBounds(250,220,170,25);
		 t4.setFont(new Font("Arial",Font.PLAIN,20));
	    t4.setForeground(Color.black);
		b.add(t4);

		l5= new JLabel("Med expiry date: ");
		//l5.setFont(f);
   l5.setBounds(20,260,250,25);
		 l5.setFont(new Font("Arial",Font.PLAIN,20));
	    l5.setForeground(Color.BLACK);
		b.add(l5);

	    t5= new JTextField(20);
		t5.setBounds(250,260,170,25);
		 t5.setFont(new Font("Arial",Font.PLAIN,20));
	    t5.setForeground(Color.black);
		b.add(t5);


		l6= new JLabel("Med purchase date: ");
		//l6.setFont(f);
    l6.setBounds(20,300,250,25);
    	 l6.setFont(new Font("Arial",Font.PLAIN,20));
	    l6.setForeground(Color.BLACK);
		b.add(l6);

        t6= new JTextField(20);
		t6.setBounds(250,300,170,25);
		 t6.setFont(new Font("Arial",Font.PLAIN,20));
	    t6.setForeground(Color.black);b.add(t6);

		l7 = new JLabel("Medicine type: ");
		//l7.setFont(f);
    l7.setBounds(470,100,200,25);
    	 l7.setFont(new Font("Arial",Font.PLAIN,20));
	    l7.setForeground(Color.BLACK);
		b.add(l7);

        t7 = new JTextField(20);
		t7.setBounds(720,100,170,25);
		 t7.setFont(new Font("Arial",Font.PLAIN,20));
	    t7.setForeground(Color.black);
		b.add(t7);

		l8= new JLabel("Medicine purchase price: ");
		//l8.setFont(f);
   l8.setBounds(470,140,240,25);
    	 l8.setFont(new Font("Arial",Font.PLAIN,20));
	    l8.setForeground(Color.BLACK);
		b.add(l8);

        t8 = new JTextField(20);
		t8.setBounds(720,140,170,25);
		 t8.setFont(new Font("Arial",Font.PLAIN,20));
	    t8.setForeground(Color.black);b.add(t8);

		l9 = new JLabel("Medicine sale price: ");
		//l9.setFont(f);
    l9.setBounds(470,180,200,25);
	 l9.setFont(new Font("Arial",Font.PLAIN,20));
	    l9.setForeground(Color.BLACK);
    	b.add(l9);

        t9 = new JTextField(20);
		t9.setBounds(720,180,170,25);
		 t9.setFont(new Font("Arial",Font.PLAIN,20));
	    t9.setForeground(Color.black);
		b.add(t9);

		l10 = new JLabel("Medicine rack no: ");
		//l10.setFont(f);
   l10.setBounds(470,220,200,25);
    	 l10.setFont(new Font("Arial",Font.PLAIN,20));
	    l10.setForeground(Color.BLACK);
		b.add(l10);

        t10 = new JTextField(20);
		t10.setBounds(720,220,170,25);
		 t10.setFont(new Font("Arial",Font.PLAIN,20));
	    t10.setForeground(Color.black);
		b.add(t10);

		l11 = new JLabel("Supplier name: ");
		//l11.setFont(f);
   l11.setBounds(470,260,180,25);
    	 l11.setFont(new Font("Arial",Font.PLAIN,20));
	    l11.setForeground(Color.BLACK);
		b.add(l11);

        t11 = new JTextField(20);
	   	t11.setBounds(720,260,170,25);
	   	 t11.setFont(new Font("Arial",Font.PLAIN,20));
	    t11.setForeground(Color.black);
		b.add(t11);

	   	l12 = new JLabel("Supplier id: ");
		//l12.setFont(f);
 	l12.setBounds(470,300,180,25);
    	 l12.setFont(new Font("Arial",Font.PLAIN,20));
	    l12.setForeground(Color.BLACK);
		b.add(l12);

    	t12 = new JTextField(20);
	    t12.setBounds(720,300,170,25);
	     t12.setFont(new Font("Arial",Font.PLAIN,20));
	    t12.setForeground(Color.black);
		b.add(t12);

        b0 = new JButton("Search",new ImageIcon("images//search.png"));
        b0.setBounds(250,350,110,35);b0.setToolTipText("click to search medicine details");
		b.add(b0);b0.addActionListener(this);

		b1 = new JButton("Clear",new ImageIcon("images//clear.png"));
		b1.setBounds(400,350,110,35);b1.setToolTipText("click to clear all textfields");
	    b.add(b1); b1.addActionListener(this);

        b2= new JButton("All",new ImageIcon("images//all.png"));
		b2.setBounds(550,350,110,35);b2.setToolTipText("click to view all medicine details");
		b.add(b2); b2.addActionListener(this);
		scrlPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);  
	    scrlPane.setBounds(0,420,920,170);
		//scrlPane.setEditable(false);
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

	     jf.setTitle("Search Medicine ");
	     jf.setSize(920,600);
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
		    JOptionPane.showMessageDialog(this,"Please enter medicine bno or name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else
	        {
	         int foundrec = 0;

	    Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");

		  ps=con.prepareStatement("select * from medicine where mname='"+t2.getText()+"' or mbno='"+t1.getText()+"'");
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
 else if(ae.getSource()==b2)
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
  new SearchMedicine();
 }
}


