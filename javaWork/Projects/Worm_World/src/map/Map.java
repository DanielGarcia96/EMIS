package map;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

import java.util.ArrayList;

import worm.Worm;

public class Map extends JPanel {
	protected ArrayList<Worm> worms;
	protected short gradient;
	protected String mapName;
	protected BufferedImage map = null;
	protected ArrayList<Point> eatenEarth;
	
	public Map(String mapName) {
		super();
		setSize(500,500);
		
		worms = new ArrayList<Worm>();
		eatenEarth = new ArrayList<Point>();
		this.mapName = mapName;
		mapName = "Garden";
		gradient = 0;
		loadMap(mapName);
		
		setVisible(true);
	}
	
	public void loadMap(String pathname) {
		try {
			map = ImageIO.read(new File(mapName));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void addWorm(Worm w) {
		worms.add(w);
	}
	
	public BufferedImage getMap() {
		return map;
	}
	
	public void update() {
		this.repaint();
	}
	
	public void eatEarth(Point p) {
		eatenEarth.add(p);
	}
	
	public void paint(Graphics g) {
		super.paint(g);
		
		g.drawImage(getMap(), 0, 0, getMap().getWidth(), getMap().getHeight(), null);
		
		for(Point p: eatenEarth) {
			g.drawOval(p.x, p.y, 1, 1);
		}
		
		for(Worm w : worms) {
			g.drawImage(w.getImage(), w.getPosition().x, w.getPosition().y, 
					w.getImage().getWidth(), w.getImage().getHeight(), null);
		}
	}
}
