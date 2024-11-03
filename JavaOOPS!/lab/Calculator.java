Here's the code with comments and extra blank spaces removed while maintaining proper syntax:

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class TrafficLightWithButtons extends JFrame implements ActionListener {
    private JRadioButton redButton, yellowButton, greenButton;
    private JPanel lightPanel;
    public TrafficLightWithButtons() {
        setTitle("Traffic Light Simulator with Buttons");
        setSize(300, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        redButton = new JRadioButton("Red");
        yellowButton = new JRadioButton("Yellow");
        greenButton = new JRadioButton("Green");
        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);
        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(3, 1));
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);
        lightPanel = new LightPanel();
        add(buttonPanel, BorderLayout.SOUTH);
        add(lightPanel, BorderLayout.CENTER);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        lightPanel.repaint();
    }
    private class LightPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.BLACK);
            g.fillRect(100, 50, 100, 300);
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
```