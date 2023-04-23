import javax.swing.*;
import java.awt.*;

class About extends JFrame
{
	JFrame jf;
	JLabel b;
	ImageIcon img;
	JLabel l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
	JButton b1,b2,b3;

	About()
	{
		jf=new JFrame();
		img=new ImageIcon("images//rn.jpg");
		b=new JLabel("",img,JLabel.CENTER);
		b.setBounds(0,0,800,600);
		jf.add(b);
		//setVisible(true);

		b.setLayout(null);

		l1 = new JLabel("Medical Store Manangement System");
		l1.setFont(new Font("Times New Roman",Font.BOLD,25));
		l1.setBounds(200,30,600,40);l1.setForeground(Color.black);
		b.add(l1);



		l2 = new JLabel("This System is developed by,");
		l2.setFont(new Font("Times New Roman",Font.BOLD,18));
		l2.setForeground(Color.black);
		l2.setBounds(50,150,600,40);
		b.add(l2);

		l3 = new JLabel("Mr.Akshay Uttam Chame.  ");
		l3.setFont(new Font("Times New Roman",Font.BOLD,20));
		l3.setBounds(225,200,900,40);l3.setForeground(Color.black);
		b.add(l3);
		
		l8 = new JLabel("Mr.Aryan Amol Lad.");
		l8.setFont(new Font("Times New Roman",Font.BOLD,20));
		l8.setBounds(225,220,900,40);l8.setForeground(Color.black);
		b.add(l8);
		
		l9 = new JLabel("Mr.Soham Sujeet Waghmare.");
		l9.setFont(new Font("Times New Roman",Font.BOLD,20));
		l9.setBounds(225,240,900,40);l9.setForeground(Color.black);
		b.add(l9);
		
		l10 = new JLabel("Mr.Ajay Prakashrao Yache.");
		l10.setFont(new Font("Times New Roman",Font.BOLD,20));
		l10.setBounds(225,260,900,40);l10.setForeground(Color.black);
		b.add(l10);

		l4 = new JLabel("~ Guided By Mrs.Galshetwar madam.");
		l4.setFont(new Font("Times New Roman",Font.BOLD,20));l4.setForeground(Color.black);
		l4.setBounds(480,290,800,40);
		b.add(l4);

		l5 = new JLabel("In this system we can add details of Medicines,Suppliers & We can also update,delete & search the existing ");
		l5.setFont(new Font("Times New Roman",Font.BOLD,17));
		l5.setForeground(Color.black);
		l5.setBounds(50,385,800,40);
		b.add(l5);

		l6 = new JLabel("*******************************************************************************");
		l6.setFont(new Font("Times New Roman",Font.BOLD,20));
		l6.setForeground(Color.black);
		l6.setBounds(50,350,800,40);
		b.add(l6);

		l7 = new JLabel("details.It is helpfull for stock of Medicine & whrere we placed the medicine in store.");
		l7.setFont(new Font("Times New Roman",Font.BOLD,17));
		l7.setForeground(Color.black);
		l7.setBounds(50,405,800,40);
		b.add(l7);

        jf.setTitle("About System");
		jf.setSize(900,700);
		jf.setLocation(20,20);
		jf.setResizable(false);
		
		jf.setVisible(true);

	}

	public static void main(String args[])
	{
          new About();

	}
}