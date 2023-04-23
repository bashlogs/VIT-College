import org.jdatepicker.impl.JDatePanelImpl;
import org.jdatepicker.impl.JDatePickerImpl;
import org.jdatepicker.impl.SqlDateModel;

// why org.jdatepicker.impl.SqlDateModel is not working in my code?


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.Properties;

class datepicker{
    datepicker(){
        JFrame jf=new JFrame();
        jf.setSize(500,500);
        jf.setLayout(null);
        jf.setVisible(true);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setTitle("Date Picker");
        jf.setLocationRelativeTo(null);
        jf.setResizable(false);
        jf.getContentPane().setBackground(Color.WHITE);
        JLabel l1=new JLabel("Date");
        l1.setBounds(50,50,100,30);
        jf.add(l1);
        SqlDateModel model = new SqlDateModel();
        Properties p = new Properties();
        p.put("text.today", "Today");
        p.put("text.month", "Month");
        p.put("text.year", "Year");
        JDatePanelImpl datePanel = new JDatePanelImpl(model, p);
        JDatePickerImpl datePicker = new JDatePickerImpl(datePanel, new DateLabelFormatter());
        datePicker.setBounds(150,50,200,30);
        jf.add(datePicker);
        JButton b1=new JButton("Submit");
        b1.setBounds(150,100,100,30);
        jf.add(b1);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String date= datePicker.getJFormattedTextField().getText();
                System.out.println(date);
            }
        });
    }
}
