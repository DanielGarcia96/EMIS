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
		
		worm = new Worm("Danny", "StandardWorm");
		
		this.map = new Map("Garden");
		map.addWorm(worm);
		addKeyListener(map.getController(worm));
		
		add(map, BorderLayout.CENTER);
		pack();
		setVisible(true);
	}
	
	public static void main(String[] args) {
		Main m = new Main();
	}

}
