import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TrafficLightWithButtons extends JFrame implements ActionListener {
    private JRadioButton redButton, yellowButton, greenButton;
    private JPanel lightPanel;

    // Constructor to set up the frame and components
    public TrafficLightWithButtons() {
        // Set up the window
        setTitle("Traffic Light Simulator with Buttons");
        setSize(300, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create the radio buttons
        redButton = new JRadioButton("Red");
        yellowButton = new JRadioButton("Yellow");
        greenButton = new JRadioButton("Green");

        // Group the radio buttons so only one can be selected
        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);

        // Add action listeners to the radio buttons
        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);

        // Create a panel for the buttons and add them
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(3, 1));
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);

        // Create the light panel where the lights will be drawn
        lightPanel = new LightPanel();

        // Add the button panel and light panel to the frame
        add(buttonPanel, BorderLayout.SOUTH);
        add(lightPanel, BorderLayout.CENTER);
    }

    // Handle button click events to repaint the light panel
    @Override
    public void actionPerformed(ActionEvent e) {
        lightPanel.repaint();
    }

    // Inner class to handle the drawing of the traffic light
    private class LightPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            // Draw the traffic light frame
            g.setColor(Color.BLACK);
            g.fillRect(100, 50, 100, 300);

            // Draw the lights based on which button is selected
            drawLight(g, Color.RED, 150, 80, redButton.isSelected());
            drawLight(g, Color.YELLOW, 150, 180, yellowButton.isSelected());
            drawLight(g, Color.GREEN, 150, 280, greenButton.isSelected());
        }

        private void drawLight(Graphics g, Color color, int x, int y, boolean isOn) {
            if (isOn) {
                g.setColor(color);
            } else {
                g.setColor(Color.DARK_GRAY);
            }
            g.fillOval(x - 40, y - 40, 80, 80);
        }
    }

    public static void main(String[] args) {
        TrafficLightWithButtons frame = new TrafficLightWithButtons();
        frame.setVisible(true);
    }
}