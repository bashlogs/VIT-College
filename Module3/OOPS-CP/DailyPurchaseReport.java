import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;



public class DailyPurchaseReport extends JFrame implements ActionListener
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

  public DailyPurchaseReport()
  {
   jf=new JFrame();
   img=new ImageIcon("images//61804.jpg");
    b=new JLabel("",img,JLabel.CENTER);
    b.setBounds(0,0,800,600);
    jf.add(b);
    //setVisible(true);
    f = new Font("Arial",Font.BOLD,20);
    b.setLayout(null);

  	ln = new JLabel("Daily purchase report");
    ln.setFont(new Font("Arial",Font.BOLD,30));
    ln.setForeground(Color.black);
    ln.setHorizontalAlignment(JLabel.CENTER);
	  ln.setBounds(0,30,900,40);ln.setForeground(Color.black);
    b.add(ln);

    l1 = new JLabel("Enter purchase report date");
   l1.setFont(new Font("Arial",Font.BOLD,18));
   l1.setHorizontalAlignment(JLabel.CENTER);
   l1.setBounds(0,150,900,40);l1.setForeground(Color.black);
  b.add(l1);l1.setForeground(Color.black);

    t1=new JTextField(10);
    t1.setBounds(350,200,200,25);t1.setToolTipText("Enter purchase report date");
   t1.setFont(new Font("Arial",Font.BOLD,18)); 
   t1.setForeground(Color.black);
   b.add(t1);

    submit = new JButton("Submit",new ImageIcon("images//open.png"));
    submit.setBounds(285,250,135,35); submit.setToolTipText("click to open daily purchase report");
    b.add(submit);submit.addActionListener(this);

    clear = new JButton("Clear",new ImageIcon("images//clear.png"));
    clear.setBounds(465,250,135,35);clear.setToolTipText("click to clear textfield");
    b.add(clear);clear.addActionListener(this);

    scrlPane.setBounds(0,370,920,600);
    b.add(scrlPane);
    tabGrid.setFont(new Font ("Arial",0,15));

   	model.addColumn("S_ID");
   	model.addColumn("S_NAME");
  	model.addColumn("M_BNO");
  	model.addColumn("M_NAME");
  	model.addColumn("M_EXPDATE");
  	model.addColumn("M_QTY");
  	model.addColumn("M_PURPRICE");
  	model.addColumn("M_SALEPRICE");

    jf.setTitle("Daily Purchase Report");
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
		    JOptionPane.showMessageDialog(this,"Please enter purchase date !","Warning!!!",JOptionPane.WARNING_MESSAGE);
	        }
	        else
	        {
	         int foundrec = 0;
     	Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection("jdbc:mysql://localhost:3306/medical_store","root","");
		System.out.println("Connected to database.");
		stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs = stmt.executeQuery("SELECT sid,sname,mbno,mname,mexpdate,mqty,mpurprice,msaleprice from medicine where mpurdate='"+t1.getText()+"' ");
          while(rs.next())
            {
            	model.insertRow(r++,new Object[]{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6),rs.getString(7),rs.getString(8)});
              foundrec = 1;
            }
              if (foundrec == 0)
                {
                    JOptionPane.showMessageDialog(null,"Not any medicine purchase on given date","Dialog",JOptionPane.WARNING_MESSAGE);
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
    	new DailyPurchaseReport();
    }
}