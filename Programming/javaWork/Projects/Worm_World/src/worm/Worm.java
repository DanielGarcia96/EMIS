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
	protected BufferedImage image = null;
	
	public Worm(String username, String wormType) {
		this.userName = username;
		this.wormType = wormType;
		items = new ArrayList<Item>();
		position = new Point(250,250);
		
		try {
			image = ImageIO.read(new File("./images/worms/"+wormType+".png"));
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
		return image;
	}
}
