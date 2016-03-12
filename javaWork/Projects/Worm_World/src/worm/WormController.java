package worm;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.HashSet;
import java.util.Iterator;

import javax.swing.Timer;

import map.Map;

public class WormController implements KeyListener {
	
	public HashSet<Integer> pressedKeys = new HashSet<Integer>();
	public Worm thisWorm;
	public Map  map;
	
	public WormController(Worm w) {
		
		thisWorm = w;
		
        //Check every 20ms if there's keys pressed
        new Timer(20, new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0) {
                if(!pressedKeys.isEmpty()){
                    Iterator<Integer> i = pressedKeys.iterator();
                    while(i.hasNext()){
                    	int compare = i.next().intValue();
                    	switch(compare) {
                    		case 'w':
                    			thisWorm.changePosition(thisWorm.getPosition().getX(), thisWorm.getPosition().getY()+1);
                    			map.eatEarth(thisWorm.getPosition());
                    			break;
                    		case 's':
                    			thisWorm.changePosition(thisWorm.getPosition().getX(), thisWorm.getPosition().getY()-1);
                    			map.eatEarth(thisWorm.getPosition());
                    			break;
                    		case 'a':
                    			thisWorm.changePosition(thisWorm.getPosition().getX()-1, thisWorm.getPosition().getY());
                    			map.eatEarth(thisWorm.getPosition());
                    			break;
                    		case 'd':
                    			thisWorm.changePosition(thisWorm.getPosition().getX()+1, thisWorm.getPosition().getY()+1);
                    			map.eatEarth(thisWorm.getPosition());
                    			break;
                    	}
                    }
                }
                map.update();
            }
        }).start();
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

}
