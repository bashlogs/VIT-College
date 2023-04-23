import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.GridLayout;

public class MainMenu extends JFrame implements ActionListener
{   JFrame jf;
    JLabel b;
    ImageIcon img;
	JMenuBar mbar;
	JMenu m1,m2,m3,m4,m5;
	JMenuItem m1_1,m1_2,m1_3,m1_4,m1_5,m2_1,m2_2,m2_3,m2_4,m2_5,m3_1,m3_2,m3_3,m4_1,m5_1;
	JLabel l1,l2,l3,l4,l5;
	JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16;

	public MainMenu()
	{
        jf=new JFrame();
		img=new ImageIcon("images//61804.jpg");
        b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);
                
		
		b.setLayout(null);
		int gap = 5;
		l1=new JLabel("WELCOME TO MED TRACKING SYSTEM");
		l1.setHorizontalAlignment(JLabel.CENTER);
		l1.setFont(new Font("Times New Roman",Font.BOLD,28));
		l1.setBounds(25,30,800,20);		
		l1.setBorder(BorderFactory.createEmptyBorder(gap, gap, gap, gap));
		l1.setForeground(Color.BLACK);
		b.add(l1);
		
		l2=new JLabel("SUPPLIER");
		l2.setFont(new Font("Times New Roman",Font.BOLD,24));
		l2.setForeground(Color.BLACK);
		l2.setBounds(58,120,800,20);
		b.add(l2);

		b1=new JButton("New Supplier");
		b1.setBounds(40,160,150,30);
		b.add(b1);
		b1.addActionListener(this);

		b2=new JButton("Search Supplier");
		b2.setBounds(40,210,150,30);
		b.add(b2);
		b2.addActionListener(this);

		b3=new JButton("Update Supplier");
		b3.setBounds(40,260,150,30);
		b.add(b3);
		b3.addActionListener(this);

		b4=new JButton("Delete Supplier");
		b4.setBounds(40,310,150,30);
		b.add(b4);
		b4.addActionListener(this);

		b5=new JButton("List Supplier");
		b5.setBounds(40,360,150,30);
		b.add(b5);
		b5.addActionListener(this);


		l3=new JLabel("MEDICINE");
		l3.setFont(new Font("Times New Roman",Font.BOLD,24));
		l3.setForeground(Color.BLACK);
		l3.setBounds(270,120,800,20);
		b.add(l3);

		b6=new JButton("New Medicine");
		b6.setBounds(255,160,150,30);
		b.add(b6);
		b6.addActionListener(this);

		b7=new JButton("Search Medicine	");
		b7.setBounds(255,210,150,30);
		b.add(b7);
		b7.addActionListener(this);

		b8=new JButton("Update Medicine");
		b8.setBounds(255,260,150,30);
		b.add(b8);
		b8.addActionListener(this);

		b9=new JButton("Delete Medicine");
		b9.setBounds(255,310,150,30);
		b.add(b9);
		b9.addActionListener(this);

		b10=new JButton("List Medicine");
		b10.setBounds(255,360,150,30);
		b.add(b10);
		b10.addActionListener(this);


		l4=new JLabel("REPORT");
		l4.setFont(new Font("Times New Roman",Font.BOLD,24));
		l4.setForeground(Color.BLACK);
		l4.setBounds(495,120,800,20);
		b.add(l4);

		b11=new JButton("Daily Report");
		b11.setBounds(470,160,150,30);
		b.add(b11);
		b11.addActionListener(this);

		b12=new JButton("Supplier Report");
		b12.setBounds(470,210,150,30);
		b.add(b12);
		b12.addActionListener(this);

		b13=new JButton("Medicine Report");
		b13.setBounds(470,260,150,30);
		b.add(b13);
		b13.addActionListener(this);

		l4=new JLabel("ABOUT");
		l4.setFont(new Font("Times New Roman",Font.BOLD,24));
		l4.setForeground(Color.BLACK);
		l4.setBounds(710,120,800,20);
		b.add(l4);
		
		b14=new JButton("About Us");
		b14.setBounds(680,160,150,30);
		b.add(b14);
		b14.addActionListener(this);

		b15=new JButton("Exit");
		b15.setBounds(680,210,150,30);
		b.add(b15);
		b15.addActionListener(this);


		mbar = new JMenuBar();
		
		jf.setJMenuBar(mbar);

		m1=new JMenu("Supplier");
		mbar.add(m1);
		m1_1 = new JMenuItem("Add New Supplier",new ImageIcon("images//addnew.png"));
		m1.add(m1_1);
		m1_2 = new JMenuItem("search Supplier",new ImageIcon("images//search.png"));
		m1.add(m1_2);
		m1_3 = new JMenuItem("Update Supplier",new ImageIcon("images//update.png"));
		m1.add(m1_3);
		m1_4 = new JMenuItem("Delete Supplier",new ImageIcon("images//delete.png"));
		m1.add(m1_4);
	    m1_5 = new JMenuItem("List of Supplier",new ImageIcon("images//all.png"));
		m1.add(m1_5);

		m2=new JMenu("Medicine");
		mbar.add(m2);
		m2_1 = new JMenuItem("Add New Medicine",new ImageIcon("images//addnew.png"));
		m2.add(m2_1);
		m2_2 = new JMenuItem("search Medicine",new ImageIcon("images//search.png"));
		m2.add(m2_2);
		m2_3 = new JMenuItem("Update Medicine",new ImageIcon("images//update.png"));
		m2.add(m2_3);
		m2_4 = new JMenuItem("Delete Medicine",new ImageIcon("images//delete.png"));
		m2.add(m2_4);
	    m2_5 = new JMenuItem("Stock of Medicine",new ImageIcon("images//all.png"));
		m2.add(m2_5);


		m3=new JMenu("Report");
	    mbar.add(m3);
		m3_1 = new JMenuItem("Daily Purchase Report",new ImageIcon("images//report.png"));
		m3.add(m3_1);

		m3_2 = new JMenuItem("Suplier wise medicine Report",new ImageIcon("images//report.png"));
		m3.add(m3_2);

		m3_3 = new JMenuItem("Suplier wise medicine Report",new ImageIcon("images//report.png"));
		m3.add(m3_3);

		m4=new JMenu("About");
		mbar.add(m4);
		m4_1 = new JMenuItem("About System",new ImageIcon("images//help.png"));
		m4.add(m4_1);

		m5=new JMenu("Exit");
		mbar.add(m5);
		m5_1 = new JMenuItem("Exit",new ImageIcon("images//exit.png"));
		m5.add(m5_1);

        m1_1.addActionListener(this);
		m1_2.addActionListener(this);
		m1_3.addActionListener(this);
		m1_4.addActionListener(this);
    	m1_5.addActionListener(this);

		m2_1.addActionListener(this);
		m2_2.addActionListener(this);
		m2_3.addActionListener(this);
		m2_4.addActionListener(this);
	    m2_5.addActionListener(this);

		m3_1.addActionListener(this);
		m3_2.addActionListener(this);
		m3_3.addActionListener(this);
		m4_1.addActionListener(this);
		m5_1.addActionListener(this);

		jf.setTitle("Main Menu");
		jf.setLocation(20,20);
	    jf.setSize(900,700);
	    jf.setResizable(true);
		
		jf.setVisible(true);

	}

	public void actionPerformed(ActionEvent ae)
	{

	  if(ae.getSource()==m1_1 || ae.getSource()==b1)
		{
		  new AddNewSupplier();
		}
		else if(ae.getSource()==m1_2 || ae.getSource()==b2)
		{
		 new SearchSupplier();
		}
		else if(ae.getSource()==m1_3 || ae.getSource()==b3)
		{
		new UpdateSupplier();
		}
		else if(ae.getSource()==m1_4 || ae.getSource()==b4)
		{
		new DeleteSupplier();
		}
	    else if(ae.getSource()==m1_5 || ae.getSource()==b5)
		{
		  new SupplierList();
		}


		else if(ae.getSource()==m2_1 || ae.getSource()==b6)
		{
			new AddNewMedicine();
		}
		else if(ae.getSource()==m2_2 || ae.getSource()==b7)
		{
			new SearchMedicine();
		}
		else if(ae.getSource()==m2_3 || ae.getSource()==b8)
		{
			new UpdateMedicine();
		}
		else if(ae.getSource()==m2_4 || ae.getSource()==b9)
		{
			new DeleteMedicine();
		}
		else if(ae.getSource()==m2_5 || ae.getSource()==b10)
		{
			new MedicineList();
		}

		 else if(ae.getSource()==m3_1 || ae.getSource()==b11)
		 {
		   new DailyPurchaseReport();
		 }

		  else if(ae.getSource()==m3_2 || ae.getSource()==b12)
		 {
		   new SupplierWiseMedList();
		 }

		 else if(ae.getSource()==m3_3 || ae.getSource()==b13)
		 {
		   new medicine_report();
		 }

		else if(ae.getSource()==m4_1 || ae.getSource()==b14)
		{
	        new About();
		}

		else if(ae.getSource()==m5_1 || ae.getSource()==b15)
		{
		  System.exit(0);
		}

  }

	public static void main(String args[])
	{
		new MainMenu();
	}
}
