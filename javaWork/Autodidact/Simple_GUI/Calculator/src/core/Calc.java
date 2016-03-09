package core;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calc
{
	private JFrame mainFrame;
	private JLabel displayLabel;
	private JPanel controlPanel;
	private String bufferString = "";
	private double firstArg = 0;
	private double secondArg = 0;
	private char operator;

	public Calc()
	{
		mainFrame = new JFrame("Calculator");	
		mainFrame.setSize(500,500);
		mainFrame.setLayout(new GridLayout(2,1));
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		displayLabel = new JLabel("0");
		
		mainFrame.add(displayLabel, BorderLayout.NORTH);

		controlPanel = new JPanel();
		controlPanel.setLayout(new GridLayout(4,4));

		loadControlPanel();
		
		mainFrame.setVisible(true);
	}

	public static void main(String[] args)
	{
		Calc calc = new Calc();
	}

	public void loadControlPanel()
	{
		JButton sevenButton = new JButton("7");
		sevenButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "7";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(sevenButton);

		JButton eightButton = new JButton("8");
		eightButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "8";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(eightButton);

		JButton nineButton = new JButton("9");
		nineButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "9";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(nineButton);

		JButton divideButton = new JButton("/");
		divideButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				firstArg = Double.parseDouble(bufferString);
				bufferString = "";
				displayLabel.setText("0");
				operator = '*';
			}
		});
		mainFrame.add(divideButton);
		
		JButton fourButton = new JButton("4");
		fourButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "4";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(fourButton);

		JButton fiveButton = new JButton("5");
		fiveButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "5";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(fiveButton);

		JButton sixButton = new JButton("6");
		sixButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "6";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(sixButton);
		
		JButton multiplyButton = new JButton("*");
		multiplyButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				firstArg = Double.parseDouble(bufferString);
				bufferString = "";
				displayLabel.setText("0");
				operator = '*';
			}
		});
		mainFrame.add(multiplyButton);
		
		JButton oneButton = new JButton("1");
		oneButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "1";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(oneButton);
		
		JButton twoButton = new JButton("2");
		twoButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "2";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(twoButton);
		
		JButton threeButton = new JButton("3");
		threeButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "3";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(threeButton);

		JButton minusButton = new JButton("-");
		minusButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				firstArg = Double.parseDouble(bufferString);
				bufferString = "";
				displayLabel.setText("0");
				operator = '-';
			}
		});
		mainFrame.add(minusButton);
		
		JButton decimalButton = new JButton(".");
		decimalButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += ".";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(decimalButton);
		
		JButton zeroButton = new JButton("0");
		zeroButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				bufferString += "0";
				displayLabel.setText(bufferString);
			}
		});
		mainFrame.add(zeroButton);
	
		JButton enterButton = new JButton("Enter");
		enterButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				switch(operator)
				{
					case '+':
						secondArg = Double.parseDouble(bufferString);
						displayLabel.setText(String.valueOf(firstArg+secondArg));
						bufferString = "";
					break;
					
					case '-':
						secondArg = Double.parseDouble(bufferString);
						displayLabel.setText(String.valueOf(firstArg-secondArg));
						bufferString = "";
					break;
					
					case '*':
						secondArg = Double.parseDouble(bufferString);
						displayLabel.setText(String.valueOf(firstArg*secondArg));
						bufferString = "";
					break;
					
					case '/':
						secondArg = Double.parseDouble(bufferString);
						displayLabel.setText(String.valueOf(firstArg/secondArg));
						bufferString = "";
					break;
					
					default:
						displayLabel.setText("INVALID OPERATION");
						bufferString = "";
				}
			}
		});
		mainFrame.add(enterButton);
	}
}
