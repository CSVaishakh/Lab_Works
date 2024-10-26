import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class TrafficLight extends JFrame implements ActionListener {
    JLabel label;
    JTextField display;
    JRadioButton r1, r2, r3;
    ButtonGroup bg;
    Container c;
    TrafficLight() {
        setLayout(new FlowLayout());
        c = getContentPane();
        label = new JLabel("Traffic Light");
        r1 = new JRadioButton("Red");
        r2 = new JRadioButton("Yellow");
        r3 = new JRadioButton("Green");
        display = new JTextField(20); // Initialize display with a column size
        bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);
        c.add(label);
        c.add(r1);
        c.add(r2);
        c.add(r3);
        c.add(display);
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);
        setSize(500, 500);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close the application when the frame is closed
        c.setBackground(Color.white);
    }
    public void actionPerformed(ActionEvent ie) {
        if (ie.getSource() == r1) {
            c.setBackground(Color.red);
            display.setText("RED : TURNED ON");
        } else if (ie.getSource() == r2) {
            c.setBackground(Color.yellow); // Corrected method name
            display.setText("YELLOW : TURNED ON");
        } else if (ie.getSource() == r3) {
            c.setBackground(Color.green); // Corrected method name
            display.setText("GREEN : TURNED ON");
        }
    }
    public static void main(String[] args) {
        new TrafficLight();
    }
}

