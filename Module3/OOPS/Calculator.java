import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener {
    private JTextField resultField;
    private JButton button0, button1, button2, button3, button4, button5, button6, button7, button8, button9;
    private JButton buttonAdd, buttonSubtract, buttonMultiply, buttonDivide, buttonEquals, buttonClear;
    private double operand1, operand2;
    private String operator;

    public Calculator() {
        super("Calculator");

        resultField = new JTextField(20);
        resultField.setEditable(false);

        button0 = new JButton("0");
        button1 = new JButton("1");
        button2 = new JButton("2");
        button3 = new JButton("3");
        button4 = new JButton("4");
        button5 = new JButton("5");
        button6 = new JButton("6");
        button7 = new JButton("7");
        button8 = new JButton("8");
        button9 = new JButton("9");
        buttonAdd = new JButton("+");
        buttonSubtract = new JButton("-");
        buttonMultiply = new JButton("*");
        buttonDivide = new JButton("/");
        buttonEquals = new JButton("=");
        buttonClear = new JButton("C");

        JPanel buttonPanel = new JPanel(new GridLayout(4, 4));
        buttonPanel.add(button7);
        buttonPanel.add(button8);
        buttonPanel.add(button9);
        buttonPanel.add(buttonDivide);
        buttonPanel.add(button4);
        buttonPanel.add(button5);
        buttonPanel.add(button6);
        buttonPanel.add(buttonMultiply);
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);
        buttonPanel.add(buttonSubtract);
        buttonPanel.add(button0);
        buttonPanel.add(buttonEquals);
        buttonPanel.add(buttonClear);
        buttonPanel.add(buttonAdd);

        add(resultField, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);

        button0.addActionListener(this);
        button1.addActionListener(this);
        button2.addActionListener(this);
        button3.addActionListener(this);
        button4.addActionListener(this);
        button5.addActionListener(this);
        button6.addActionListener(this);
        button7.addActionListener(this);
        button8.addActionListener(this);
        button9.addActionListener(this);
        buttonAdd.addActionListener(this);
        buttonSubtract.addActionListener(this);
        buttonMultiply.addActionListener(this);
        buttonDivide.addActionListener(this);
        buttonEquals.addActionListener(this);
        buttonClear.addActionListener(this);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String buttonText = ((JButton) e.getSource()).getText();

        if (buttonText.matches("[0-9]")) {
            String resultText = resultField.getText();
            resultField.setText(resultText + buttonText);
        } else if (buttonText.matches("[+\\-*/]")) {
            operand1 = Double.parseDouble(resultField.getText());
            operator = buttonText;
            resultField.setText("");
        } else if (buttonText.equals("=")) {
            operand2 = Double.parseDouble(resultField.getText());

            if (operator.equals("+")) {
                resultField.setText(Double.toString(operand1 + operand2));
            } else if (operator.equals("-")) {
                resultField.setText(Double.toString(operand1 - operand2));
            } else if (operator.equals("*")) {
                resultField.setText(Double.toString(operand1 * operand2));
            } else if (operator.equals("/")) {
                resultField.setText(Double.toString(operand1 / operand2));
            }
        } else if (buttonText.equals("C")) {
            resultField.setText("");
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
