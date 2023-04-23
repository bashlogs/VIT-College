// Write a datepicker program using frame
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.*;
import javax.swing.text.DateFormatter;
import javax.swing.text.DefaultFormatterFactory;
import javax.swing.text.MaskFormatter;
import javax.swing.text.NumberFormatter;


class datepickerpgm extends JFrame{
    
    public datepickerpgm(){
        super("Date Picker");
        JFormattedTextField dateField = new JFormattedTextField(new DateFormatter(new SimpleDateFormat("dd/MM/yyyy")));
        dateField.setValue(new Date());
        add(dateField);

        // Write a date picker prg
        
        
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        setVisible(true);
    }
    public static void main(String[] args) {
        datepickerpgm dp = new datepickerpgm();

    }

}