package worm;

import java.util.ArrayList;
import items.*;

public class Worm {
	protected String username;
	protected short power;
	protected ArrayList<Item> items;
	
	public Worm(String username) {
		this.username = username;
		items = new ArrayList<Item>();
	}
	
	public void addItem(Item i) {
		items.add(i);
	}
}
