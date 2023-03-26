    import java.awt.*;  
    import javax.swing.*;  
    public class temp {  
        public static void main(String[] args) {  
		JFrame frame = new JFrame("SIMPLE TEXT");
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());  
	        JLabel label = new JLabel("JFrame By Example");  
		JButton button = new JButton();  
	        button.setText("Button");  
        	panel.add(label);  
	        panel.add(button);  
        	frame.add(panel);  
	        frame.setSize(200, 300);  
        	frame.setLocationRelativeTo(null);  
	        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.setResizable(false);
		frame.pack();
		//frame.setLocationRelativeTo(null);
		frame.setVisible(true);
        }  
    } 
