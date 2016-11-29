package map;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

import java.util.ArrayList;
import java.util.ConcurrentModificationException;

import worm.Worm;
import worm.WormController;

@SuppressWarnings("serial")
public class Map extends JPanel {
	protected ArrayList<Worm> worms;
	protected ArrayList<WormController> wormControllers;
	protected short gradient;
	protected String mapName;
	protected BufferedImage map = null;
	public ArrayList<Point> eatenEarth;
	
	public Map(String mapName) {
		super();
		setSize(500,500);
		
		worms = new ArrayList<Worm>();
		wormControllers = new ArrayList<WormController>();
		eatenEarth = new ArrayList<Point>();
		this.mapName = mapName;
		gradient = 0;
		loadMap();
		
		setVisible(true);
	}
	
	public void loadMap() {
		try {
			map = ImageIO.read(new File("./images/maps/"+mapName+".png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void addWorm(Worm w) {
		registerWormController(w);
		worms.add(w);
	}
	
	private void registerWormController(Worm w) {
		wormControllers.add(new WormController(w,this));
	}

	public BufferedImage getMap() {
		return map;
	}
	
	public void update() {
		repaint();
	}
	
	public void eatEarth(Point p) {
		eatenEarth.add(p);
	}
	
	public void paint(Graphics g) {
		super.paint(g);
		
		g.drawImage(getMap(), 0, 0, getWidth(), getHeight(), null);
		
		for(int i = 0; i < eatenEarth.size(); i++) {
			int y = 0;
			int x = 0;
			try {
				x = eatenEarth.get(i).x+17;
				y = eatenEarth.get(i).y+25;
			}catch(ConcurrentModificationException e) {
				e.printStackTrace();
			}
			g.drawOval(x, y, 10, 10);
		}
		for(Point p: eatenEarth) {
			g.drawOval(p.x+17, p.y+25, 10, 10);
		}
		
		for(Worm w : worms) {
			g.drawImage(w.getImage(), w.getPosition().x, w.getPosition().y, 
						w.getImage().getWidth(), w.getImage().getHeight(), null);
		}
	}
	
	public WormController getController(Worm worm) {
		return wormControllers.get(0);
	}
}