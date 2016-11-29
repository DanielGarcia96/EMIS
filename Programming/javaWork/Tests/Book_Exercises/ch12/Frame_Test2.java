package core;

import java.io.*;
import java.awt.*;
import java.awt.image.*;
import javax.imageio.*;
import javax.swing.*;

public class Frame_Test2 extends JFrame{
    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    public Frame_Test2() {
        super("Locations");
        Toolkit kit = Toolkit.getDefaultToolkit();
        Dimension d = kit.getScreenSize();
        int width = d.width;
        int height = d.height;
        setSize(width / 2, height / 2);
        setLocation(width / 4, height / 4);
        JPanel imgPanel = new JPanel();
        BufferedImage img = null;
        File file = new File("kill_yourself.gif");
        System.out.println("File exists: " + file.exists());

        try {
            img = ImageIO.read(file);
        } catch (IIOException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (img != null) {
            JLabel label = new JLabel(new ImageIcon(img));
            imgPanel.add(label);
            add(label);
        }
    }
    public static void main(String[] args) {
        Frame_Test2 f = new Frame_Test2();
        f.setDefaultCloseOperation(EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
