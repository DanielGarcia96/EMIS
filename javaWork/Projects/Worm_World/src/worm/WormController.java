package worm;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ConcurrentModificationException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.TimerTask;

import java.util.Timer;

import map.Map;

public class WormController implements KeyListener {
	
	public HashSet<Integer> pressedKeys = new HashSet<Integer>();
	public Timer keyTimer;
	public Worm thisWorm;
	public Map  map;
	
	public WormController(Worm w, Map m) {
		
		thisWorm = w;
		map = m;
		
        //Check every 20ms if there's keys pressed
        keyTimer = new Timer();
        keyTimer.schedule(new KeyTimer(), 0, 20);
        keyTimer.schedule(new DirtTimer(), 7000, 7000);
	}

	@Override
	public void keyPressed(KeyEvent arg0) {
		//Add key to hashSet when pressed
		 int keyCode = arg0.getKeyCode();
         pressedKeys.add(keyCode);
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
        //Remove key from hashSet when released
        int keyCode = arg0.getKeyCode();
        pressedKeys.remove(keyCode);
	}

	@Override
	public void keyTyped(KeyEvent arg0) {}
	
	private class KeyTimer extends TimerTask {
		public void run() {
			if(!pressedKeys.isEmpty()){
                Iterator<Integer> i = pressedKeys.iterator();
                while(i.hasNext()){
                	int compare = 0;
                	try {
                		compare = i.next().intValue();
                	}catch(ConcurrentModificationException e) {
                		e.printStackTrace();
                	}
                	switch(compare) {
                		case 'W':
                			if (thisWorm.getPosition().getY() <= 64)
                				break;
                			thisWorm.changePosition(thisWorm.getPosition().getX(), thisWorm.getPosition().getY()-1);
                			System.out.println(thisWorm.getPosition());
                			map.eatEarth(thisWorm.getPosition());
                			break;
                		case 'S':
                			thisWorm.changePosition(thisWorm.getPosition().getX(), thisWorm.getPosition().getY()+1);
                			System.out.println(thisWorm.getPosition());
                			map.eatEarth(thisWorm.getPosition());
                			break;
                		case 'A':
                			thisWorm.changePosition(thisWorm.getPosition().getX()-1, thisWorm.getPosition().getY());
                			System.out.println(thisWorm.getPosition());
                			map.eatEarth(thisWorm.getPosition());
                			break;
                		case 'D':
                			thisWorm.changePosition(thisWorm.getPosition().getX()+1, thisWorm.getPosition().getY());
                			System.out.println(thisWorm.getPosition());
                			map.eatEarth(thisWorm.getPosition());
                			break;
                	}
                }
            }
            map.repaint();
        }
	}
	
	private class DirtTimer extends TimerTask {

		@Override
		public void run() {
			if (!map.eatenEarth.isEmpty())
			map.eatenEarth.remove(0);
		}
	}

}