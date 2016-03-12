package core;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;

import map.*;
import worm.*;

public class Main extends JFrame {
	public Map map;
	public Worm worm;
	
	public Main() {
		super("Worm World");
		setSize(500,500);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		this.worm = new Worm("Danny", "StandardWorm");
		addKeyListener(this.worm.getController());
		
		this.map = new Map("Garden");
		map.addWorm(worm);
		
		setContentPane(map);
		pack();
		setVisible(true);
	}
	
	public static void main(String[] args) {
		Main m = new Main();
	}

}
