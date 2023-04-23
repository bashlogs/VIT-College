import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class SupplierWiseMedList extends JFrame implements ActionListener
 {
    JFrame jf;
	JLabel b;
	ImageIcon img;
    JButton submit,clear;
    JLabel l1,ln;
    JTextField t1;
    Font f;
    Connection con;
    PreparedStatement ps;
    Statement stmt;
    ResultSet rs;
 	DefaultTableModel model = new DefaultTableModel();
    JTable tabGrid = new JTable(model);
    JScrollPane scrlPane = new JScrollPane(tabGrid);

  public SupplierWiseMedList()
  {
   jf=new JFrame();
   img=new ImageIcon("images//61804.jpg");
	b=new JLabel("",img,JLabel.CENTER);
	b.setBounds(0,0,800,600);
	jf.add(b);
	//setVisible(true);
   f = new Font("Arial",Font.PLAIN,20);
   b.setLayout(null);

  	ln = new JLabel("Supplier wise Medicine report");
    ln.setFont(new Font("Arial",Font.BOLD,25));
    ln.setForeground(Color.black);
    ln.setHorizontalAlignment(JLabel.CENTER);
	  ln.setBounds(0,30,900,40);ln.setForeground(Color.black);
    b.add(ln);

    l1 = new JLabel("Enter Supplier name");
    l1.setFont(f);
	l1.setForeground(Color.black);
  l1.setHorizontalAlignment(JLabel.CENTER);
  l1.setBounds(0,150,900,40);l1.setForeground(Color.black);
    b.add(l1);

    t1=new JTextField(10);
    t1.setBounds(350,200,200,25);t1.setToolTipText("Enter supplier name");
    t1.setFont(new Font("Arial",Font.PLAIN,15)); 
	t1.setForeground(Color.black);
	b.add(t1);



    submit = new JButton("Submit",new ImageIcon("images//open.png"));
    submit.setBounds(285,250,135,35); submit.setToolTipText("click to open supplier wise medicine report");
    b.add(submit);submit.addActionListener(this);

    clear = new JButton("Clear",new ImageIcon("images//clear.png"));
    clear.setBounds(465,250,135,35);clear.setToolTipText("click to clear textfield");
    b.add(clear);clear.addActionListener(this);

    scrlPane.setBounds(0,370,920,600);
    b.add(scrlPane);
    tabGrid.setFont(new Font ("Arial",0,15));

        model.addColumn("M_BNO");
        model.addColumn("M_NAME");
        model.addColumn("M_COMPANY");
        model.addColumn("M_QUANTITY");
        model.addColumn("M_EXPDATE");
        model.addColumn("M_PURDATE");
        model.addColumn("M_TYPE");
        model.addColumn("M_PURPRICE");
        model.addColumn("M_SALEPRICE");
        model.addColumn("M_RACKNO");
        model.addColumn("M_SID");
        model.addColumn("M_SNAME");


    jf.setTitle("Supplier Wise Medicine Report");
    jf.setSize(920,700);
	jf.setLocation(20,20);
	jf.setResizable(false);

    jf.setVisible(true);
  }

  	public void actionPerformed(ActionEvent ae)
	{
	if(ae.getSource()==submit)
	 {//list
  	int r = 0;
     try
     {
     		if(((t1.getText()).equals("")))
	        {
		    JOptionPane.showMessageDialog(this,"Please supplier name !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else
	        {
	         int foundrec = 0;
     	Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("SELECT mbno,mname,mcompany,mqty,mexpdate,mpurdate,mtype,mpurprice,msaleprice,mrackno,sid,sname from medicine where sname='"+t1.getText()+"' ");
          while(rs.next())
            {
  model.insertRow(r++,new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6),rs.getString(7),rs.getString(8),rs.getString(9),rs.getString(10),rs.getString(11),rs.getString(12)});
              foundrec = 1;
            }
              if (foundrec == 0)
                {
                    JOptionPane.showMessageDialog(null,"Not any medicine provide by given supplier","Dialog",JOptionPane.WARNING_MESSAGE);
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

	 else if(ae.getSource()==clear)
	 {
	 	t1.setText("");
	 }
    }

  public static void main(String args[])
    {
    	new SupplierWiseMedList();
    }
}
