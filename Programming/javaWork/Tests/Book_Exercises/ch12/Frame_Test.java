package core;
import javax.swing.*;

public class Frame_Test extends JFrame{
    public static final int DEFAULT_WIDTH = 300;
    public static final int DEFAULT_HEIGHT = 200;
    public Frame_Test() {
        super("This is a JFrame");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    public static void main(String[] args) {
        Frame_Test f = new Frame_Test();
    }
}
