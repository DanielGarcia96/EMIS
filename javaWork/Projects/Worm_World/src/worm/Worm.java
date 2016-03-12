package worm;

import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

import items.*;

public class Worm {
	protected String userName;
	protected String wormType;
	protected short power;
	protected ArrayList<Item> items;
	protected Point position;
	protected WormController controller;
	protected BufferedImage image = null;
	
	public Worm(String username, String wormType) {
		this.userName = username;
		this.wormType = wormType;
		items = new ArrayList<Item>();
		position = new Point(50,50);
		controller = new WormController(this);
		
		try {
			image = ImageIO.read(new File(wormType));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void changePosition(double x, double y) {
		position = new Point((int)x,(int)y);
	}
	
	public void addItem(Item i) {
		items.add(i);
	}
	
	public void addItems(ArrayList<Item> items) {
		for (Item i : items) {
			this.items.add(i);
		}
	}
	
	public String getUsername() {
		return userName;
	}
	
	public short getPower() {
		return power;
	}
	
	public Point getPosition() {
		return position;
	}
	
	public ArrayList<Item> getItems() {
		return items;
	}

	public BufferedImage getImage() {
		// TODO Auto-generated method stub
		return image;
	}
	
	public WormController getController() {
		return controller;
	}
}
