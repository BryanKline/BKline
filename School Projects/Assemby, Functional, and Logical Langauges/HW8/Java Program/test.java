import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

public class test extends JFrame 
{
    int redCounter = 255;
    int greenCounter = 0;
    int blueCounter = 0;


    protected JButton save;
	protected JButton reset;
    protected JButton redMinus;
    protected JButton greenMinus;
    protected JButton blueMinus;
    protected JButton redPlus;
    protected JButton greenPlus;
    protected JButton bluePlus;

    protected JPanel blank1, blank2, blank3, blank4, blank5, blank6;
    protected JPanel mainPanel;
    protected JPanel listPanel;
    protected JPanel button;
    protected JPanel colorPanel;
    protected JPanel colorButtonPanel;
    protected JPanel controlButtonPanel;

	protected JTextField red;
    protected JTextField green;
	protected JTextField blue;
    protected JTextField myTitle;

    protected JLabel redLabel;
    protected JLabel greenLabel;
    protected JLabel blueLabel;

    protected Drawing drawBox;

    protected JList<String> colorList;

    String colorListData[] = {"Red", "Green", "Blue", "Yellow", "Cyan", "Magenta", "Orange", "Pink", "Grey", "Black", "White"};

	public static void main (String argv[]) 
	{
        
        
        new test("Test");


    }

    public test(String title) 
	{
        super(title);		
		//setSize(200, 500);
        setBounds(200, 200, 500, 300);

        addWindowListener(new WindowDestroyer());      

        getContentPane().setLayout(new GridLayout(1, 2, 10, 10));
        mainPanel = new JPanel(new GridLayout(2, 1, 10, 10));
        
        button = new JPanel(new GridLayout(2, 1, 10, 10));
        listPanel = new JPanel(new FlowLayout());
        colorPanel = new JPanel(new GridLayout(1, 1, 10, 10));
        colorButtonPanel = new JPanel(new GridLayout(3, 4, 10, 10));
        controlButtonPanel = new JPanel(new FlowLayout());
        blank1 = new JPanel(new GridLayout(1, 1, 10, 10));
        blank2 = new JPanel(new GridLayout(1, 1, 10, 10));


        getContentPane().add(mainPanel);
        getContentPane().add(listPanel);
        mainPanel.add(colorPanel);
        mainPanel.add(button);
        button.add(colorButtonPanel);


        button.add(controlButtonPanel);        


        
        drawBox = new Drawing();
        save = new JButton("Save");
        reset = new JButton("Reset");
        redMinus = new JButton("-");
        greenMinus = new JButton("-");
        blueMinus = new JButton("-");
        redPlus = new JButton("+");
        greenPlus = new JButton("+");
        bluePlus = new JButton("+");
        redLabel = new JLabel(" Red:");
        greenLabel = new JLabel(" Green:");
        blueLabel = new JLabel(" Blue:");
        red = new JTextField("" + redCounter); 
        green = new JTextField("" + greenCounter);
        blue = new JTextField("" + blueCounter);
        colorList = new JList<String>(); 


   
        colorList.setFixedCellWidth(200);
        colorList.setFixedCellHeight(24);
        colorPanel.add(drawBox);


        colorButtonPanel.add(redLabel);
        colorButtonPanel.add(red);
        colorButtonPanel.add(redMinus);
        colorButtonPanel.add(redPlus);
        colorButtonPanel.add(greenLabel);
        colorButtonPanel.add(green);
        colorButtonPanel.add(greenMinus);
        colorButtonPanel.add(greenPlus);
        colorButtonPanel.add(blueLabel);
        colorButtonPanel.add(blue);        
        colorButtonPanel.add(blueMinus);  
        colorButtonPanel.add(bluePlus);



        
        listPanel.add(colorList);
        colorList.setListData(colorListData);

        
        controlButtonPanel.add(blank1);
        controlButtonPanel.add(save); 
        controlButtonPanel.add(reset);
        controlButtonPanel.add(blank2);






        
        //getContentPane().setLayout(new GridBagLayout());
        //GridBagConstraints control = new GridBagConstraints();

        //control.insets = new Insets(3, 3, 3, 3);
        




        
        /*
        control.weightx = 1;
        control.weighty = 1;
        control.gridx = 1;
        control.gridy = 1;
        getContentPane().add(redLabel, control);

        control.weightx = 1;
        control.weighty = 1;
        control.gridx = 2;
        control.gridy = 1;
        getContentPane().add(red, control);

        control.weightx = 1;
        control.weighty = 1;
        control.gridx = 3;
        control.gridy = 1;
        getContentPane().add(redMinus, control);
        
        control.weightx = 1;
        control.weighty = 1;
        control.gridx = 4;
        control.gridy = 1;
        getContentPane().add(redPlus, control);


        control.weightx = 100;
        control.weighty = 10;
        control.gridx = 5;
        control.gridy = 0;
        control.gridwidth = 100;
        control.gridheight = 10;
        control.insets = new Insets(10, 10, 10, 10);
        control.fill = GridBagConstraints.HORIZONTAL;
        control.fill = GridBagConstraints.VERTICAL;
        colorList = new JList<String>();
        getContentPane().add(colorList, control);
        colorList.setListData(colorListData);*/

        
		setVisible(true);
	}


    private class Drawing extends JComponent
    {
        public void paint(Graphics box)
        {
            Dimension size = getSize();
            box.setColor(new Color(redCounter, greenCounter, blueCounter));
            box.fillRect(1, 1, size.width - 2, size.height - 2);
            repaint();
        }
    }



    private class WindowDestroyer extends WindowAdapter
    {      
		public void windowClosing(WindowEvent event)
   	    {          
            System.exit(0);
        }           
        
                                                             
    }                                                              
} 


